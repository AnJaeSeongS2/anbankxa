
#ifndef ORA_PROC

#include <netinet/in.h>

#include <arpa/inet.h>

#endif

#include "sdl.h"


extern  char *sdl_encode_kstrdata(char *dp1, char *dp2); 
extern  char *sdl_decode_kstrdata(char *dp1, char *dp2); 

extern  char *sdl_encode_input(char *dp1, char *dp2); 
extern  char *sdl_decode_input(char *dp1, char *dp2); 

extern  char *sdl_encode_input1(char *dp1, char *dp2); 
extern  char *sdl_decode_input1(char *dp1, char *dp2); 

extern  char *sdl_encode_test(char *dp1, char *dp2); 
extern  char *sdl_decode_test(char *dp1, char *dp2); 

extern  char *sdl_encode_sdlsel(char *dp1, char *dp2); 
extern  char *sdl_decode_sdlsel(char *dp1, char *dp2); 

extern  char *sdl_encode_info_3(char *dp1, char *dp2); 
extern  char *sdl_decode_info_3(char *dp1, char *dp2); 

extern  char *sdl_encode_edu_emp(char *dp1, char *dp2); 
extern  char *sdl_decode_edu_emp(char *dp1, char *dp2); 

extern  char *sdl_encode_echo_s(char *dp1, char *dp2); 
extern  char *sdl_decode_echo_s(char *dp1, char *dp2); 

extern  char *sdl_encode_rqsvc(char *dp1, char *dp2); 
extern  char *sdl_decode_rqsvc(char *dp1, char *dp2); 

extern  char *sdl_encode_emp(char *dp1, char *dp2); 
extern  char *sdl_decode_emp(char *dp1, char *dp2); 


struct kstrdata {
int len		/* null = 0 */;
char sdata[20]		/* null = '\0' */;
};


struct input {
long inacnt_id		/* null = 0 */;
};


struct input1 {
long inacnt_id		/* null = 0 */;
char address[61]		/* null = '\0' */;
};


struct test {
char kor_echo[20]		/* null = '\0' */;
char upper[20]		/* null = '\0' */;
};


struct sdlsel {
long account_id		/* null = 0 */;
long branch_id		/* null = 0 */;
char ssn[14]		/* null = '\0' */;
long balance		/* null = 0 */;
char acct_type[2]		/* null = '\0' */;
char last_name[21]		/* null = '\0' */;
char first_name[21]		/* null = '\0' */;
char mid_init[2]		/* null = '\0' */;
char phone[15]		/* null = '\0' */;
char address[61]		/* null = '\0' */;
};


struct info_3 {
long customer_num		/* null = 0 */;
char lname[15]		/* null = '\0' */;
char zipcode[5]		/* null = '\0' */;
};


struct edu_emp {
int empno		/* null = 0 */;
char ename[11]		/* null = '\0' */;
char job[10]		/* null = '\0' */;
int mgr		/* null = 0 */;
char date[9]		/* null = '\0' */;
float sal		/* null = 0.000000 */;
float comm		/* null = 0.000000 */;
int deptno		/* null = 0 */;
};


struct echo_s {
char charval		/* null = '\0' */;
short shortval		/* null = 0 */;
int intval		/* null = 0 */;
float floatval		/* null = 0.000000 */;
double doubleval		/* null = 0.000000 */;
char stringval[19]		/* null = '\0' */;
};


struct rqsvc {
char svc[20]		/* null = '\0' */;
char data[20]		/* null = '\0' */;
};


struct emp {
int type		/* null = 0 */;
int empno		/* null = 0 */;
};
