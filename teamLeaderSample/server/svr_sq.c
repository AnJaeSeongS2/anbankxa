#include <stdio.h>
#include <usrinc/atmi.h>
#include <usrinc/tmaxapi.h>

#define MAXKEYCNT 10

GET_SQ(TPSVCINFO *msg)
{
	char get_key[MAXKEYCNT][SQ_SYSKEY_SIZE+1];
	int count;

	count = get_keylist(get_key);

	sprintf(msg->data, "GET_SQ is done, count=[%d]", count);
			
	tpreturn(TPSUCCESS,0,(char *)msg->data, 0,0);
}	

int get_keylist(char get_key[MAXKEYCNT][SQ_SYSKEY_SIZE])
{
	char *sqbuf = NULL;
	SQ_KEYLIST_T sqh;
	SQ_KEYINFO_T keyinfo;
	long sqbuf_len = 0;
	int count, i, j, ret;

	if ((sqbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
		printf("sqbuf alloc failed [%s]\n", tpstrerror(tperrno));
	}

	sqh = tmax_sq_getkeylist(NULL, 0);
	if(sqh != NULL)
	{
		count = tmax_keylist_count(sqh);

		for(i=0; i<count; i++)
		{
			memset((char *)&keyinfo, 0x00, sizeof(keyinfo));
			tmax_keylist_getakey(sqh, i, &keyinfo);
			memset(get_key[i], 0x00, SQ_SYSKEY_SIZE);
			for(j=0; j< keyinfo.keylen; j++)
			get_key[i][j] = keyinfo.key[j];
			get_key[i][j] = 0;

			ret = tmax_sq_get(get_key[i], strlen(get_key[i]), (char **)&sqbuf, &sqbuf_len, 0);
			if(ret < 0)
			{
				printf("tmax_sq_get failed [%s]\n", tpstrerror(tperrno));
				tpfree(sqbuf);
				return -1;
			}
			printf("GET : [%d] Key = [%s] , Data = [%s]\n", i, get_key[i], sqbuf);
		}
		printf("\n");

		tmax_keylist_free(sqh);
	}

	return i;
}
