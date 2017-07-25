#include <stdio.h>
#include <usrinc/atmi.h>
#include <string.h>
#include <stdlib.h>
#include "../sdl/anbankxa.s"
const char *const BANK_ID[2] = {"anbank1","anbank2"};
int main(int argc, char *argv[])
{
       
       char *rcvbuf;
       int acnt_id1=0, n, timeout , acnt_money=0,acnt_id2=0;
	   char *bank_id1 = (char *)malloc(sizeof(char) * 10);
	   char *bank_id2 = (char *)malloc(sizeof(char) * 10);
       long len;
       char* commandstr = (char *)malloc(sizeof(char)*20);

		//Usage:./anbankxacli -COMMAND_NAME
		// ./anbankxacli                       : show help
		// ./anbankxacli -c ACCOUNT_ID BANK_ID  : make new account
		// ./anbankxacli -d ACCOUNT_ID BANK_ID MONEY : deposit to this account
		// ./anbankxacli -w ACCOUNT_ID BANK_ID MONEY : withdrow from this account
		// ./anbankxacli -s ACCOUNT_ID1 BANK_ID1 MONEY ACCOUNT_ID2 BANK_ID2 : send money of account1 to account2

       if (argc == 1 || argc >8){
          fprintf(stderr, "Usage:%s -COMMAND_NAME\n",argv[0]);
          printf("-COMMAND_NAME : \n-c ACCOUNT_ID BANK_ID  : make new account\n-d ACCOUNT_ID BANK_ID MONEY : deposit to this account\n-w ACCOUNT_ID BANK_ID MONEY : withdrow from this account\n-s ACCOUNT_ID1 BANK_ID1 MONEY ACCOUNT_ID2 BANK_ID2 : send money of account1 to account2\n");
          exit(1);
       }

	
       if(!strcmp(argv[1],"-c"))
	   {
		   strcpy(commandstr,"CREATE");
		   acnt_id1 = atoi(argv[2]);
		   strcpy(bank_id1 , argv[3]);
	   }
       else if(!strcmp(argv[1],"-d"))
	   {
		   strcpy(commandstr , "DEPOSIT");
		   acnt_id2 = atoi(argv[2]);
		   strcpy(bank_id2, argv[3]);
		   acnt_money = atoi(argv[4]);
	   }
       else if(!strcmp(argv[1],"-w"))
	   {
		   strcpy(commandstr,"WITHDRAW");
		   acnt_id1 = atoi(argv[2]);
		   strcpy( bank_id1 , argv[3]);
		   acnt_money = atoi(argv[4]);
	   }
       else if(!strcmp(argv[1],"-s") && argc==7)
	   { 
		   strcpy(commandstr , "SENDMONEY");
		   acnt_id1 = atoi(argv[2]);
		   strcpy( bank_id1 , argv[3]);
		   acnt_money = atoi(argv[4]);
		   acnt_id2 = atoi(argv[5]);
		   strcpy( bank_id2 , argv[6]);
	   }
       else
       {
          printf("-COMMAND_NAME is not correct\n"); 
          exit(1);
       }
       printf("LET'S DO %s\n",commandstr);

       
	   //transaction processing start.   
	   n = tpstart((TPSTART_T *)NULL);
       if (n < 0) {
              fprintf(stderr, "tpstart fail! tperrno = %d\n", tperrno);
              exit(1);
       }
       
       rcvbuf = (char *)tpalloc("STRING", NULL, 0);
       if (rcvbuf == NULL) {
              fprintf(stderr, "tpalloc fail: rcvbuf tperrno = %d\n", tperrno);
              tpend();
              exit(1);
       }
	   


	   //tpcall 에 넘겨줄 sndbuf생성.
	   struct input_bank2 *sndbuf2;
       sndbuf2 = (struct input_bank2 *)tpalloc("STRUCT", "input_bank2", sizeof(struct input_bank2));
       if (sndbuf2 == NULL) {
              fprintf(stderr, "tpalloc fail        : sndbuf2 tperrno = %d\n", tperrno);
              tpend();
              exit(1);
       }
	   sndbuf2->account_id1 = acnt_id1;
	   strcpy( sndbuf2->bank_id1 , bank_id1);
	   sndbuf2->money = acnt_money;
	   sndbuf2->account_id2 = acnt_id2;
	   strcpy( sndbuf2->bank_id2 , bank_id2);
	   strcpy( sndbuf2->commandstr , commandstr);

	   
	   
	   printf("before tpcall(ATMSERVICE)\n"); 
	   //tpcall 로 ATMSERVICE라는 서비스를 call함.
       n = tpcall("ATMSERVICE", (char *)sndbuf2, sizeof(struct input_bank2), 
                  (char **)&rcvbuf, (long *)&len, TPNOFLAGS);
      
	   
	   if (n < 0) {
              fprintf(stderr, "tpcall fail! tperrno = %d\n", tperrno);       
			   tpfree((char *)sndbuf2);
			   tpfree((char *)rcvbuf);
			   free(commandstr);
              tpend();
              exit(1);
       }
       printf("rtn msg = %s\n", rcvbuf);
       tpfree((char *)sndbuf2);
       tpfree((char *)rcvbuf);
	   free(commandstr);
       tpend();
}
