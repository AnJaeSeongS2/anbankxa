#include <stdio.h>
#include <usrinc/atmi.h>

TOUPPER_CONV(TPSVCINFO *msg)
{
	int             i, ret;
	long		rcvlen, revent;

	printf("TOUPPER service is started!\n");
	printf("INPUT : data=%s\n", msg->data);

	while (1) {
		ret = tprecv(msg->cd, (char **)&(msg->data), &rcvlen, TPNOTIME, &revent);
		if (ret < 0 && revent != TPEV_SENDONLY) {
			printf("svr : tprecv fail, error = [%s], revent = 0x%08x\n", tpstrerror(tperrno), revent);
			tpreturn(TPFAIL, -1, NULL, 0, 0);
		}

		if (revent == TPEV_SENDONLY) break;
	}

	for (i = 0; i < msg->len; i++)
		msg->data[i] = toupper(msg->data[i]);

	printf("OUTPUT: data=%s\n", msg->data);

	tpreturn(TPSUCCESS, 0, (char *)msg->data, 0, 0);
}
