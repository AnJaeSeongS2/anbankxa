#include <stdio.h>
#include <usrinc/atmi.h>
#include <usrinc/ucs.h>

#define MAX_CLI 100

int num_cli;
int client_id[MAX_CLI];
int count;

tpsvrinit(int argc, char *argv[])
{
	num_cli = 0;
	count = 0;
	
	return 0;
}

int usermain(int argc, char *argv[])
{
	int     rcode;
	int     i;
	int     ret;
	char    *sndbuf;

	printf("\nusermain start\n");

	sndbuf = (char *)tpalloc("CARRAY", NULL, 1024);
	if(sndbuf == NULL)
		printf("usermain : tpalloc is failed [%s]\n", tpstrerror(tperrno));
		

	while(1)
	{
		sleep(5);

		for (i = 0; i < num_cli; i++)
		{
			sprintf(sndbuf, "Success tpsendtocli [%d]", count++);

			ret = tpsendtocli (client_id[i], sndbuf, 1024, 0);
		}

		rcode = tpschedule(-1);
	}
}

LOGIN(TPSVCINFO *msg)
{
	char    *sndbuf;
	int     clid;
	int     ret;

	sndbuf = (char *)tpalloc("CARRAY", NULL, 1024);
	if(sndbuf == NULL)
	{
		printf("LOGINSVC : tpalloc is failed [%s]\n\n", tpstrerror(tperrno));
		tpreturn(TPFAIL, -1, NULL, 0, 0);
	}

	if (num_cli < MAX_CLI)
	{
		client_id[num_cli] = tpgetclid();
		printf("\nclient id(clid) = %d\n", client_id[num_cli]);
		num_cli++;
	}
	else
	{
		printf("LOGOUTSVC : max client is over\n\n");
		tpreturn(TPFAIL, -1, NULL, 0, 0);
	}
		
	sprintf(sndbuf, "Client Registration Success");

	tpreturn(TPSUCCESS, 0, (char *)sndbuf, 1000, 0);
}

tpsvrdone()
{

}
