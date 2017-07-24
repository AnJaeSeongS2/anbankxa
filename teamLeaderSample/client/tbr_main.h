#ifndef _CLI_H_
	#define _CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/tx.h>
#include <usrinc/tmaxapi.h>

#define SQLOK       0
#define SQLDUP      1
#define SQLNOTFOUND 1403

#define MAXLEN 		50
#define NAMELEN		11


#define COMMIT          1
#define ROLLBACK        2


#define V_EMPNO		1000
#define V_ENAME		"tmaxqmc"
#define V_JOB		"tmaxqmc"
#define V_SAL		10
#define V_HIREDATE	"051119"

/* flags */
#define INSERT		1
#define UPDATE		2
#define DELETE		3
#define SELECT		4

struct temp_str{
	int   empno;
	char  ename[MAXLEN];
	char  job[MAXLEN];
	char  date[MAXLEN];
	float sal;
	int   commit_yn; /* 1:tx_commit, other except 1 : tx_rollback */
	char  svcname[XATMI_SERVICE_NAME_LENGTH];
};
typedef struct temp_str *str;

void print_input(str sndbuf);
void print_output(char *rcvbuf);

int carray_sel(str sndbuf, char *rcvbuf, char *myname);

void print_input(str sndbuf)
{
	printf("sndbuf->empno = [%d]\n", sndbuf->empno);
	printf("sndbuf->sal = [%d]\n", sndbuf->sal);    
	printf("sndbuf->ename = [%s]\n", sndbuf->ename);
	printf("sndbuf->job = [%s]\n", sndbuf->job);    
	printf("sndbuf->date = [%s]\n", sndbuf->date);
	printf("sndbuf->svcname = [%s]\n", sndbuf->svcname);
}

void print_output(char *rcvbuf)
{
	printf("rcvbuf=[%s]\n", rcvbuf);
}

int carray_sel(str sndbuf, char *rcvbuf, char *myname)
{
	int ret, cd;
	long rlen;

	cd = tpcall(sndbuf->svcname, (char *)sndbuf, sizeof(struct temp_str), (char **)&rcvbuf, (long *)&rlen, 0 );
	if(cd < 0)
	{
		printf("[%s] tpcall %s is failed [%s]\n", myname, sndbuf->svcname, rcvbuf);
		tx_rollback();
		exit(1);
	}

	printf("[%s] [%s]\n", myname, rcvbuf);

	return 0; 
}

#endif
