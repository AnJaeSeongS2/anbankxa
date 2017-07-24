#include <stdio.h>
#include <usrinc/atmi.h>


TPENQ(TPSVCINFO *msg)
{
        int             i, ret;

        printf("TPENQ service is started!\n");
        printf("INPUT : data=%s\n", msg->data);

	ret = tpenq("rq1", NULL, (char *)msg->data, 0, TPRQS);
	if (ret == -1) {
		printf("tpenq failed [%s]\n", tpstrerror(tperrno));
		tpreturn(TPFAIL, -1, NULL, 0, 0);	
	}

        tpreturn(TPSUCCESS,0,(char *)msg->data, 0,0);
}


TPDEQ(TPSVCINFO *msg)
{
        int             i, ret;
        char            *rcvbuf;
        long            rcvlen;

        printf("\nTPDEQ service is started!\n");

        if ((rcvbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
                printf("server : rcvbuf alloc failed [%s]\n", tpstrerror(tperrno));
                tpreturn(TPFAIL, -1, NULL, 0, 0);
        }

        ret = tpdeq( "rq1", NULL, (char **)&rcvbuf, (long *)&rcvlen, TPRQS );
        if (ret < 0)
        {
                printf("server : tpdeq failed [%s]\n", tpstrerror(tperrno) );
                tpfree((char *)rcvbuf);
                tpreturn(TPFAIL, -1, NULL, 0, 0);
        }

        printf("INPUT : data=%s\n", rcvbuf);

        for (i = 0; i < strlen(rcvbuf); i++)
                rcvbuf[i] = toupper(rcvbuf[i]);

        printf("OUTPUT: data=%s\n\n", rcvbuf);

        tpreturn(TPSUCCESS, 0, (char *)rcvbuf, 0, 0);
}
