#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>
#include "../sdl/demo.s"

main(int argc, char *argv[])
{
	struct	kstrdata *sndbuf, *rcvbuf;
	long	rcvlen, sndlen;
	int	ret;

	if (argc != 2){
		printf("Usage: sdltolower string\n");
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

	if ((sndbuf=(struct kstrdata *)tpalloc("STRUCT", "kstrdata",0))==NULL){
		printf("sendbuf alloc failed !\n");
		tpend();
		exit(1);
	}

	if ((rcvbuf=(struct kstrdata *)tpalloc("STRUCT","kstrdata",0))==NULL){
		printf("recvbuf alloc failed !\n");
		tpfree((char *)sndbuf);
		tpend();
		exit(1);
	}

	sndbuf->len = strlen(argv[1]);
	strcpy(sndbuf->sdata, argv[1]);

	if (tpcall("SDLTOLOWER", (char *)sndbuf, 0, (char **)&rcvbuf, &rcvlen, 0) == -1){
		printf("Can't send request to service SDLTOLOWER \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpfree((char *)rcvbuf);
		tpend();
		exit(1);
	}

	printf("send data: %s\n", sndbuf->sdata);
	printf("recv data: %s\n", rcvbuf->sdata);

	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
}
