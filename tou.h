#ifndef TOU_H
#define TOU_H
typedef struct
{
        char name[10];
        char kk[20];
        char gender;
        char mobile[20];
        unsigned long time;
        unsigned int delet; //0注销 1正常
        unsigned int cade; //会员卡类型
        //chat time1[20];  //到期时间
}hy;

//页面函数
void login();
void clear();
void add_page();
void query_page();
void alter_page();
void deleat_page();
void login11();
void regist();
void login1();

//功能函数
void information_demo(hy* a);
int less_name(char* a,size_t s);
void alter_demo(hy* a,size_t b,char* c);
void deleat_demo(char* a);
char* gender_demo(char a);
char* cade_demo(unsigned int a);
void regist_demo(char* a);
void login_demo(char* a);

#endif


