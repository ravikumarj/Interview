#include<iostream>
#include<string.h>
using namespace std;
void replace(char *a)
{
//scan to count number of white spaces
int count=0;
int len=strlen(a);
int i=0;
for(i=0;i<len;i++)
	{
	if(a[i]==' ' )
		{
		count++;
		}
	}
int newsize=len+count*2;
char *newstr=new char[newsize];
newstr[newsize]='\0';
cout<<"\nNew size"<<newsize;
i=len-1;
while(i>=0)
	{
	if(a[i]==' ')
		{
		newstr[newsize-1]='0';
		newstr[newsize-2]='2';
		newstr[newsize-3]='%';
		newsize=newsize-3;
		i--;
		}
	else
		{
		newstr[newsize-1]=a[i];
		i--;
		newsize=newsize-1;
		}
	}

cout<<"\nReplace Str"<<newstr<<endl;
}
main()
{
char a[30]="aaa bb cc";
replace(a);
}

	
