#ifndef _SVC_H_
	#define _SVC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/tmaxapi.h>
#include <usrinc/tx.h>
#include <usrinc/fbuf.h>

#define SQLOK       0
#define SQLDUP      1
#define SQLNOTFOUND 1403

#define MAXLEN 		50
#define NAMELEN		11


#define COMMIT          1
#define ROLLBACK        2

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


#endif
