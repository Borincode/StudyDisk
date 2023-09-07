//判断IPv4/IPv6/MAC地址是否合法 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IPV4 "IPv4"
#define IPV6 "IPv6"
#define NEITHER "Neither"
#define False 0
#define True 1

int checkIPV4(char *ip)
{
	int sepNum;
	if((ip[0] == '0'&&ip[1]!=0)|| ip[0] == '.' || strlen(ip) > 3 || strlen(ip) == 0)
	{
		if(ip[0] == '0')
			printf("首位不应为0"); 
		else if(ip[0] == '.')
			printf("首位不应为.");
		else if(strlen(ip) > 3)
			printf("长度超出限制");
		else
			printf("不应为0"); 
			
		return False;
	}
	
	sepNum = atoi(ip);
	
	if(sepNum > 255)
	{
		printf("超出255");
		return False; 
	}
	return True;
}

int checkIPV6(char *ip)
{
	int i=0;
	
	if(ip[0] == ':' || strlen(ip) > 4 || strlen(ip) == 0)
	{
		if (ip[0] == ':')
			printf("首位不应为:");
			
		else if(strlen(ip) > 4)
			printf("长度超出范围");
			
		else
			printf("长度不应为0"); 
			
		return False;
	}

		
	for(i=0;i<strlen(ip);i++)
	{
		if((ip[i] >='0' && ip[i] <='9') || (ip[i] >='a' && ip[i] <='f') || (ip[i] >='A' && ip[i] <='F'))
			continue;
		else
		{
			printf("超出16进制范围！");
			return False;
		}
	}
	return True;
}

int checkMAC(char *ip)
{
	int i=0;
	
	if(ip[0] == ':' || strlen(ip) > 2 || strlen(ip) == 0)
	{
		if (ip[0] == ':')
			printf("首位不应为':'");
			
		else if(strlen(ip) > 2)
			printf("长度超出范围");
			
		else
			printf("长度不应为0"); 
			
		return False;
	}

		
	for(i=0;i<strlen(ip);i++)
	{
		if((ip[i] >='0' && ip[i] <='9') || (ip[i] >='a' && ip[i] <='f') || (ip[i] >='A' && ip[i] <='F'))
			continue;
		else
		{
			printf("超出16进制范围！");
			return False;
		}
	}
	return True;
}

char *solveIP(char *IP)
{
	if(IP == NULL)
		return "错误的IPv4地址";
	char *cur,*pre;
	char ip[10] = {0};
	char len = 0;

	if(strchr(IP,'.'))
	{
		pre = IP;
		cur = strchr(IP,'.');    //找到'.'的位置
		while(cur)
		{
			memcpy(ip,pre,cur-pre);    //取出两个'.'之间的字符
			if(checkIPV4(ip) == False)
			{
				printf("！第%d组出现问题",len+1); 
				return "错误的IPv4地址";
			}
			pre = cur + 1;
			cur = strchr(pre,'.');
			memset(ip,0,10);
			len++;
			
			if(len > 3)        //判断分组是否符合ipv4要求
				return "错误的IPv4地址";
		}
		
		if(len != 3)
			return "错误的IPv4地址";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkIPV4(ip) == False)
		{
			printf("！第%d组出现问题",len+1); 
			return "错误的IPv4地址";
		}
		return IPV4;
	}
	
	else if(strchr(IP,':'))
	{
		pre = IP;
		cur = strchr(IP,':');
		while(cur)
		{
			memcpy(ip,pre,cur-pre);
			
			if(checkIPV6(ip) == False)
			{
				printf("！第%d组出现问题",len+1); 
				return "错误的IPv6地址";
			
			}
			pre = cur + 1;
			
			cur = strchr(pre,':');
			
			memset(ip,0,10);
			
			len++;
			if(len > 7)
				return "错误的IPv6地址";
		}
		
		if(len != 7)
			return "错误的IPv6地址";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkIPV6(ip) == False)
		{
			printf("！第%d组出现问题",len+1); 
			return "错误的IPv6地址";
		}
			
		return "IPv6";
	}
}

char *solveMAC(char* IP)
{
	
if(IP == NULL)
		return "错误的IPv4地址";
	char *cur,*pre;
	char ip[10] = {0};
	char len = 0;
	
	pre = IP;
	cur = strchr(IP,':');
	
	while(cur)
	{
		memcpy(ip,pre,cur-pre);
			
		if(checkMAC(ip) == False)
		{
			printf("！第%d组出现问题",len+1); 
			return "错误的MAC地址";
			
		}
			pre = cur + 1;
			
			cur = strchr(pre,':');
			
			memset(ip,0,10);
			
			len++;
			if(len > 5)
				return "错误的MAC地址";
	}
		
		if(len != 5)
			return "错误的MAC地址";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkMAC(ip) == False)
		{
			printf("！第%d组出现问题",len+1); 
			return "错误的MAC地址";
		}
			
		return "MAC";
	
}

int main()
{
	char *IP;
	char ip[100];
	int len;
	char type[5];
	
	printf("请选择输入地址类型(IP or MAC)：");
	
	scanf("%s",&type);

	
	if(strcmp(type,"IP")==0)//相等返回0，字符串1大于字符串2返回大于0， 字符串1大于字符串2返回小于0
	{
		printf("请输入IP地址：");
		scanf("%s",&ip);
		IP=ip;
		printf("\n%s\n",solveIP(IP));
	}
	
	else if(strcmp(type,"MAC")==0)
	{
		printf("请输入MAC地址：");
		scanf("%s",&ip);
		IP=ip;
		printf("\n%s\n",solveMAC(IP));
	}
	
	else
		printf("请输入正确类型！"); 

}

