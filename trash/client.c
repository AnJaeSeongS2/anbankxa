#include <stdio.h>
#include <usrinc/atmi.h>

//#include "../sdl/demo.s"
#include "demo.s"
//#include <demo_sdl.h>

#define TEMP_PHONE "6283-2114"
#define TEMP_ADDRESS "Korea"

int main(int argc, char *argv[])
{
       struct input *sndbuf;
       char *rcvbuf;
       int acnt_id, n, timeout , acnt_money;
       long len;
       if (argc == 1 || argc >5){
          fprintf(stderr, "Usage:%s -COMMAND_NAME\n",argv[0]);
          printf("-COMMAND_NAME : \n-c ACCOUNT_ID   : make new account\n-d ACCOUNT_ID MONEY : deposit to this account\n-w ACCOUNT_ID MONEY : withdrow from this account");
          exit(1);
       }
       if (argc == 3) {
             if( argc[1] !="-c"){
                printf("-COMMAND_NAME : \n-c ACCOUNT_ID   : make new account\n-d ACCOUNT_ID MONEY : deposit to this account\n-w ACCOUNT_ID MONEY : withdrow from this account");
                exit(1);
            }
       }
       char *commandstr;
       if(argv[1] =="-c") commandstr="CREATE";
       else if(argv[1] =="-d") commandstr="DEPOSIT";
       else if(argv[1] =="-w") commandstr="WITHDROW";
       else
       {
          printf("-COMMAND_NAME is not correct"); 
          exit(1);
       }

       acnt_id = atoi(argv[2]);
       acnt_money = 0;
       if( argv[1] != "-c"){
          acnt_money =atoi(argv[3]);
       }
       fprintf(stderr, "acnt_id = %d\n", acnt_id);
       fprintf(stderr, "acnt_money = %d\n", acnt_money);
       timeout = 5;

/*
       n = tmaxreadenv("tmax.env", "tmax");
       if (n < 0) {
              fprintf(stderr, "tmaxreadenv fail! tperrno = %d\n", tperrno);
              exit(1);
       }
*/
       n = tpstart((TPSTART_T *)NULL);
       if (n < 0) {
              fprintf(stderr, "tpstart fail! tperrno = %s\n", tperrno);
              exit(1);
      }
       sndbuf = (struct input *)tpalloc("STRUCT", "input", sizeof(struct input));
       if (sndbuf == NULL) {
              fprintf(stderr, "tpalloc fail: sndbuf tperrno = %d\n", tperrno);
              tpend();
              exit(1);
       }

       rcvbuf = (char *)tpalloc("STRING", NULL, 0);
       if (rcvbuf == NULL) {
              fprintf(stderr, "tpalloc fail: rcvbuf tperrno = %d\n", tperrno);
              tpend();
              exit(1);
       }
       sndbuf->account_id = acnt_id;
       sndbuf->money = acnt_money;
       tx_set_transaction_timeout(timeout);
       n = tx_begin();
       if (n < 0)
              fprintf(stderr, "tx begin fail! tperrno = %d\n", tperrno);
      
       n = tpcall(commandstr, (char *)sndbuf, sizeof(struct input), 
                  (char **)&rcvbuf, (long *)&len, TPNOFLAGS);
       if (n < 0) {
              fprintf(stderr, "tpcall fail! tperrno = %d\n", tperrno);       
              tpend();
              exit(1);
       }

       n = tx_commit();
       if (n < 0) {
              fprintf(stderr, "tx commit fail! tx error = %d \n", n);
              tx_rollback();
              tpend();
              exit(1);
       }
       printf("rtn msg = %s\n", rcvbuf);
       tpfree((char *)sndbuf);
       tpfree((char *)rcvbuf);
       tpend();
}
