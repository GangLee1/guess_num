#include "stdio.h" 
#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 4

double random(double start, double end)
{
return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

int *random_num(int *c)
{
	for(int i=0; i<N-1;i++)
		for(int k=i+1;k<N;k++)
		{
			if(c[i]==c[k] && c[k]==9)c[k]=1;
			if(c[i]==c[k] && c[k]<9)c[k]=(c[k]+1)%10;
			for(int j=0;j<k;j++)
			{
				if(c[k]==c[j] && c[k]==9)c[k]=1;
				if(c[j]==c[k] && c[k]<9)c[k]=(c[k]+1)%10;
			}
		}
	return c;
}//判断随机数是否有重复数字并修改重复数字

void games()
{
	int wanjia=0;
	int *random_num(int *);
	int a,open;

	printf("游戏开始:\n");
	while(1){
		printf("请输入您想进行的游戏模式:1-有限次猜数 2-无限次猜数 :");
		scanf("%d",&a);
		if(a==1)
		{
			int *c,b,t[N],step=0;		//将步骤置0
			printf("我们已抽取了一个各位上的数字不重复的4位数;\n");
			double random(double,double);
			srand(unsigned(time(0)));

			for(int i=0; i<N; i++)
			t[i]=int(random(0,10));
			c=t;
			c=random_num(c);
			printf("请输入您需要猜数的次数,本轮游戏将该次数为限:");
			scanf("%d",&b);	
			do{
				int i=0,p=0,d[N]={0},h=0;		//重置h,保证输入的数字每次各位上不重复
			
				printf("请猜测一个四位数,各位上从1到9不重复的数字:");
				scanf("%d",&wanjia);
				if(wanjia/1000>10 ){
					printf("输入的数字不要超过4位且您已经猜过%d次;\n",step);
					continue;
				}
				if(wanjia/1000==0){
					printf("输入的数字不要少于4位且您已经猜过%d次;\n",step);
					continue;
				}
				while(wanjia)
				{
					d[i++]=wanjia%10;
					wanjia=wanjia/10;
				}
				for(i=0;i<N/2;i++)
				{
					p=d[i];
					d[i]=d[N-i-1];
					d[N-i-1]=p;
				}//将数字变成整数数组
				for(i=0;i<N-1;i++)
					for(int j=i+1;j<N;j++)
						if(d[i]==d[j]){
							h=1;
							break;}
				if(h==1){
					printf("输入的数字各位上不能重复且您已经猜过%d次;\n",step);
					continue;
				}
				
				int l=0,r=0;			//重置l,r
				for(i=0;i<N;i++)
				{
					if(c[i]==d[i])l++;
					for(int j=0;j<N;j++)
						if(c[i]==d[j])r++;
				}
				step++;
				if(r==l && r==4)	//猜测正确，退出循环
				{
					printf("猜测正确\n");
					break;
				}
				printf("%dA%dB",r,l);
				printf("\n");
				}while(step<b);		//猜测循环
			printf("猜测了%d次\n",step);
			printf("随机数为:");
			for(int i=0;i<N;i++) printf("%d",c[i]);
			printf("\n");
		}
		
		if(a==2)
		{
			int *c,t[N],step=0;		//将步骤置0
			printf("我们已抽取了一个各位上的数字不重复的4位数;\n");
			double random(double,double);
			srand(unsigned(time(0)));

			for(int i=0; i<N; i++)
			t[i]=int(random(0,10));
			c=t;
			c=random_num(c);
			
			do
			{
				int str;
			
				int i=0,p=0,d[N]={0},h=0;		//重置h,保证输入的数字每次各位上不重复
				
				printf("请猜测一个四位数,各位上从1到9不重复的数字:");
				scanf("%d",&wanjia);
				if(wanjia/1000>10 ){
				printf("输入的数字不要超过4位且您已经猜过%d次;\n",step);
				continue;
				}
				if(wanjia/1000==0){
					printf("输入的数字不要少于4位且您已经猜过%d次;\n",step);
					continue;
				}
				while(wanjia)
				{
					d[i++]=wanjia%10;
					wanjia=wanjia/10;
				}
				for(i=0;i<N/2;i++)
				{
					p=d[i];
					d[i]=d[N-i-1];
					d[N-i-1]=p;
				}//将数字变成整数数组
				for(i=0;i<N-1;i++)
					for(int j=i+1;j<N;j++)
						if(d[i]==d[j]){
							h=1;
							break;}
				if(h==1){
					printf("输入的数字各位上不能重复且您已经猜过%d次;\n",step);
					continue;
				}
					
				int l=0,r=0;			//重置l,r和h
				for(i=0;i<N;i++)
				{
					if(c[i]==d[i])l++;
					for(int j=0;j<N;j++)
						if(c[i]==d[j])r++;
				}
				step++;
				if(r==l && r==4)	//猜测正确，退出循环
				{
					printf("猜测正确\n");
					break;
				}
				printf("%dA%dB",r,l);
				printf("\n");

				if(step%5==0)		//为玩家提供退出的机会，每猜测5次看玩家是否想继续
				{
					printf("您还想继续游戏吗？1/0:");
					scanf("%d",&str);
					if(str==0)break;
				}
			}while(1);		//无限循环
			printf("猜测了%d次\n",step);
			printf("随机数为:");
			for(int i=0;i<N;i++)printf("%d",c[i]);
			printf("\n");
		}
		printf("您还想继续游戏吗?1/0:");
		scanf("%d",&open);
		printf("\n");
		if(open==0)break;		
	}
	
}

int main()
{
	printf("游戏介绍:\n");
	printf("1.这是一个猜数字游戏,在每次游戏前，我们都会随机抽取一个各位上数字都不重复的4位数,如1234;\n");
	printf("2.每次猜测输入的数据都给出类似的提示*A*B;\n");
	printf("3.其中A前的*代表本次猜对了多少个数字，B前的*代表本次才对的数字并且位置正确的数字数目;\n");
	games();
	return 0;
}
