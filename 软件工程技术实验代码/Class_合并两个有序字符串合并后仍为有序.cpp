//�ϲ������ַ������ϲ���Ϊ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main_1()
{
	int a[100];
	int b[100];
	int arr[200];
	int n1,n2;
	int len1 = 0,len2 = 0;
	
	printf("����������1�ĳ���:");
	scanf("%d",&n1);
	for(int i = 0; i < n1; i++)
		scanf("%d",&a[i]);
		
	printf("����������2�ĳ���:");
	scanf("%d",&n2);
	for(int i = 0; i < n2; i++)
		scanf("%d",&b[i]);
				  
	int len = n1 + n2;
	
	for(int i = 0; i < len; i++)
	{
		if(len1 == n1)
		{
			arr[i]=b[len2];
			len2++;	
		}
		
		else if(len2 == n2)
		{
			arr[i]=a[len1];
			len1++;	
		}
		
		else if(a[len1] < b[len2])
		{
			arr[i]=a[len1];
			len1++;
		}
		
		else if(a[len1] >= b[len2])
		{
			arr[i]=b[len2];
			len2++;
		}
		
	}
	
	printf("�ϲ��������Ϊ:\n"); 
	for(int i = 0; i < len; i++)
		printf("%d ",arr[i]); 
		
	printf("\n");
}

int main_2()
{
	char a[]={'1', '3', '5', 'A', 'C', 'a'};
	char b[]={'2', '4', '6', 'B', 'd', 'e'};
	char arr[200];
	int n1,n2;
	int len1 = 0,len2 = 0;
	
	n1 = sizeof(a)/sizeof(a[0]);
	n2 = sizeof(b)/sizeof(b[0]); 
	
	printf("����1Ϊ��"); 
	for(int i = 0; i < n1; i++)
		printf("%c ",a[i]);
		
	printf("\n����2Ϊ��"); 
	for(int i = 0; i < n2; i++)
		printf("%c ",b[i]);
	
	printf("\n");
	
	int len = n1 + n2;

	
	for(int i = 0; i < len; i++)
	{
		if(len1 == n1)
		{
			arr[i]=b[len2];
			len2++;	
		}
		
		else if(len2 == n2)
		{
			arr[i]=a[len1];
			len1++;	
		}
		
		else if(a[len1] < b[len2])
		{
			arr[i]=a[len1];
			len1++;
		}
		
		else if(a[len1] >= b[len2])
		{
			arr[i]=b[len2];
			len2++;
		}
		
	}
	
	printf("\n�ϲ���:\n");
	
	for(int i = 0; i < len; i++)
		printf("%c ",arr[i]); 
}

int main()
{
	int n;
	printf("��ѡ������(1 or 2):");
 	scanf("%d",&n);
 	
 	if(n == 1)
 		main_1();
	else if(n == 2)
	 	main_2();
	else
	 	printf("����������"); 
}
