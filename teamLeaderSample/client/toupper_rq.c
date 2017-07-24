#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>

main(int argc, char *argv[])
{
	char	*sndbuf, *rcvbuf;
	long	rcvlen, sndlen, revent;
	int	ret, i, cd;

	if (argc != 2) {
		printf("Usage: toupper_rq string\n");
		exit(1);
	}

	if ( (ret = tmaxreadenv( "tmax.env","TMAX" )) == -1 ){
		printf( "tmax read env failed\n" );
		exit(1);
	}

	if (tpstart((TPSTART_T *)NULL) == -1){
		printf("tpstart failed\n");
		exit(1);
	}

	if ((sndbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
		printf("sendbuf alloc failed !\n");
		tpend();
		exit(1);
	}

	if ((rcvbuf = (char *)tpalloc("STRING", NULL, 0)) == NULL) {
		printf("recvbuf alloc failed !\n");
		tpfree((char *)sndbuf);
		tpend();
		exit(1);
	}

	strcpy(sndbuf, argv[1]);

	cd = tpenq("rq1", "TOUPPER", (char *)sndbuf, 0, TPNOFLAGS );
	if (cd < 0) {
		printf("tpenq failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpfree((char *)rcvbuf);
		tpend();
		exit(1);
	}

	cd = tpdeq("rq1", "TOUPPER", &rcvbuf, &rcvlen, TPNOFLAGS );
	if (cd < 0)
	{
		printf("tpdeq failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpfree((char *)rcvbuf);
		tpend();
		exit(1);
	}

	printf("send data: %s\n", sndbuf);
	printf("recv data: %s\n", rcvbuf);

	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
}
