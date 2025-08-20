#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"tou.h"

char* gender_demo(char a)
{
	if(a=='1')
	{
		return "男";
	}
	else if(a=='2')
	{
		return "女";
	}
}

char* cade_demo(unsigned int a)
{
	if(a==1)
	{
		return "年卡";
	}
	else if(a==2)
	{
		return "月卡";
	}
}


//添加
void information_demo(hy* a)
{
        FILE* fp=fopen("huiyuanxinxi","a");
        if(fp==NULL)
        {
                printf("fopen file!");
                exit(-1);
        }
        fwrite(a,sizeof(hy),1,fp);
        fclose(fp);
}


//查询
int less_name(char* a,size_t s)
{
        int b;
        FILE* fp=fopen("huiyuanxinxi","rb");
        if(fp==NULL)
        {
                printf("fopen file");
                exit(-1);
        }
        hy na;
        while(1)
        {
                int c;
                fread(&na,sizeof(na),1,fp);
                if(s==1)
                {
                        c=strcmp(a,na.name);
                }
                else if(s==2)
                {
                        c=strcmp(a,na.kk);
                }
                else if(s==3)
                {
			c=strcmp(a,na.mobile);
		}
		if(c==0 && na.delet==1)
		{
			b=1;
			printf("以下是该会员的基本信息\n");
			printf(" 姓名:%s \n 卡号:%s \n 性别:%s \n 手机号:%s \n ",na.name,na.kk,gender_demo(na.gender),na.mobile);
			struct tm* dt; 
			dt=localtime(&na.time);
			printf("注册时间:%d年%d月%d日 %02d:%02d\n",dt->tm_year + 1900,dt->tm_mon+1,dt->tm_mday,dt->tm_hour,dt->tm_min);

			break;
                }
                else if(feof(fp)==1)
                {
                        printf("没有该会员的信息\n");
			break;
                }
     	}
        fclose(fp);
        return 1;

}

//修改会员信息
void alter_demo(hy* a,size_t b,char* d)
{
        FILE* fp=fopen("huiyuanxinxi","r+");
        if(fp==NULL)
        {
                printf("fopen file");
                exit(-1);
        }
        hy na;
        while(fread(&na,sizeof(na),1,fp))
        {
                int c;
                if(b==1)
                {
                        c=strcmp(d,na.name);
                }
                else if(b==2)
                {
                        c=strcmp(d,na.kk);
                }
                else if(b==3)
                {
			c=strcmp(d,na.mobile);
		}
		if(c==0)
		{
			unsigned long p=ftell(fp);
			fseek(fp,p-sizeof(hy),SEEK_SET);
			unsigned long ti=na.time;
			a->time=ti;
			a->delet=1;
			if(fwrite(a,sizeof(hy),1,fp))
			{
				printf("修改成功\n");
				break;
			}
			else
			{
				printf("修改失败\n");
				break;
			}
                } 
     	}
        fclose(fp);
	return;
}

void deleat_demo(char* a)
{
	hy f;
	FILE* fp=fopen("huiyuanxinxi","r+");
	if(fp==NULL)
	{
		printf("fopen fail\n");
		exit(-1);
	}
	while(1)
	{
		fread(&f,sizeof(hy),1,fp);
		if(strcmp(a,f.kk)==0 && f.delet==1)
		{
			printf("以下是该会员的基本信息\n");
                        printf(" 姓名:%s \n 卡号:%s \n 性别:%s \n 手机号:%s \n",f.name,f.kk,gender_demo(f.gender),f.mobile);
                        struct tm* dt;
                        dt=localtime(&f.time);
                        printf("注册时间:%d年%d月%d日 %02d:%02d\n",dt->tm_year + 1900,dt->tm_mon+1,dt->tm_mday,dt->tm_hour,dt->tm_min);
			
			unsigned long s=ftell(fp);
			fseek(fp,s-sizeof(hy),SEEK_SET);

			f.delet=0;
			if(fwrite(&f,sizeof(hy),1,fp))
			{
				printf("删除成功!\n");
				break;
			}
			else 
			{
				printf("删除失败\n");
				break;
			}
			break;
		}
	       /*	else 
		{
			printf("没有此会员的信息");
		}*/
		if(feof(fp)==1)
		{
			printf("没有该会员的信息\n");
			break;
		}
	}

	fclose(fp);
	return ;

}
void regist_demo(char* a)
{
	FILE* fp=fopen("login","w");
	if(fp==NULL)
	{
		printf("login fail\n");
		return ;
	}
	fputs(a,fp);
	printf("您的密码为%s\n",a);
	fclose(fp);
	return ;
}

void login_demo(char* a)
{
	FILE* fp=fopen("login","r");
	if(fp==	NULL)
	{
		printf("file\n");
		return ;
	}
	char s[20];
	fgets(s,sizeof(a),fp);
	if(strcmp(a,s)==0)
	{
		printf("登录成功\n");
		login();
	}
	fclose(fp);
	return;
}
