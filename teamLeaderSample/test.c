#include<stdio.h>
#include<stdlib.h>
const char *const BANKNAMES[2] = {"anbank1","anbank2"};


struct input1
{
	int a;
	int b;
};

struct input2
{
	int a;
	int b;
	int c;
	int d;
};

void main(){
    //BANKNAMES[1] = "adfa";
    for( int i = 0 ; i < sizeof(BANKNAMES)/sizeof(const char* const) ; i++){
    fprintf(stdout,"bankname %s\n",BANKNAMES[i]);

    }

	struct void *str;
	if(1==1)
	{
		struct input1 *data1;
		data1->a = 1;
		data1->b = 1;
		str = data1;
		fprintf(stdout,"a = %s\n",&data1);
		fprintf(stdout,"a = %s\n",(*&str)->a);
	}
	
		//fprintf(stdout,"a = %s\n",str->a);

}
