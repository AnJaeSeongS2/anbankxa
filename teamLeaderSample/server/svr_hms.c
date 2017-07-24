#include <stdio.h>
#include <stdlib.h>
#include <usrinc/atmi.h>
#include <usrinc/hmsapi.h>


HMS_SHND *sess = NULL;
HMS_PHND *prod = NULL;

int
tpsvrinit(int argc, char **argv)
{
    while(1) {
        sess = hms_create_session("hms01", 0, HMS_AUTO_ACK, 0);
        if (sess != NULL) {
            break;
        }
        if (tperrno != TPENOREADY) {
            printf("hms_create_session(hms01) : FAIL \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
            return -1;
        }
    }

    prod = hms_create_sender(sess, "queue01", "prod_svc", 0);
    if (prod == NULL) {
        printf("hms_create_sender() : FAIL \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        return -1;
    }

    return 1;
}

int
tpsvrdone()
{
    if (hms_close_sender(prod, 0) < 0) {
        printf("hms_close_sender : FAIL \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        return -1;
    }
    
    if (hms_close_session(sess, 0) < 0)
        printf("hms_close_session() : FAIL \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));

    return 1;
}

HMS(TPSVCINFO *msg)
{
    int n, i;
    hms_msg_t *hmsmsg = NULL;
    char *data = msg->data;
    int  len = msg->len, asize;

    printf("HMS service is started!\n");
   
    /* TOUPPER */
    for (i = 0; i < len; i++)
        data[i] = toupper(data[i]);

    /* ALLOCATION */
    asize = len +1024;
    hmsmsg = hms_alloc(sess, asize);
    if (hmsmsg == NULL) {
        printf("hms_alloc : fail \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, NULL, 0, 0);
    }
    
    /* SET BODY */
    n = hms_set_body(hmsmsg, data, len);
    if (n < 0) {
        hms_free(hmsmsg);
        printf("hms_set_body : fail \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, NULL, 0, 0);
    }
    
    /* SEND : hms01, non_persistent */
    n = hms_sendex(prod, hmsmsg, HMS_DLV_NON_PERSISTENT, 0, 0, 0);
    if (n < 0) {
        hms_free(hmsmsg);
        printf("hms_sendex(prod) : fail \n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, NULL, 0, 0);
    }

    /* FREE */
    hms_free(hmsmsg);
	tpreturn(TPSUCCESS, 0,(char*)msg->data, msg->len, 0);
}
