#include <stdio.h>
#include <stdlib.h>
#include <usrinc/atmi.h>
#include <usrinc/ucs.h>
#include <usrinc/tmaxapi.h>

main(int argc, char *argv[])
{
	char *sndbuf;
	char *rcvbuf;
	long rcvlen;
	int RecvCnt = 0;
	int ret;

	
	if ((ret = tmaxreadenv("tmax.env","TMAX")) == -1) {
		printf( "tmax read env failed\n" );
		exit(1);
	}

	if ( tpstart((TPSTART_T *)NULL) == -1 ){
		printf( "tpstart failed [%s]\n",tpstrerror(tperrno));
		exit(1);
	}

	ret = tpsetunsol_flag(TPUNSOL_POLL);
	if (ret < 0)
	{
		printf("tpsetunsol_flag failed [%s]\n", tpstrerror(tperrno));
		tpend();
		exit(1);
	}

	if ((sndbuf = (char *)tpalloc("CARRAY", NULL, 1024)) == NULL){
		printf( "sndbuf tpalloc failed[%s]\n",tpstrerror(tperrno));
		tpend();
		exit(1);
	}

	if ((rcvbuf = (char *)tpalloc("CARRAY", NULL, 1024)) == NULL){
		printf( "sndbuf tpalloc failed[%s]\n",tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpend();
		exit(1);
	}


	ret = tpcall("LOGIN", (char *)sndbuf, 1024, (char **)&rcvbuf, (long *)&rcvlen, 0);
	if(ret < 0)
	{
		printf( "tpcall LOGIN failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpfree((char *)rcvbuf);
		tpend();
		exit(1);
	}
	
	printf("\n#[ Received Message from LOGINSVC : %s ]\n\n", rcvbuf);

	while(1)
	{
		ret = tpgetunsol(UNSOL_TPSENDTOCLI, (char **)&rcvbuf, (long *)&rcvlen, TPBLOCK);
		if (ret < 0)
		{
			printf("tpgetunsol failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
			tpfree((char *)sndbuf);
			tpfree((char *)rcvbuf);
			tpend();
			exit(1);
		}
			
		if(rcvlen > 0)
		{
			printf("#[ Received Message from ucs Server %d : %s ]\n", RecvCnt, rcvbuf);
			RecvCnt ++;
		}

		if (RecvCnt == 10) break;
	}

	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
}
