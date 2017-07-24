#ifndef _TBPC_COMMON_SRC_GEN
#define _TBPC_COMMON_SRC_GEN



#define TBSQLCODE_NOTFOUND 1403



/*
==========================================
        host variable type
==========================================
*/

typedef enum esql_hostvar_type_e {

    /* string */
    ESQL_TYPE_CHARP = 0,        /* (signed) char* */
    ESQL_TYPE_UCHARP,           /* unsigned char* */
    ESQL_TYPE_CHAR_ARRAY,       /* (signed) char[n] */
    ESQL_TYPE_UCHAR_ARRAY,      /* unsigned char[n] */

    /* char */
    ESQL_TYPE_CHAR,             /* (signed) char */
    ESQL_TYPE_UCHAR,            /* unsigned char */

    /* int */
    ESQL_TYPE_INT,              /* (signed) int */
    ESQL_TYPE_UINT,             /* unsigned int */

    /* short */
    ESQL_TYPE_SHORT,            /* (signed) short (int) */
    ESQL_TYPE_USHORT,           /* unsigned short */

    /* long */
    ESQL_TYPE_LONG,             /* (signed) long (int) */
    ESQL_TYPE_ULONG,            /* unsigned long (int) */

    /* float/double */
    ESQL_TYPE_FLOAT,            /* float */
    ESQL_TYPE_DOUBLE,           /* double */

    /* VARCHAR */
    ESQL_TYPE_VARCHAR,          /* VARCHAR[n] */
    ESQL_TYPE_VARCHARP,         /* VARCHAR* */

    /* EXTERNAL DATATYPE */
    ESQL_TYPE_VARRAW,           /* VARRAW */
    ESQL_TYPE_LONG_VARRAW,      /* LONG VARRAW */

    /* EXTENED DATATYPE */
    ESQL_TYPE_NCHAR_ARRAY,      /* NCHAR */

    /* LOB */
    ESQL_TYPE_CLOB,             /* CLOB */
    ESQL_TYPE_BLOB,             /* BLOB */
    ESQL_TYPE_BFILE,            /* BFILE */

    /* COBOL COMP3 */
    ESQL_TYPE_CBL_COMP3,        /* COBOL COMP3 */
    ESQL_TYPE_EXT_VARCHAR,      /* external datatype */

    /* CURSOR */
    ESQL_TYPE_CURSOR,           /* SQL_CURSOR */

    ESQL_HVTYPE_EXT_NUMBER          = 30,
    ESQL_HVTYPE_EXT_VARNUM          = 31,
    ESQL_HVTYPE_EXT_INTEGER         = 32,
    ESQL_HVTYPE_EXT_FLOAT           = 33,
    ESQL_HVTYPE_EXT_LONG            = 34,
    ESQL_HVTYPE_EXT_UNSIGNED        = 35,
    ESQL_HVTYPE_EXT_CHAR            = 36,
    ESQL_HVTYPE_EXT_CHARZ           = 37,
    ESQL_HVTYPE_EXT_CHARF           = 38,
    ESQL_HVTYPE_EXT_STRING          = 39,
    ESQL_HVTYPE_EXT_VARCHAR         = 40,
    ESQL_HVTYPE_EXT_VARCHAR2        = 41,
    ESQL_HVTYPE_EXT_LONG_VARCHAR    = 42,
    ESQL_HVTYPE_EXT_VARRAW          = 43,
    ESQL_HVTYPE_EXT_LONG_VARRAW     = 44,
    ESQL_HVTYPE_EXT_RAW             = 45,
    ESQL_HVTYPE_EXT_ROWID           = 46,
    ESQL_HVTYPE_EXT_LONG_RAW        = 47 
} esql_hostvar_type_t;



/*
==========================================
       ESQL type 
==========================================
*/

typedef enum esql_type_t {
    /* CONNECT */
    ESQL_TYPE_CONNECT = 1,

    /* DML */
    ESQL_TYPE_SELECT,
    ESQL_TYPE_EXECUTE_DML,

    /* cursor */
    ESQL_TYPE_OPEN_CURSOR,
    ESQL_TYPE_CLOSE_CURSOR,
    ESQL_TYPE_FETCH,

    ESQL_TYPE_COMMIT,
    ESQL_TYPE_COMMIT_RELEASE,
    ESQL_TYPE_ROLLBACK,
    ESQL_TYPE_ROLLBACK_RELEASE,
    ESQL_TYPE_ROLLBACK_TO_SAVEPOINT,

    /* DDL */
    ESQL_TYPE_DDL,  

    /* PSM */
    ESQL_TYPE_PSM,  

    ESQL_TYPE_DYN_EXEC_IMMED,
    ESQL_TYPE_DYN_EXECUTE,
    ESQL_TYPE_DYN_PREPARE,
    ESQL_TYPE_DYN_OPEN_CURSOR,
    ESQL_TYPE_DYN_DESC_BIND,
    ESQL_TYPE_DYN_DESC_SELECT,

    ESQL_TYPE_ANSIDYN_ALLOC_DESC,
    ESQL_TYPE_ANSIDYN_DEALLOC_DESC,
    ESQL_TYPE_ANSIDYN_SET_DESC,
    ESQL_TYPE_ANSIDYN_GET_DESC,
    ESQL_TYPE_ANSIDYN_DESC_INPUT,
    ESQL_TYPE_ANSIDYN_DESC_OUTPUT,

    /* THREAD & CONTEXT */
    ESQL_TYPE_ENABLE_THREADS,
    ESQL_TYPE_CONTEXT_ALLOCATE,
    ESQL_TYPE_CONTEXT_USE,
    ESQL_TYPE_CONTEXT_FREE,

    /* ALLOCATE & FREE */
    ESQL_TYPE_ALLOCATE,
    ESQL_TYPE_FREE,

    /* LOB */
    ESQL_TYPE_LOB_APPEND,
    ESQL_TYPE_LOB_ASSIGN,
    ESQL_TYPE_LOB_CLOSE,
    ESQL_TYPE_LOB_COPY,
    ESQL_TYPE_LOB_CREATE_TEMP,
    ESQL_TYPE_LOB_DESCRIBE,
    ESQL_TYPE_LOB_ERASE,
    ESQL_TYPE_LOB_FREE_TEMP,
    ESQL_TYPE_LOB_OPEN,
    ESQL_TYPE_LOB_READ,
    ESQL_TYPE_LOB_TRIM,
    ESQL_TYPE_LOB_WRITE,

    /* ETC */
    ESQL_TYPE_START_SQL,
    ESQL_TYPE_END_SQL,

    ESQL_TYPE_REGISTER_CONNECT,
    ESQL_TYPE_XA_SET_CONNECTION
} esql_type_t;



/*
==========================================
       char_map 
==========================================


CHAR_MAP  fixed-length  blank-padded  null-terminated  NULL is fixed-length
(DBMS)                                                      blank-padded
---------------------------------------------------------------------------
VARCHAR2        o           o             x               o
CHARF           o           o             x               x
CHARZ           o           o             o               o
STRING          x           x             o               x
*/

typedef enum char_map_e {
    CHAR_MAP_DEFAULT = 0,
    CHAR_MAP_VARCHAR2,
    CHAR_MAP_CHARF,
    CHAR_MAP_CHARZ,
    CHAR_MAP_STRING
} char_map_t;



typedef enum esql_desc_item_e {
    ESQL_DESC_ITEM_NONE = 0,
    ESQL_DESC_ITEM_TYPE,
    ESQL_DESC_ITEM_LENGTH,
    ESQL_DESC_ITEM_INDICATOR,
    ESQL_DESC_ITEM_INDICATOR_P,
    ESQL_DESC_ITEM_DATA,
    ESQL_DESC_ITEM_DATA_P,
    ESQL_DESC_ITEM_OCTET_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH_P,
    ESQL_DESC_ITEM_RETURNED_OCTET_LENGTH,
    ESQL_DESC_ITEM_PRECISION,
    ESQL_DESC_ITEM_SCALE,
    ESQL_DESC_ITEM_NULLABLE,
    ESQL_DESC_ITEM_NAME,
    ESQL_DESC_ITEM_CHARACTER_SET_NAME,
    ESQL_DESC_COUNT
} esql_desc_item_t;



#include <string.h>


#include "sqlca.h"


typedef void * sql_context;
typedef void * SQL_CONTEXT;



typedef void * sql_cursor;
typedef void * SQL_CURSOR;



typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;



static struct esql_sqlctx {
    esql_type_t     stmt_type;

    char           *db_name;
    char           *cursor_name;
    char           *pstmt_name;
    char           *savepoint;
    char           *stmt;

    char_map_t      char_map;
    int             stmt_cache_size;
    int             fetch_type;
    int             abs_rel_nth;
    int             flag;
    int             option;

    struct sqlca   *sqlca;
    void           *sqlda;

    char           *desc_name;
    char           *desc_into;
    int             value;

    sql_context    *sql_ctx;
    char           *sqlstate;

    unsigned int    file_id;
    unsigned int    prefetch;

    int             rmid;

    unsigned int    dummy[2];

    void           *reserved[1];
    void           *oraca;
    void           *ep_ctx;

    unsigned int    iter_cnt;               /* count of iteration */
    unsigned int    host_var_total_cnt;     /* total # of host var */
    unsigned int    host_var_out_cnt;       /* # of out host var */

    void               **p_hostvar;         /* array of host var */
    unsigned int        *p_hostvar_len;     /* array of length of host var */
    unsigned int        *p_hostvar_stride;  /* array of stride of host var */
    esql_hostvar_type_t *p_hostvar_type;    /* array of host var type */
    unsigned int        *p_param_type;      /* array of param type */
    esql_desc_item_t    *p_ansi_dyn_type;   /* array of ansi dyn item type */
    void               **p_hostind;         /* array of host ind */
    unsigned int        *p_hostind_stride;  /* array of stride of host ind */
    long                *p_ind;             /* array of indicator */


    void                *hostvar[2];        /* array of host var */
    unsigned int         hostvar_len[2];    /* array of length of host var */
    unsigned int         hostvar_stride[2]; /* array of stride of host var */
    esql_hostvar_type_t  hostvar_type[2];   /* array of host var type */
    unsigned int         param_type[2];     /* array of param type */
    esql_desc_item_t     ansi_dyn_type[2];  /* array of ansi dyn item type */
    void                *hostind[2];        /* array of host ind */
    unsigned int         hostind_stride[2]; /* array of stride of host ind */
    long                 ind[2];            /* array of indicator */

} sqlstm;


extern void esql_do(struct esql_sqlctx *_sqlctx);



#endif



#include <stdio.h>
#include <ctype.h>
#include <usrinc/atmi.h>
#include <usrinc/sdl.h>
#include "../sdl/demo.s"
#define OKMSG "YOU COMPLETE THE TRANSACTION"
#define USERPASS "tibero/tmax"

	/*
		EXEC SQL include sqlca.h;
	 */
#ifndef _SQLCA_H
#define _SQLCA_H

#define SQLERRMC_LEN	70

struct sqlca {
    char    sqlcaid[8];              /* "SQLCA" id */
    int     sqlabc;                  /* byte length of SQL structure */
    int     sqlcode;                 /* status code of SQL execution */

    struct {
        unsigned short sqlerrml;     /* message length */
        char           sqlerrmc[SQLERRMC_LEN]; /* error message */
    } sqlerrm;

    char    sqlerrp[8];              /* RESERVED */
    int     sqlerrd[6];              /* error */
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows affected after an INSERT, UPDATE, DELETE	*/
	/* 3: empty							*/
	/* 4: empty							*/
	/* 5: empty							*/

    char    sqlwarn[8];              /* warning */
  	/* Element 0: set to 'W' if at least one other is 'W'		*/
	/* 1: if 'W' at least one character string			*/
	/* value was truncated when it was stored into a host variable.	*/
	/* 2: if 'W' a (hopefully) non-fatal notice occured		*/
	/* 3: empty 							*/
	/* 4: empty							*/
	/* 5: empty							*/
	/* 6: empty							*/
	/* 7: empty							*/
    char    sqlext[8];               /* RESERVED */
};

#ifndef _WIN32
extern struct sqlca sqlca;
#else   /* _WIN32 */
#   ifdef __cplusplus
extern "C" struct sqlca __declspec(dllimport) sqlca;
#   else
extern struct sqlca __declspec(dllimport) sqlca;
#   endif
#endif  /* _WIN32 */

#endif  /* _SQLCA_H */

	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
    int     account_id;
    int     money;

	/*
		EXEC SQL END DECLARE SECTION;
	 */

//INSERT(TPSVCINFO *msg){   이렇게 해야하는게 아닌가?
//INSERT(msg)
//TPSVCINFO  *msg;
//{
CREATE(TPSVCINFO *msg)
{
    struct input *rcvbuf;
    int     ret;
    long    acnt_id;
    char    *send;

    rcvbuf = (struct input *)(msg->data);
    send = (char *)tpalloc("STRING", NULL, 0);
    if (send == NULL) {
        fprintf(stderr, "tpalloc fail errno = %s\n", tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, (char *)NULL, 0, TPNOFLAGS);
    }


    account_id = rcvbuf->account_id;
    money= rcvbuf->money;
    
	/*
		EXEC SQL CONNECT :"tibero/tmax"
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)("tibero/tmax");
    __sqlctx.hostvar_len[0]     = (unsigned int)strlen("tibero/tmax")+1;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHARP;
    __sqlctx.param_type[0]      = 16;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    /*  Declare && Open Cursor for Fetch */
    
	/*
		EXEC SQL INSERT INTO ACCOUNT (
    ACCOUNT_ID, 
    MONEY )
    VALUES (
    :account_id, :money);
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "INSERT INTO ACCOUNT (\n\
    ACCOUNT_ID, \n\
    MONEY )\n\
    VALUES (\n\
    :v000, :v001)";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(account_id));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(&(money));
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 0;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    
	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf("account_id = %d\nmoney = %d\n",account_id,money);
    if (sqlca.sqlcode != 0 && sqlca.sqlcode != 1403 )
    {
        printf("CREATE(INSERT) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }
    strcpy(send, OKMSG);
    tpreturn(TPSUCCESS, 1, (char *)send, strlen(send), TPNOFLAGS);
}

DEPOSIT(TPSVCINFO *msg)
{
    struct input *rcvbuf;
    int     ret;
    long    acnt_id;
    char    *send;

    rcvbuf = (struct input *)(msg->data);
    send = (char *)tpalloc("STRING", NULL, 0);
    if (send == NULL) {
        fprintf(stderr, "tpalloc fail errno = %s\n", tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, (char *)NULL, 0, TPNOFLAGS);
    }


    account_id = rcvbuf->account_id;
    
	/*
		EXEC SQL CONNECT :"tibero/tmax"
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)("tibero/tmax");
    __sqlctx.hostvar_len[0]     = (unsigned int)strlen("tibero/tmax")+1;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHARP;
    __sqlctx.param_type[0]      = 16;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    
	/*
		EXEC SQL SELECT MONEY INTO :money FROM ACCOUNT WHERE ACCOUNT_ID = :account_id;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "SELECT MONEY             FROM ACCOUNT WHERE ACCOUNT_ID = :v000";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(money));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(&(account_id));
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    /*  Declare && Open Cursor for Fetch */
    long prevmoney = money;
    money = money + rcvbuf->money;
    
	/*
		EXEC SQL UPDATE ACCOUNT
             SET MONEY = :money
             WHERE ACCOUNT_ID = :account_id;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "UPDATE ACCOUNT\n\
             SET MONEY = :v000\n\
             WHERE ACCOUNT_ID = :v001";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(money));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 8;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(&(account_id));
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    printf("account_id = %d\nmoney = %d\n",account_id,money);
    if ((sqlca.sqlcode != 0 && sqlca.sqlcode != 1403) )
    {
        printf("DEPOSIT(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }
    if (prevmoney>money)
    {
        printf("money high limit over prevmoney<money");
        printf("WITHDROW(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }
    if (money<0)
    {
        printf("money high limit over money<0");
        printf("WITHDROW(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }
    strcpy(send, OKMSG);
    
	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    tpreturn(TPSUCCESS, 1, (char *)send, strlen(send), TPNOFLAGS);
}

WITHDROW(TPSVCINFO *msg)
{
    struct input *rcvbuf;
    int     ret;
    long    acnt_id;
    char    *send;

    rcvbuf = (struct input *)(msg->data);
    send = (char *)tpalloc("STRING", NULL, 0);
    if (send == NULL) {
        fprintf(stderr, "tpalloc fail errno = %s\n", tpstrerror(tperrno));
        tpreturn(TPFAIL, 0, (char *)NULL, 0, TPNOFLAGS);
    }


    account_id = rcvbuf->account_id;

    
	/*
		EXEC SQL CONNECT :"tibero/tmax"
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)("tibero/tmax");
    __sqlctx.hostvar_len[0]     = (unsigned int)strlen("tibero/tmax")+1;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHARP;
    __sqlctx.param_type[0]      = 16;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    
	/*
		EXEC SQL SELECT MONEY INTO :money FROM ACCOUNT WHERE ACCOUNT_ID = :account_id;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "SELECT MONEY             FROM ACCOUNT WHERE ACCOUNT_ID = :v000";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(money));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(&(account_id));
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    /*  Declare && Open Cursor for Fetch */
    long prevmoney = money;
    money= money - rcvbuf->money;
    
	/*
		EXEC SQL UPDATE ACCOUNT 
             SET MONEY = :money
             WHERE ACCOUNT_ID = :account_id;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "UPDATE ACCOUNT \n\
             SET MONEY = :v000\n\
             WHERE ACCOUNT_ID = :v001";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(money));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 8;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(&(account_id));
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf("account_id = %d\nmoney = %d\n",account_id,money);
    if (sqlca.sqlcode != 0 && sqlca.sqlcode != 1403 )
    {
        printf("WITHDROW(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }

    if (prevmoney<money)
    {
        printf("money min limit over prevmoney<money");
        printf("WITHDROW(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }
    if (money<0)
    {
        printf("money min limit over money<0");
        printf("WITHDROW(UPDATE) failed sqlcode = %d\n", sqlca.sqlcode);
        tpreturn(TPFAIL, -1, (char *)NULL, 0, TPNOFLAGS);
    }

    strcpy(send, OKMSG);
    
	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    struct esql_sqlctx  __sqlctx;
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 62;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    tpreturn(TPSUCCESS, 1, (char *)send, strlen(send), TPNOFLAGS);
}
