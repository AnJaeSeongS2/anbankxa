
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
