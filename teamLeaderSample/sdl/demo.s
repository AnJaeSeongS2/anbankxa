struct kstrdata {
    int     len;
    char    sdata[20];
};

struct input {
        long    inacnt_id;
};

struct input1 {
        long    inacnt_id;
        char    address[61];
};

struct test {
    char    kor_echo[20];
    char    upper[20];
};

struct sdlsel{
        long  account_id;
        long  branch_id;
        char  ssn[14];
        long  balance;
        char  acct_type[2];
        char  last_name[21];
        char  first_name[21];
        char  mid_init[2];
        char  phone[15];
        char  address[61];
};

struct info_3 {
        long customer_num;
        char lname[15];
        char zipcode[5];
};

struct edu_emp{
        int empno;
        char ename[11];
        char job[10];
        int mgr;
        char date[9];
        float sal;
        float comm;
        int deptno;
};
struct echo_s {
        char charval;
        short shortval;
        int intval;
        float floatval;
        double doubleval;
        char stringval[19];
};

struct rqsvc {
        char svc[20];
        char data[20];
};

struct emp {
        int type;
        int empno;
};