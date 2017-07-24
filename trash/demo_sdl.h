
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
