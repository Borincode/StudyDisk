//杨辉三角// 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int lengh;//用户输入行数 
	int n=1;
	
	printf("请输入行数："); 
	scanf("%d",&lengh);
	
	int *p2=(int *)malloc(lengh);//p2数组负责继承p下文内p1数组的内容，用于计算新的一行数据 
	p2[0]=1;
	p2[1]=1;
	
//	先选择输出前两行，从第三行开始计算(用p2继承p1数组内容) 
	while(n<=lengh)
	{
		if(n==1)
			printf("1 \n");
		
		
		else if(n==2)
			printf("1 1\n");
		
		
		else
		{
			int *p1=(int *)malloc(n);
			
			for(int i=0;i<n;i++)
			{
				if(i==0||i==n-1)//直接输出每一行的首元素和尾元素 
					p1[i]=1;
				else
					p1[i]=p2[i-1]+p2[i];//计算中间元素 
				
			}
		
			
			for(int i=0;i<n;i++)
			{
				printf("%d ",p1[i]);
				p2[i]=p1[i]; 
				
			}
			
			printf("\n");
			
		}
		
		n++;
	}
	return 0;
	 
} 
