//ģ�⶷��������

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

void sent ()
{
	int sum[16] = {0};//sum�������ڼ�¼ÿ���Ƶ����� 
	int color[16][5] = {0};//��¼ÿ������Ļ�ɫ��Ϣ 
	
	char *a = "����"; 
	char *b = "����"; 
	char *c = "÷��"; 
	char *d = "����"; 
	
	bool flag;//�Ƿ�Ϊ��Ч���� 
	
	for(int i=0; i<3; i++)//���ȸ�ÿһλ����������� 
	{
		printf("���%d: ",i+1);
		
		int total=0;
		
		while(total<17)//��һ������Լ�����������Ϣ 
		{
			flag = false;

			while(flag==false)
			{
				
				int ret = rand() % 15 + 1;//����1-15֮��������������14����С����15�������  
			
				if(ret == 14 || ret == 15)//��С��ֻ��һ�� 
				{
					if(sum[ret] == 0)
					{
						sum[ret] = sum[ret] + 1;
					
						if(ret == 14)
							printf("С�� ");
						else
							printf("���� ");
							
						total++;
						flag = true;//��Ч����
					}
				}
			
				else
				{
					if(sum[ret]<4)
					{
					 
						int color_rand = rand() % 4 + 1;//���ɻ�ɫ��Ϣ��1������ҡ�2������ҡ�3����÷����4������
						
						if(color[ret][color_rand] == 0)//��Ч����
						{
							color[ret][color_rand] = color[ret][color_rand] + 1;
							sum[ret] = sum[ret] + 1;
							
							if(color_rand==1)
								printf("%s_%d ",a,ret); 
								
							if(color_rand==2)
								printf("%s_%d ",b,ret); 
								
							if(color_rand==3)
								printf("%s_%d ",c,ret);
								
							if(color_rand==4)
								printf("%s_%d ",d,ret); 
							
							total++;
							flag = true;//��Ч����
						}
							
					}
				}
				

			}
		}
		printf("\n");
	}
	
	printf("����: ");
		
		int total=0;
		
		while(total<3)//�������Լ�����������Ϣ 
		{
			flag = false;

			while(flag==false)
			{
				
				int ret = rand() % 15 + 1;//����1-15֮��������������14����С����15�������  
			
				if(ret == 14 || ret == 15)//��С��ֻ��һ�� 
				{
					if(sum[ret] == 0)
					{
						sum[ret] = sum[ret] + 1;
					
						if(ret == 14)
							printf("С�� ");
						else
							printf("���� ");
							
						total++;
						flag = true;//��Ч����
					}
				}
			
				else
				{
					if(sum[ret]<4)
					{
					 
						int color_rand = rand() % 4 + 1;//���ɻ�ɫ��Ϣ��1������ҡ�2������ҡ�3����÷����4������
						
						if(color[ret][color_rand] == 0)//��Ч����
						{
							color[ret][color_rand] = color[ret][color_rand] + 1;
							sum[ret] = sum[ret] + 1;
							
							if(color_rand==1)
								printf("%s_%d ",a,ret); 
								
							if(color_rand==2)
								printf("%s_%d ",b,ret); 
								
							if(color_rand==3)
								printf("%s_%d ",c,ret);
								
							if(color_rand==4)
								printf("%s_%d ",d,ret); 
							
							total++;
							flag = true;//��Ч����
						}
							
					}
				}
				
			}
		}
		printf("\n");

}

int main()
{
	
	for(int i=1; i<=5; i++)//����5�ַ��� 
	{ 
		printf("��%d�η��ƽ��Ϊ: \n",i);
		sent();
		 
	} 
	return 0;
 } 
