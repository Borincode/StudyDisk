//�ж�IPv4/IPv6/MAC��ַ�Ƿ�Ϸ� 
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
			printf("��λ��ӦΪ0"); 
		else if(ip[0] == '.')
			printf("��λ��ӦΪ.");
		else if(strlen(ip) > 3)
			printf("���ȳ�������");
		else
			printf("��ӦΪ0"); 
			
		return False;
	}
	
	sepNum = atoi(ip);
	
	if(sepNum > 255)
	{
		printf("����255");
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
			printf("��λ��ӦΪ:");
			
		else if(strlen(ip) > 4)
			printf("���ȳ�����Χ");
			
		else
			printf("���Ȳ�ӦΪ0"); 
			
		return False;
	}

		
	for(i=0;i<strlen(ip);i++)
	{
		if((ip[i] >='0' && ip[i] <='9') || (ip[i] >='a' && ip[i] <='f') || (ip[i] >='A' && ip[i] <='F'))
			continue;
		else
		{
			printf("����16���Ʒ�Χ��");
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
			printf("��λ��ӦΪ':'");
			
		else if(strlen(ip) > 2)
			printf("���ȳ�����Χ");
			
		else
			printf("���Ȳ�ӦΪ0"); 
			
		return False;
	}

		
	for(i=0;i<strlen(ip);i++)
	{
		if((ip[i] >='0' && ip[i] <='9') || (ip[i] >='a' && ip[i] <='f') || (ip[i] >='A' && ip[i] <='F'))
			continue;
		else
		{
			printf("����16���Ʒ�Χ��");
			return False;
		}
	}
	return True;
}

char *solveIP(char *IP)
{
	if(IP == NULL)
		return "�����IPv4��ַ";
	char *cur,*pre;
	char ip[10] = {0};
	char len = 0;

	if(strchr(IP,'.'))
	{
		pre = IP;
		cur = strchr(IP,'.');    //�ҵ�'.'��λ��
		while(cur)
		{
			memcpy(ip,pre,cur-pre);    //ȡ������'.'֮����ַ�
			if(checkIPV4(ip) == False)
			{
				printf("����%d���������",len+1); 
				return "�����IPv4��ַ";
			}
			pre = cur + 1;
			cur = strchr(pre,'.');
			memset(ip,0,10);
			len++;
			
			if(len > 3)        //�жϷ����Ƿ����ipv4Ҫ��
				return "�����IPv4��ַ";
		}
		
		if(len != 3)
			return "�����IPv4��ַ";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkIPV4(ip) == False)
		{
			printf("����%d���������",len+1); 
			return "�����IPv4��ַ";
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
				printf("����%d���������",len+1); 
				return "�����IPv6��ַ";
			
			}
			pre = cur + 1;
			
			cur = strchr(pre,':');
			
			memset(ip,0,10);
			
			len++;
			if(len > 7)
				return "�����IPv6��ַ";
		}
		
		if(len != 7)
			return "�����IPv6��ַ";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkIPV6(ip) == False)
		{
			printf("����%d���������",len+1); 
			return "�����IPv6��ַ";
		}
			
		return "IPv6";
	}
}

char *solveMAC(char* IP)
{
	
if(IP == NULL)
		return "�����IPv4��ַ";
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
			printf("����%d���������",len+1); 
			return "�����MAC��ַ";
			
		}
			pre = cur + 1;
			
			cur = strchr(pre,':');
			
			memset(ip,0,10);
			
			len++;
			if(len > 5)
				return "�����MAC��ַ";
	}
		
		if(len != 5)
			return "�����MAC��ַ";
			
		memcpy(ip,pre,strlen(pre));
		
		if(checkMAC(ip) == False)
		{
			printf("����%d���������",len+1); 
			return "�����MAC��ַ";
		}
			
		return "MAC";
	
}

int main()
{
	char *IP;
	char ip[100];
	int len;
	char type[5];
	
	printf("��ѡ�������ַ����(IP or MAC)��");
	
	scanf("%s",&type);

	
	if(strcmp(type,"IP")==0)//��ȷ���0���ַ���1�����ַ���2���ش���0�� �ַ���1�����ַ���2����С��0
	{
		printf("������IP��ַ��");
		scanf("%s",&ip);
		IP=ip;
		printf("\n%s\n",solveIP(IP));
	}
	
	else if(strcmp(type,"MAC")==0)
	{
		printf("������MAC��ַ��");
		scanf("%s",&ip);
		IP=ip;
		printf("\n%s\n",solveMAC(IP));
	}
	
	else
		printf("��������ȷ���ͣ�"); 

}

