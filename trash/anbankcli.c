#include <stdio.h>
#include <usrinc/atmi.h>

//#include "../sdl/demo.s"
#include "../sdl/demo.s"
//#include <demo_sdl.h>

#define TEMP_PHONE "6283-2114"
#define TEMP_ADDRESS "Korea"
/* Tmax의 xa switch openinfo */
#define OPENINFO        "host=192.168.1.16:8930+dbglvl=1+timeout=10"
/* Tmax의 xa switch closeinfo */
#define CLOSEINFO       ""
const char *const BANK_ID[2] = {"anbank1","anbank2"};
extern struct xa_switch_t tmaxxaosw;
struct xa_switch_t _xasw;
int _xa_load(int xaoption)
{
        _xasw.name[0] = 0;
        _xasw = tmaxxaosw;
        if (_xasw.name[0] == 0)
            return -1;
        return 1;
}

int main(int argc, char *argv[])
{
       struct input *sndbuf;
       char *rcvbuf;
       int acnt_id1, n, timeout , acnt_money,acnt_id2=0;
	   char *bank_id1, *bank_id2=0;
       long len;
       if (argc == 1 || argc >8){
          fprintf(stderr, "Usage:%s -COMMAND_NAME\n",argv[0]);
          printf("-COMMAND_NAME : \n-c ACCOUNT_ID BANK_ID  : make new account\n-d ACCOUNT_ID BANK_ID MONEY : deposit to this account\n-w ACCOUNT_ID BANK_ID MONEY : withdrow from this account\n-s ACCOUNT_ID1 BANK_ID1 MONEY ACCOUNT_ID2 BANK_ID2 : send money of account1 to account2\n");
          exit(1);
       }
       char* commandstr;
       if(!strcmp(argv[1],"-c")) commandstr="CREATE";
       else if(!strcmp(argv[1],"-d")) commandstr="DEPOSIT";
       else if(!strcmp(argv[1],"-w")) commandstr="WITHDROW";
       else if(!strcmp(argv[1],"-s")) commandstr="SENDMONEY";
       else
       {
          printf("-COMMAND_NAME is not correct"); 
          exit(1);
       }
       printf("LET'S DO %s\n",commandstr);
	   
       
       acnt_id1 = atoi(argv[2]);
	   bank_id1 = atoi(argv[3]);
       acnt_money = 0;
       if(strcmp(argv[1], "-c")){
          acnt_money =atoi(argv[4]);
       }
       fprintf(stdout, "acnt_id1 = %d\n", acnt_id);
       fprintf(stdout, "acnt_money2 = %d\n", acnt_money);
       if(argc==7){
          acnt_id2 = atoi(argv[4]);
		  bank_id2 = atoi(argv[5]);
	      fprintf(stdout, "acnt_id1 = %d\n", acnt_id);
          fprintf(stdout, "acnt_money2 = %d\n", acnt_money);

       }
       timeout = 60;

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
       sndbuf->account_id1 = acnt_id1;
	   sndbuf->bank_id1 = bank_id1;
       sndbuf->money = acnt_money;
	   sndbuf->account_id2 = acnt_id2;
	   sndbuf->bank_id2 = bank_id2;
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
