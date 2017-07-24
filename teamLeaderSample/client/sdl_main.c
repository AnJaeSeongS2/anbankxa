#include <stdio.h>
#include <stdlib.h>
#include <usrinc/atmi.h>
#include "../sdl/demo.s"

int print_main();
int sdl_ins();
int sdl_sel();
int sdl_upt();
int sdl_del();

main()
{
	int    in_num;
	int    ret;
	struct edu_emp *sndbuf, *rcvbuf;
	long   rcvlen;


	if ((ret = tmaxreadenv("tmax.env","TMAX")) == -1) {
		printf( "tmax read env failed\n" );
		exit(1);
	}

	in_num = print_main();	
	
	if ( in_num == 0 ){
		printf( "This Program is Over..... Bye Bye\n" );
		exit(0);
	}

	if ( tpstart((TPSTART_T *)NULL) == -1 ){
		printf( "tpstart failed[%s]\n",tpstrerror(tperrno));	
		exit(1);
	}

	if ((sndbuf = (struct edu_emp *)tpalloc("STRUCT","edu_emp",0)) == NULL){
		printf( "sndbuf tpalloc failed[%s]\n",tpstrerror(tperrno));
		tpend();
		exit(1);
	}	
	if ((rcvbuf = (struct edu_emp *)tpalloc("STRUCT","edu_emp",0)) == NULL){
		printf( "sndbuf tpalloc failed[%s]\n",tpstrerror(tperrno));
		tpfree((char *)sndbuf);
		tpend();
		exit(1);
	}	

	switch(in_num){
		case 1:
		   ret = sdl_ins(sndbuf,rcvbuf);	
		   if (ret == 0)
			printf( "\n\n******** Insert Successfully!! *********\n" );
		   else{
			printf( "\n\n********* Insert Failed!!!! ***********\n");
			printf( "********* Sqlca.SqlCode = %d *********\n",tpurcode);
		   }
		   break;
		case 2:
		   ret = sdl_sel(sndbuf,rcvbuf);	
		   if (ret == 0)
			printf( "\n\n******** Select Successfully!! *********\n" );
		   else if (ret == 100){
			printf("\n***************************************************\n");
			printf( "***   Not Registered Employee Number!!!   ***\n" );
			printf("***************************************************\n\n\n");
		   }
		   else{
			printf( "\n\n********* Select Failed!!!! ***********\n");
			printf( "********* Sqlca.SqlCode = %d *********\n",tpurcode);
		   }
		   break;
		case 3:
		   ret = sdl_upt(sndbuf, rcvbuf);	
		   if (ret == 0)
			printf( "\n\n******** Update Successfully!! *********\n" );
		   else{
			printf( "\n\n********* Update Failed!!!! ***********\n");
			printf( "********* Sqlca.SqlCode = %d *********\n",tpurcode);
		   }
		   break;
		case 4:
		   ret = sdl_del(sndbuf, rcvbuf);	
		   if (ret == 0)
			printf( "\n\n******** Delete Successfully!! *********\n" );
		   else{
			printf( "\n\n********* Delete Failed!!!! ***********\n");
			printf( "********* Sqlca.SqlCode = %d *********\n",tpurcode);
		   }
	}
	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
}

int sdl_sel(struct edu_emp *sndbuf, struct edu_emp *rcvbuf)
{
	long rlen;

	printf( "Employee Number : " ); scanf("%d", &sndbuf->empno);

	if (tpcall("SDLSEL",(char *)sndbuf, 0, (char **)&rcvbuf, &rlen, 0)==-1){
		printf( "tpcall SDLSEL failed\n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		return -1;
	}

	if (tpurcode == 1403)
		return 100;

	printf("\n***************************************************\n");
	printf( "| Selected Employee Number : %d\n", rcvbuf->empno );
	printf( "| Selected Employee Name   : %s\n", rcvbuf->ename );
	printf( "| Selected Employee Job    : %s\n", rcvbuf->job );
	printf( "| Selected Manager  Number : %d\n", rcvbuf->mgr );
	printf( "| Selected Hiredate(yymmdd): %s\n", rcvbuf->date );
	printf( "| Selected Salary          : %.2f\n", rcvbuf->sal );
	printf( "| Selected Commission      : %.2f\n", rcvbuf->comm );
	printf( "| Selected Department No   : %d\n", rcvbuf->deptno );
	printf("***************************************************\n\n");

	return 0;
}
int sdl_upt(struct edu_emp *sndbuf, struct edu_emp *rcvbuf)
{
	char sel;
	int  chk=0;
	long rlen;

	printf( "Employee Number : " ); scanf("%d", &sndbuf->empno);
	printf( "\n\n" );

	printf("***************************************************\n");
	printf( "You can change only Employee Name or Employee Job \n" ); 
	printf("***************************************************\n");
	printf( "|  Employee Name: "); scanf("%s", sndbuf->ename ); 
	printf( "|  Employee Job : "); scanf("%s", sndbuf->job ); 
	printf("***************************************************\n\n");

	if (tpcall("SDLUPT",(char *)sndbuf,0,(char **)&rcvbuf,&rlen,0)==-1){
		printf( "tpcall SDLUDT failed\n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		return -1;
	}

	return 0;	
}
int sdl_del(struct edu_emp *sndbuf, struct edu_emp *rcvbuf)
{
	long rlen;

	printf( "Employee Number : " ); scanf("%d", &sndbuf->empno);

	if (tpcall("SDLDEL",(char *)sndbuf, 0, (char **)&rcvbuf, &rlen, 0)==-1){
		printf( "tpcall SDLDEL failed\n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		return -1;
	}
	
	return 0;
}
int sdl_ins(struct edu_emp *sndbuf, struct edu_emp *rcvbuf)
{
	int ret;
	long rlen;	
	printf("\n******************************************\n");
	printf( "|  Employee Number : " ); scanf ( "%d", &sndbuf->empno );
	printf( "|  Employee Name   : " ); scanf ( "%s", sndbuf->ename );
	printf( "|  Employee Job    : " ); scanf ( "%s", sndbuf->job );
	printf( "|  Manager  Number : " ); scanf ( "%d", &sndbuf->mgr );
	printf( "|  Hiredate(yymmdd): " ); scanf ( "%s", sndbuf->date);
	printf( "|  Salary          : " ); scanf ( "%f", &sndbuf->sal );
	printf( "|  Commission      : " ); scanf ( "%f", &sndbuf->comm );
	printf( "|  Department No   : " ); scanf ( "%d", &sndbuf->deptno );
	printf("******************************************\n\n");

	if (tpcall("SDLINS", (char *)sndbuf,0, (char **)&rcvbuf, &rlen, 0 ) == -1){
		printf( "tpcall SDLINS failed\n[tperrno(%d) : %s]\n", tperrno,tpstrerror(tperrno));
		return -1;
	}

	return 0; 
}
int print_main()
{
	int in_num;

	printf( "********************************************\n");
	printf( "**         Selection Menu List            **\n");
	printf( "********************************************\n");
	printf( "**                                        **\n");
	printf( "**              0. Exit                   **\n");
	printf( "**              1. Insert                 **\n");
	printf( "**              2. Select                 **\n");
	printf( "**              3. Update                 **\n");
	printf( "**              4. Delete                 **\n");
	printf( "**                                        **\n");
	printf( "********************************************\n\n\n");
	printf( "Select Menu Number[0-4] : ");
	scanf("%d",&in_num);

	return in_num;	
}
