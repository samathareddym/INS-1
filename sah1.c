#include<stdio.h>
#include<string.h>
#define N strlen(g)
void crc();
void xor();
char g[20];
char text[100];
char code[100];
int len;
int main(){
		int i,flag=0;
		printf("\n enter the message in library form");
		scanf("%s",text);
		printf("\n enter the generator number");
		scanf("%s",g);
		len=strlen(text);
		for(i=len;i<len+N-1;i++)
		{
			text[i]='0';
		}
		crc();
		for(i=len;i<len+N-1;i++)
		{
			text[i]=code[i-len];
		}
		printf("\nFinal codeword is : %s\n",text);
		printf("\nenter the coded word");
		scanf("%s",text);
		crc();
		for(i=0;i<strlen(code);i++)
		{
			if(code[i]=='1')
			{
				flag=1;
				break;
			}
		}
	if(flag==1)
	{
		printf("\nerror\n");
	}
	else
	{
		printf("\n no error\n");
	}
	return 0;
}

void crc()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		code[i]=text[i];
	}
	do
	{
		if(code[0]=='1')
		{
			xor();
		}
		for(j=0;j<N-1;j++)
		{
			code[j]=text[j+1];
		}
		code[j]=text[i];
		i++;
	}while(i<=len+N-1);
}
void xor()
{
	int i;
	for(i=0;i<N;i++)
	{
		if(code[i]==g[i])
		{
			code[i]='0';
		}
		else{
			code[i]='1';
		}
	}
}
	
	





