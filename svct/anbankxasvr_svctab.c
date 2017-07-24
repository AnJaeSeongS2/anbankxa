
#include 	<usrinc/atmi.h>

#include 	<usrinc/svct.h>

#if defined (__cplusplus)
extern "C" {
#endif

int _tmax_cob_main(int argc, char *argv[]);
int _tmax_main(int argc, char *argv[]);

#if defined(_CBL_MODULE)
/* COBOL function declaration */
extern int ATMSERVICE(void);
extern int CREATE(void);
extern int DEPOSIT(void);
extern int WITHDROW(void);
extern int SENDMONEY(void);
#else
/* C/C++ function declaration */
extern void ATMSERVICE(TPSVCINFO *);
extern void CREATE(TPSVCINFO *);
extern void DEPOSIT(TPSVCINFO *);
extern void WITHDROW(TPSVCINFO *);
extern void SENDMONEY(TPSVCINFO *);
#endif

#if defined (__cplusplus)
}
#endif


_svc_t _svc_tab[] = {
	{"ATMSERVICE", ATMSERVICE, 0, -1, -1},
	{"CREATE", CREATE, 0, -1, -1},
	{"DEPOSIT", DEPOSIT, 0, -1, -1},
	{"WITHDROW", WITHDROW, 0, -1, -1},
	{"SENDMONEY", SENDMONEY, 0, -1, -1}};

int _svc_tab_size = 5;

int
main(int argc, char *argv[])
{
#if defined(_CBL_MODULE)
	return _tmax_cob_main(argc, argv);
#else
	return _tmax_main(argc, argv);
#endif
}

