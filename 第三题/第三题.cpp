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
}//�ж�������Ƿ����ظ����ֲ��޸��ظ�����

void games()
{
	int wanjia=0;
	int *random_num(int *);
	int a,open;

	printf("��Ϸ��ʼ:\n");
	while(1){
		printf("������������е���Ϸģʽ:1-���޴β��� 2-���޴β��� :");
		scanf("%d",&a);
		if(a==1)
		{
			int *c,b,t[N],step=0;		//��������0
			printf("�����ѳ�ȡ��һ����λ�ϵ����ֲ��ظ���4λ��;\n");
			double random(double,double);
			srand(unsigned(time(0)));

			for(int i=0; i<N; i++)
			t[i]=int(random(0,10));
			c=t;
			c=random_num(c);
			printf("����������Ҫ�����Ĵ���,������Ϸ���ô���Ϊ��:");
			scanf("%d",&b);	
			do{
				int i=0,p=0,d[N]={0},h=0;		//����h,��֤���������ÿ�θ�λ�ϲ��ظ�
			
				printf("��²�һ����λ��,��λ�ϴ�1��9���ظ�������:");
				scanf("%d",&wanjia);
				if(wanjia/1000>10 ){
					printf("��������ֲ�Ҫ����4λ�����Ѿ��¹�%d��;\n",step);
					continue;
				}
				if(wanjia/1000==0){
					printf("��������ֲ�Ҫ����4λ�����Ѿ��¹�%d��;\n",step);
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
				}//�����ֱ����������
				for(i=0;i<N-1;i++)
					for(int j=i+1;j<N;j++)
						if(d[i]==d[j]){
							h=1;
							break;}
				if(h==1){
					printf("��������ָ�λ�ϲ����ظ������Ѿ��¹�%d��;\n",step);
					continue;
				}
				
				int l=0,r=0;			//����l,r
				for(i=0;i<N;i++)
				{
					if(c[i]==d[i])l++;
					for(int j=0;j<N;j++)
						if(c[i]==d[j])r++;
				}
				step++;
				if(r==l && r==4)	//�²���ȷ���˳�ѭ��
				{
					printf("�²���ȷ\n");
					break;
				}
				printf("%dA%dB",r,l);
				printf("\n");
				}while(step<b);		//�²�ѭ��
			printf("�²���%d��\n",step);
			printf("�����Ϊ:");
			for(int i=0;i<N;i++) printf("%d",c[i]);
			printf("\n");
		}
		
		if(a==2)
		{
			int *c,t[N],step=0;		//��������0
			printf("�����ѳ�ȡ��һ����λ�ϵ����ֲ��ظ���4λ��;\n");
			double random(double,double);
			srand(unsigned(time(0)));

			for(int i=0; i<N; i++)
			t[i]=int(random(0,10));
			c=t;
			c=random_num(c);
			
			do
			{
				int str;
			
				int i=0,p=0,d[N]={0},h=0;		//����h,��֤���������ÿ�θ�λ�ϲ��ظ�
				
				printf("��²�һ����λ��,��λ�ϴ�1��9���ظ�������:");
				scanf("%d",&wanjia);
				if(wanjia/1000>10 ){
				printf("��������ֲ�Ҫ����4λ�����Ѿ��¹�%d��;\n",step);
				continue;
				}
				if(wanjia/1000==0){
					printf("��������ֲ�Ҫ����4λ�����Ѿ��¹�%d��;\n",step);
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
				}//�����ֱ����������
				for(i=0;i<N-1;i++)
					for(int j=i+1;j<N;j++)
						if(d[i]==d[j]){
							h=1;
							break;}
				if(h==1){
					printf("��������ָ�λ�ϲ����ظ������Ѿ��¹�%d��;\n",step);
					continue;
				}
					
				int l=0,r=0;			//����l,r��h
				for(i=0;i<N;i++)
				{
					if(c[i]==d[i])l++;
					for(int j=0;j<N;j++)
						if(c[i]==d[j])r++;
				}
				step++;
				if(r==l && r==4)	//�²���ȷ���˳�ѭ��
				{
					printf("�²���ȷ\n");
					break;
				}
				printf("%dA%dB",r,l);
				printf("\n");

				if(step%5==0)		//Ϊ����ṩ�˳��Ļ��ᣬÿ�²�5�ο�����Ƿ������
				{
					printf("�����������Ϸ��1/0:");
					scanf("%d",&str);
					if(str==0)break;
				}
			}while(1);		//����ѭ��
			printf("�²���%d��\n",step);
			printf("�����Ϊ:");
			for(int i=0;i<N;i++)printf("%d",c[i]);
			printf("\n");
		}
		printf("�����������Ϸ��?1/0:");
		scanf("%d",&open);
		printf("\n");
		if(open==0)break;		
	}
	
}

int main()
{
	printf("��Ϸ����:\n");
	printf("1.����һ����������Ϸ,��ÿ����Ϸǰ�����Ƕ��������ȡһ����λ�����ֶ����ظ���4λ��,��1234;\n");
	printf("2.ÿ�β²���������ݶ��������Ƶ���ʾ*A*B;\n");
	printf("3.����Aǰ��*�����β¶��˶��ٸ����֣�Bǰ��*�����βŶԵ����ֲ���λ����ȷ��������Ŀ;\n");
	games();
	return 0;
}
