#include<stdio.h>
#include"tou.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>

//实现清屏效果
void clear()
{
	system("clear");
}

void login11()
{	
	char m[20];
	int a;
	printf("======= 管理员页面 =======\n");
	printf("1. 登录\n");
	printf("2. 注册\n");
	printf("==========================\n\n");

	printf("请输入操作编号:");
	scanf("%d",&a);
	getchar();
	if(a==1)
	{
		login1();
	}
	else if(a==2)
	{
		regist();
	}
	else
	{
		printf("请重新输入\n");
		login11();

	}
	return;
}

//登录页面
void login1()
{
	char b[20];
	int a;
	printf("======= 管理员登录页面 =======\n");
	printf("请输入你的管理员密码\n");
	scanf("%s",b);
	getchar();

	login_demo(b);
	printf("按0返回管理员页面\n");
	printf("请输入操作编号:");
	scanf("%d",&a);
	getchar();
	if(a==0)
	{
		login11();
	}
	return;
}


//注册页面
void regist()
{
	char b[20];
	int a;
	printf("======= 管理员注册页面 =======\n");
	printf("请输入你的管理员密码\n");
	scanf("%s",b);
	getchar();

	regist_demo(b);
	printf("按0返回管理员页面\n");
	printf("请输入操作编号:");
	scanf("%d",&a);
	getchar();
	if(a==0)
	{
		login11();
	}
	return;
}

//主页面
void login()
{

	clear();
	printf("===== 会员管理系统 =====\n");
	printf("1. 添加会员\n");
	printf("2. 查询会员\n");
	printf("3. 修改会员信息\n");
	printf("4. 删除会员信息\n");
	printf("0. 退出系统\n");
	printf("========================\n\n");
	printf("请输入操作编号: ");
	unsigned int a;
	scanf("%d",&a);
	getchar();
	switch(a)
	{
		case 1: add_page();
			break;
		case 2: query_page();
			break;
		case 3: alter_page();
			break;
		case 4: deleat_page();
			break;
		case 0: printf("欢迎您的再次光临\n");
			return;
			break;
		default: printf("输入错误请您重新输入:");
			 login();
			 return;
	}

}

//添加会员
void add_page()
{
	clear();
	hy page;
	printf("===== 添加会员 =====\n");
	printf("1. 请输入会员的姓名：");
	scanf("%s",page.name);
	getchar();
	printf("2. 请输入会员的卡号：");
	scanf("%s",page.kk);
	getchar();
	printf("3. 请输入会员的性别(1,男 2,女)：");
	scanf("%c",&(page.gender));
	getchar();
	printf("4. 请输入会员的手机号：");
	scanf("%s",page.mobile);
	getchar();
	printf("5. 请输入会员的卡类型(1,年卡 2,月卡)：");
	scanf("%d",&(page.cade));
	getchar();


	page.time=time(NULL);
	page.delet=1;
	struct tm* dt;
	dt=localtime(&page.time);


	clear();
	printf("=====会员信息=====\n");
	printf(" 姓名：%s\n 卡号：%s\n 性别：%s\n 手机号：%s\n 卡类型: %s\n",page.name,page.kk,gender_demo(page.gender),page.mobile,cade_demo(page.cade));	
	printf(" 注册时间:%d年%d月%d日 %02d:%02d\n",dt->tm_year + 1900,dt->tm_mon+1,dt->tm_mday,dt->tm_hour,dt->tm_min);

	printf(" 请您检查信息是否正确\n");
	printf(" 1. 信息正确录入会员信息\n");
	printf(" 2. 信息输入有误重新输入\n");
	while(1)
	{
		printf("请输入操作编号: ");
		unsigned int m;
		scanf("%d",&m);
		if(m==1)
		{
			//录入信息
			information_demo(&page);
			printf("您的信息录入成功\n");	
			break;	
		}
		else if(m==2)
		{
			printf("重新录入信息\n");
			add_page();
			break;
		}
		else
		{
			printf("输入有误请您重新输入\n");
			continue;
		}
	}

	printf("========================\n");
	printf("1. 继续添加会员\n");
	printf("2. 返回主页面\n");
	printf("========================\n");

	while(1)
	{	
		printf("请输入操作编号: ");

		int a;
		scanf("%d",&a);
		if(a==1) 
		{
			add_page();
			break;
		}
		else if(a==2)
		{
			login();
			break;
		}
		else
		{
			printf("输入错误请重新输入:");
			continue;
		}
	}

}

//查询会员
void query_page()
{
	clear();
	int f=0;
	printf("=====请选择你要查询的方式=====\n");
	printf("1. 会员姓名\n");
	printf("2. 会员卡号\n");
	printf("3. 会员手机号\n");
	scanf("%d",&f);
	getchar();
	char q[20];
	switch(f)
	{
		case 1:
			printf("请输入会员的姓名:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		case 2:
			printf("输入会员卡号:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		case 3: 
			printf("输入会员的手机号:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		default: printf("请重新输入");
			 query_page();
	}
	printf("\n");

	printf("========================\n");
	printf("1. 继续查询会员\n");
	printf("2. 返回主页面\n");
	printf("========================\n");
	while(1)
	{	
		printf("请输入操作编号: ");

		int a;
		scanf("%d",&a);
		if(a==1) 
		{
			query_page();
			break;
		}
		else if(a==2)
		{
			login();
			break;
		}
		else
		{
			printf("输入错误请重新输入:");
			continue;
		}
	}
}

//修改会员信息
void alter_page()
{
	clear();
	printf("=====请查询你要修改的会员信息=====\n");
	printf("1. 会员姓名\n");
	printf("2. 会员卡号\n");
	printf("3. 会员手机号\n");

	int f;
	scanf("%d",&f);
	getchar();
	char q[20];
	hy yuan;
	switch(f)
	{
		case 1:
			printf("请输入会员的姓名:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		case 2:
			printf("输入会员卡号:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		case 3: 
			printf("输入会员的手机号:");
			scanf("%s",q);
			getchar();
			less_name(q,f);
			break;
		default: printf("请重新输入");
			alter_page();
	}
	printf("您确定要修改该会员的信息吗?\n");
	printf("1. 是\n");
	printf("2. 否\n");
	int a;
	while(1)
	{	
		printf("请输入操作编号: ");

		scanf("%d",&a);
		if(a==1) 
		{
			break;
		}
		else if(a==2)
		{
			alter_page();
			break;
		}
		else
		{
			printf("输入错误请重新输入:");
			continue;
		}
	}

	clear();
	while(1)
	{
		if(a==1)
		{
			printf("=====修改该会员信息=====\n\n");

			hy page;
			printf("请您重新输入该会员的信息\n");
			printf("1. 请输入会员的姓名：");
			scanf("%s",page.name);
			getchar();
			printf("2. 请输入会员的卡号：");
			scanf("%s",page.kk);
			getchar();
			printf("3. 请输入会员的性别(1,男 0,女)：");
			scanf("%c",&(page.gender));
			getchar();
			printf("4. 请输入会员的手机号：");
			scanf("%s",page.mobile);
			getchar();
			printf("5. 请输入会员的卡类型(1,年卡 2,月卡)：");
			scanf("%d",&(page.cade));
			getchar();

			printf("修改的该会员信息为\n");
			printf("姓名:%s \n卡号:%s \n性别:%c \n手机号:%s \n卡类型:%s \n",page.name,page.kk,page.gender,page.mobile,cade_demo(page.cade));
			printf("\n");

			printf("请您确实是否要修改\n");
			printf("1. 确定修改\n");
			printf("2. 信息有误重新输入\n");
			printf("3. 放弃修改返回主页面\n");

			int n;
			scanf("%d",&n);
			if(n==1)
			{
				switch(f)
				{
					case 1:
						alter_demo(&page,f,q);
						break;
					case 2:
						alter_demo(&page,f,q);
						break;
					case 3:
						alter_demo(&page,f,q);
						break;
					default: printf("请重新输入");
						 alter_page();
						 break;
				}				
			}
			else if(n==2) continue;
			else if(n==3) 
			{
				login();
				break;
			}
		}
		printf("您是否要继续修改会员信息\n");
		printf("1. 继续修改\n");
		printf("2. 返回主页\n");
		printf("请输入操作编号\n");
		int l;
		scanf("%d",&l);
		if(l==1)
		{
			alter_page();
		}
		else if(l==2)
		{
			login();
			return;
		}
	}
	return;


}

//删除会员信息
void deleat_page()
{
	clear();
	printf("=====请查询你要删除的会员信息=====\n");
        printf("请输入会员的卡号:");
	char a[20];
	scanf("%s",a);
	getchar();
	deleat_demo(a);

	printf("您是否要删除修改会员信息\n");
	printf("1. 继续删除\n");
	printf("2. 返回主页\n");
	printf("请输入操作编号\n");
	int l;
	scanf("%d",&l);
	if(l==1)
	{
		deleat_page();
	}
	else if(l==2)
	{
		login();
		return;
	}
	
}
