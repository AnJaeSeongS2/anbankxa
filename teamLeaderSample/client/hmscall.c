#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/hmsapi.h>


int main(int argc, char **argv)
{
    char *sndbuf, *rcvbuf;
    long rcvlen, sndlen;
    HMS_SHND *sess;
    HMS_CHND *cons;
    hms_msg_t *msg;

    if (argc != 2) {
        printf("Usage : %s <message>\n\n", argv[0]);
        exit(1);
    }

    if (tmaxreadenv("tmax.env", "TMAX") == -1) {
        printf("error: tmaxreadenv() failed - %d\n", tperrno);
        exit(1);
    }

    if (tpstart((TPSTART_T *) NULL) == -1) {
        printf("error: tpstart() fail - %d\n", tperrno);
        exit(1);
    }

    if ((sndbuf = (char *)tpalloc("STRING", NULL, 1024)) == NULL) {
        printf("error: sendbuf alloc failed !\n");
        tpend();
        exit(1);
    }   
 
    if ((rcvbuf = (char *)tpalloc("STRING", NULL, 1024)) == NULL) {
        printf("error: recvbuf alloc failed !\n");
        tpfree((char *)sndbuf);
        tpend();
        exit(1);
    }   
 
    strcpy(sndbuf, argv[1]);

    if(tpcall("HMS", sndbuf, 0, &rcvbuf, &rcvlen, 0)==-1){
        printf("error: Can't send request to service HMS\n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpfree((char *)sndbuf);
        tpfree((char *)rcvbuf);
        tpend();
        exit(1);
    }
	
	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
    return 0;
}
