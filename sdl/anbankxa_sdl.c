
#ifndef ORA_PROC

#include <netinet/in.h>

#include <arpa/inet.h>

#endif

#include "/home/anu/o7/tmax/usrinc/sdl.h"


extern  char *sdl_encode_input_bank2(char *dp1, char *dp2); 
extern  char *sdl_decode_input_bank2(char *dp1, char *dp2); 


struct input_bank2 {
char bank_id1[10]		/* null = '\0' */;
int account_id1		/* null = 0 */;
long money		/* null = 0 */;
char bank_id2[10]		/* null = '\0' */;
int account_id2		/* null = 0 */;
char commandstr[20]		/* null = '\0' */;
};

int _sdl_table_size2 = 1; 

struct _sdl_struct_s _sdl_table2[] = { 
	{"input_bank2", sdl_encode_input_bank2, sdl_decode_input_bank2, 0, 5, 6, sizeof(struct input_bank2), 56},
	{""} 
};
 

int _sdl_field_table_size2 = 6; 

struct _sdl_field_s _sdl_field_table2[] = { 
	{"bank_id1", 0, 1, "", -1, 10, 10, 0, 0},
	{"account_id1", 0, 3, "0", -1, 1, 1, 12, 12},
	{"money", 0, 4, "0", -1, 1, 1, 16, 16},
	{"bank_id2", 0, 1, "", -1, 10, 10, 24, 20},
	{"account_id2", 0, 3, "0", -1, 1, 1, 36, 32},
	{"commandstr", 0, 1, "", -1, 20, 20, 40, 36},
	{""} 
};
 

 
char *
sdl_encode_input_bank2(char *dp1, char *dp2) 
{
	struct input_bank2 *dp; 
	int       i; 
	long      offset; 
	char      *cp; 
	sdl_short *sp; 
	sdl_int   *ip; 
	sdl_long  *lp, *lp2; 

	if (dp2 == NULL) { 
	   dp2 = (char *) malloc(56);
	   if (dp2 == NULL) 
	      return NULL;  
	} 
	dp = (struct input_bank2 *) dp1; 
	cp = (char *) (dp2 + 0); 
	memcpy(cp, dp->bank_id1, 10);
	ip = (sdl_int *) (dp2 + 12); 
	*ip = htonl(dp->account_id1);
	lp = (sdl_long *) (dp2 + 16); 
	*lp = htonl(dp->money);
	cp = (char *) (dp2 + 20); 
	memcpy(cp, dp->bank_id2, 10);
	ip = (sdl_int *) (dp2 + 32); 
	*ip = htonl(dp->account_id2);
	cp = (char *) (dp2 + 36); 
	memcpy(cp, dp->commandstr, 20);

	return dp2; 
}

 
char *
sdl_decode_input_bank2(char *dp1, char *dp2) 
{
	struct input_bank2 *dp; 
	int       i; 
	long      offset; 
	char      *cp; 
	sdl_short *sp; 
	sdl_int   *ip; 
	sdl_long  *lp, *lp2; 

	if (dp2 == NULL) { 
	   dp2 = (char *) malloc(sizeof(struct input_bank2));
	   if (dp2 == NULL) 
	      return NULL;  
	} 
	dp = (struct input_bank2 *) dp2; 
	cp = (char *) (dp1 + 0); 
	memcpy(dp->bank_id1, cp, 10);
	ip = (sdl_int *) (dp1 + 12); 
	dp->account_id1 = ntohl(*ip);
	lp = (sdl_long *) (dp1 + 16); 
	dp->money = ntohl(*lp);
	cp = (char *) (dp1 + 20); 
	memcpy(dp->bank_id2, cp, 10);
	ip = (sdl_int *) (dp1 + 32); 
	dp->account_id2 = ntohl(*ip);
	cp = (char *) (dp1 + 36); 
	memcpy(dp->commandstr, cp, 20);

	return dp2; 
}
