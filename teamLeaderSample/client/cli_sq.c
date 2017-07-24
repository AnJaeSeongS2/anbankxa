#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/tmaxapi.h>

#define KEYCOUNT	3

int get_keylist(char [KEYCOUNT][SQ_SYSKEY_SIZE+1]);

int
main(int argc, char *argv[])
{
	char *sqbuf, *sndbuf, sqbuf_org[1024];
	char put_key[KEYCOUNT][SQ_SYSKEY_SIZE+1];
	char get_key[KEYCOUNT][SQ_SYSKEY_SIZE+1];
	long sqbuf_len = 0, rlen, flags;
	int ret, i, len=0, sys_flag=0;
	char key[SQ_SYSKEY_SIZE+1];

	if ( (ret = tmaxreadenv( "tmax.env","TMAX" )) == -1 ){
		printf( "tmax read env failed[%s]\n", tpstrerror(tperrno) );
		return -1;
	}

	if (tpstart((TPSTART_T *)NULL) == -1){
		printf("tpstart failed [%s]\n", tpstrerror(tperrno));
		return -1;
	}

	if ((sqbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
		printf("sqbuf alloc failed [%s]\n", tpstrerror(tperrno));
		tpend();
		return -1;
	}

	if ((sndbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
		printf("sndbuf alloc failed [%s]\n", tpstrerror(tperrno));
		tpend();
		return -1;
	}

	if (argc != 3)
	{
		printf("Usage : %s Key Data\n", argv[0]);
		printf("         Key    : \"SYSTEM\" or Specific Key Value\n");
		exit(1);
	}

	strcpy(key, argv[1]);
	strcpy(sqbuf_org, argv[2]);
		 
	flags = 0L;
	if(!strcmp(key, "SYSTEM"))
	{
		flags |= TPSQ_SYSKEY;
		flags |= TPSQ_KEYGEN;
		len = SQ_SYSKEY_SIZE;
		sys_flag = 1;
	}
	else
	{
		strcpy(put_key[0], key);
		len = strlen(key);
	}

	flags |= TPSQ_UPDATE;

	for(i=0; i<KEYCOUNT; i++)
	{
		if( !sys_flag )
		{
			memset(put_key[i], 0x00, SQ_SYSKEY_SIZE+1);
			sprintf(put_key[i], "%s%d", key, i);
		}
		memset(sqbuf, 0x00, 1024);
		sprintf(sqbuf, "%s%d", sqbuf_org, i);
		ret = tmax_sq_put(put_key[i], len+1, sqbuf, strlen(sqbuf), flags);
		if(ret < 0)
		{
			printf("tmax_sq_put error, key = %s [%s]\n", put_key[i], tpstrerror(tperrno));
			tpfree(sqbuf);
			tpend();
			exit(1);
		}
		printf("PUT : [%d] Key = [%s] , Data = [%s]\n", i, put_key[i], sqbuf);
	}
	printf("\n");

	ret = tpcall("GET_SQ", (char *)sndbuf, 0, (char **)&sndbuf, &rlen, TPNOFLAGS);
	if(ret < 0)
	{
		printf("tpcall failed [%s]\n", tpstrerror(tperrno));

                tpfree((char *)sndbuf);
                tpfree((char *)sqbuf);
                tpend();
                exit(1);
        }
        printf("recv data: %s\n", sndbuf);

	tpfree((char *)sqbuf);
	tpfree((char *)sndbuf);
	tpend();
	return 0;
}