#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//using namespace std;
char *compress(char *str)
{
int count=1;
if(str == NULL)
	return NULL;

char last=str[0];
int len=strlen(str);
char s[2]={0};
int index=0;
char *newstr=new char[2*len];
for(int i=1;i<len;i++)
	{
	if(last == str[i])
		{
		count++;
		}
	else
		{
		newstr[index]=last;
		sprintf(s,"%d",count);
		strcat(newstr,s);
		index=index+2;
		//newstr[index]=s;
		last=str[i];
		count=1;
		}
	
	
	}
newstr[index]=last;
sprintf(s,"%d",count);
strcat(newstr,s);

std::cout<<"\nCompressed"<<newstr<<"\n";
}
main()
{
char a[10]="aabbbbbcc";
compress(a);
}


