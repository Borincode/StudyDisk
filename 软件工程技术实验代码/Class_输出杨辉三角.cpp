//�������// 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int lengh;//�û��������� 
	int n=1;
	
	printf("������������"); 
	scanf("%d",&lengh);
	
	int *p2=(int *)malloc(lengh);//p2���鸺��̳�p������p1��������ݣ����ڼ����µ�һ������ 
	p2[0]=1;
	p2[1]=1;
	
//	��ѡ�����ǰ���У��ӵ����п�ʼ����(��p2�̳�p1��������) 
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
				if(i==0||i==n-1)//ֱ�����ÿһ�е���Ԫ�غ�βԪ�� 
					p1[i]=1;
				else
					p1[i]=p2[i-1]+p2[i];//�����м�Ԫ�� 
				
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
