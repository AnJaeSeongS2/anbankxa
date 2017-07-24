#include "tbr_main.h"

int carray_db(str sndbuf, char *rcvbuf, int flag, int iud);

char   myname[100];

main(int argc, char *argv[])
{
	int    in_num;
	int    i, ret, empno, loop_cnt, ins_flag, upt_flag, del_flag;
	str    sndbuf;
	char   *rcvbuf;
	long   rcvlen;
	int    flags;

	if (argc != 6) {
		printf("Usage: %s empno loop_cnt ins_flag upt_flag del_flag\n", argv[0]);
		printf("flag : 1|0 \n");
		exit(1);
	}

	if ((ret = tmaxreadenv("tmax.env","TMAX")) == -1) {
		printf("<%-15s> tmaxreadenv fail [%s]", __FILE__, tpstrerror(tperrno));
		exit(1);
	}

	
	if ( tpstart((TPSTART_T *)NULL) == -1 ){
		printf("<%-15s> tpstart fail [%s]", __FILE__, tpstrerror(tperrno));
		exit(1);
	}

	sndbuf=(str)tpalloc("CARRAY", NULL, 4096);
	if(sndbuf==NULL) {
		printf("<%-15s> tpalloc fail [%s]", __FILE__, tpstrerror(tperrno));
		tpend();
		exit(1);
	}

	rcvbuf=(char *)tpalloc("STRING", NULL, 4096);
	if(rcvbuf==NULL) {
		printf("<%-15s> tpalloc fail [%s]", __FILE__, tpstrerror(tperrno));
		tpend();
		exit(1);
	}

	strcpy(myname, argv[0]);
	empno = atoi(argv[1]);
	loop_cnt = atoi(argv[2]);
	ins_flag = atoi(argv[3]);
	upt_flag = atoi(argv[4]);
	del_flag = atoi(argv[5]);

	sndbuf->empno = empno;
	sndbuf->sal   = V_SAL;
	strcpy(sndbuf->ename, V_ENAME);
	strcpy(sndbuf->job, V_JOB);
	strcpy(sndbuf->date, V_HIREDATE);

	for (i=1; i<=loop_cnt; i++)
	{

		printf("\n LOOP COUNT = %d \n", i);

		if (ins_flag == 1) 
		{
			flags = INSERT;
			printf(">> INSERT : COMMIT TEST \n");

			carray_db (sndbuf, rcvbuf, COMMIT, flags);
			strcpy(sndbuf->svcname, "TBRSEL");
			carray_sel(sndbuf, rcvbuf, argv[0]);
		}

		if (upt_flag == 1) 
		{
			flags = UPDATE;
			printf(">> UPDATE : COMMIT TEST \n");

			carray_db (sndbuf, rcvbuf, COMMIT, flags);
			sndbuf->empno++;
			strcpy(sndbuf->svcname, "TBRSEL");
			carray_sel(sndbuf, rcvbuf, myname);
		}

		if (del_flag == 1) 
		{
			flags = DELETE;
			printf(">> DELETE : ROLLBACK TEST \n");

			carray_db (sndbuf, rcvbuf, ROLLBACK, flags);
			strcpy(sndbuf->svcname, "TBRSEL");
			carray_sel(sndbuf, rcvbuf, myname);

			printf(">> DELETE : COMMIT TEST \n");

			carray_db (sndbuf, rcvbuf, COMMIT, flags);
			strcpy(sndbuf->svcname, "TBRSEL");
			carray_sel(sndbuf, rcvbuf, myname);
		}
	}

	tpfree((char *)sndbuf);
	tpfree((char *)rcvbuf);
	tpend();
}

int carray_db(str sndbuf, char *rcvbuf, int flag, int iud)
{
	int ret, cd;
	long rlen;	
	
	ret = tx_begin();
	if(ret < 0)
	{
		printf("<%-15s> tx_begin fail [%s]", __FILE__, tpstrerror(tperrno));
		exit(1);
	}

	if(iud == INSERT)
		strcpy(sndbuf->svcname, "TBRINS");
	else if(iud == UPDATE)
		strcpy(sndbuf->svcname, "TBRUPT");
	else if(iud == DELETE)
		strcpy(sndbuf->svcname, "TBRDEL");
	else
	{
		printf("[%s] flags must be INSERT or UPDATE or DELETE\n", myname);
		exit(1);
	}
	cd = tpcall(sndbuf->svcname, (char *)sndbuf, sizeof(struct temp_str), (char **)&rcvbuf, (long *)&rlen, 0 );
        if(cd < 0)
        {
		printf("[%s] [%s]\n", myname, rcvbuf);
                tx_rollback();
		exit(1);
        }

	printf("[%s] [%s]\n", myname, rcvbuf);

	if(flag == COMMIT)
	{
		ret = tx_commit();
	        if(ret < 0)
       		{
			printf("<%-15s> tx_commit fail [%s]", __FILE__, tpstrerror(tperrno));
                	exit(1);
        	}
	} else {
		ret = tx_rollback();
	        if(ret < 0)
       		{
			printf("<%-15s> tx_rollback fail [%s]", __FILE__, tpstrerror(tperrno));
                	exit(1);
        	}
	}

	return 0; 
}
