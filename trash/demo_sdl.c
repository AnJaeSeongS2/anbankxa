
#ifndef ORA_PROC

#include <netinet/in.h>

#include <arpa/inet.h>

#endif

#include "/home/anu/o7/tmax/usrinc/sdl.h"


extern  char *sdl_encode_input(char *dp1, char *dp2); 
extern  char *sdl_decode_input(char *dp1, char *dp2); 


struct input {
int account_id		/* null = 0 */;
int money		/* null = 0 */;
};

int _sdl_table_size2 = 1; 

struct _sdl_struct_s _sdl_table2[] = { 
	{"input", sdl_encode_input, sdl_decode_input, 0, 1, 2, sizeof(struct input), 8},
	{""} 
};
 

int _sdl_field_table_size2 = 2; 

struct _sdl_field_s _sdl_field_table2[] = { 
	{"account_id", 0, 3, "0", -1, 1, 1, 0, 0},
	{"money", 0, 3, "0", -1, 1, 1, 4, 4},
	{""} 
};
 

 
char *
sdl_encode_input(char *dp1, char *dp2) 
{
	struct input *dp; 
	int       i; 
	long      offset; 
	char      *cp; 
	sdl_short *sp; 
	sdl_int   *ip; 
	sdl_long  *lp, *lp2; 

	if (dp2 == NULL) { 
	   dp2 = (char *) malloc(8);
	   if (dp2 == NULL) 
	      return NULL;  
	} 
	dp = (struct input *) dp1; 
	ip = (sdl_int *) (dp2 + 0); 
	*ip = htonl(dp->account_id);
	ip = (sdl_int *) (dp2 + 4); 
	*ip = htonl(dp->money);

	return dp2; 
}

 
char *
sdl_decode_input(char *dp1, char *dp2) 
{
	struct input *dp; 
	int       i; 
	long      offset; 
	char      *cp; 
	sdl_short *sp; 
	sdl_int   *ip; 
	sdl_long  *lp, *lp2; 

	if (dp2 == NULL) { 
	   dp2 = (char *) malloc(sizeof(struct input));
	   if (dp2 == NULL) 
	      return NULL;  
	} 
	dp = (struct input *) dp2; 
	ip = (sdl_int *) (dp1 + 0); 
	dp->account_id = ntohl(*ip);
	ip = (sdl_int *) (dp1 + 4); 
	dp->money = ntohl(*ip);

	return dp2; 
}
