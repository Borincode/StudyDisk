//模拟斗地主发牌

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

void sent ()
{
	int sum[16] = {0};//sum数组用于记录每张牌的数量 
	int color[16][5] = {0};//记录每张牌面的花色信息 
	
	char *a = "黑桃"; 
	char *b = "红桃"; 
	char *c = "梅花"; 
	char *d = "方块"; 
	
	bool flag;//是否为有效发牌 
	
	for(int i=0; i<3; i++)//首先给每一位玩家轮流发牌 
	{
		printf("玩家%d: ",i+1);
		
		int total=0;
		
		while(total<17)//给一个玩家以及生成牌面信息 
		{
			flag = false;

			while(flag==false)
			{
				
				int ret = rand() % 15 + 1;//生成1-15之间的随机数，其中14代表小王、15代表大王  
			
				if(ret == 14 || ret == 15)//大小王只有一张 
				{
					if(sum[ret] == 0)
					{
						sum[ret] = sum[ret] + 1;
					
						if(ret == 14)
							printf("小王 ");
						else
							printf("大王 ");
							
						total++;
						flag = true;//有效发牌
					}
				}
			
				else
				{
					if(sum[ret]<4)
					{
					 
						int color_rand = rand() % 4 + 1;//生成花色信息，1代表黑桃、2代表红桃、3代表梅花、4代表方块
						
						if(color[ret][color_rand] == 0)//有效发牌
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
							flag = true;//有效发牌
						}
							
					}
				}
				

			}
		}
		printf("\n");
	}
	
	printf("底牌: ");
		
		int total=0;
		
		while(total<3)//给底牌以及生成牌面信息 
		{
			flag = false;

			while(flag==false)
			{
				
				int ret = rand() % 15 + 1;//生成1-15之间的随机数，其中14代表小王、15代表大王  
			
				if(ret == 14 || ret == 15)//大小王只有一张 
				{
					if(sum[ret] == 0)
					{
						sum[ret] = sum[ret] + 1;
					
						if(ret == 14)
							printf("小王 ");
						else
							printf("大王 ");
							
						total++;
						flag = true;//有效发牌
					}
				}
			
				else
				{
					if(sum[ret]<4)
					{
					 
						int color_rand = rand() % 4 + 1;//生成花色信息，1代表黑桃、2代表红桃、3代表梅花、4代表方块
						
						if(color[ret][color_rand] == 0)//有效发牌
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
							flag = true;//有效发牌
						}
							
					}
				}
				
			}
		}
		printf("\n");

}

int main()
{
	
	for(int i=1; i<=5; i++)//进行5轮发牌 
	{ 
		printf("第%d次发牌结果为: \n",i);
		sent();
		 
	} 
	return 0;
 } 
