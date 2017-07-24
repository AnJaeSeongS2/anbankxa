#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/hmsapi.h>


int main(int argc, char **argv)
{
    char *rcvbuf;
    long rcvlen;
    HMS_SHND *sess;
    HMS_CHND *cons;
    hms_msg_t *msg;

    if (argc != 1) {
        printf("Usage : %s \n\n", argv[0]);
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

 
    if ((rcvbuf = (char *)tpalloc("STRING", NULL, 2048)) == NULL) {
        printf("error: recvbuf alloc failed !\n");
        tpfree((char *)rcvbuf);
        tpend();
        exit(1);
    }   
 
      /* RECV MESSAGE FROM HMS */
     if ((sess = hms_create_session("hms01", 0, HMS_AUTO_ACK, 0)) == NULL) {
        printf("error: hms_create_session() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpend();
        exit(1);
    }

    if ((cons = hms_create_receiver(sess, "queue01", "cons01", NULL, NULL, 0)) == NULL) {
        printf("error: hms_create_receiver() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpend();
        exit(1);
    }
	
    /* ALLOCATION */
    if ((msg = hms_alloc(sess, 2048)) == NULL) {
        printf("error: hms_alloc() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpend();
        exit(1);
    }

    /* RECV MESSAGE */
    if (hms_recvex(cons, &msg, 5, 0) == -1) {
        printf("error: hms_recvex() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        hms_free(msg);
        tpend();
        exit(1);
    }
	
    rcvlen =2048;

    /* GET BODY */
    if (hms_get_body(msg, rcvbuf, &rcvlen) == -1) {
        printf("error: hms_get_body() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        hms_free(msg);
        tpend();
        exit(1);
    }

    printf("HMS MESSAGE : %s\n", rcvbuf);

    /* CLOSE RECEIVER */
    if (hms_close_receiver(cons, 0) == -1) {
        printf("error: hms_close_receiver() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        hms_free(msg);
        tpend();
        exit(1);
    }
    
    /* CLOSE SESSION */
    if (hms_close_session(sess, 0) == -1) {
        printf("error: hms_close_session() failed \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        hms_free(msg);
        tpend();
        exit(1);
    }

    hms_free(msg);
    tpend();

    return 0;
}
