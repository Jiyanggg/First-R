#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void m();
char *Print(int n)
{
	int i,j;
	char ch[10],c;
	i=n/13+1;
	j=n%13;
	
	if(j==10)
    c='+';
    else if(j==11)
    c='J';
    else if(j==12)
    c='Q';
    else if(j==13)
    c='K';
    else 
    c=char (j+'0');
    

	if(n==53)
	{
		ch[0]='X';
		ch[1]='W';
	}
	else if(n==54)
	{
		ch[0]='D';
		ch[1]='W';
	}
	else if(i==1)
	{
		ch[0]=3;
		ch[1]=c;
	}
	else if(i==2)
	{
		ch[0]=6;
		ch[1]=c;
	}
	else if(i==3)
	{
		ch[0]=5;
		ch[1]=c;
	}
	else if(i==4)
	{
	    ch[0]=4;
		ch[1]=c;
	}
	ch[2]='\0';
	return ch;
	
}
int main()
{
	char ch;
	do
	{   cout<<"发牌:"<<endl;
		m();
		cout<<"停止发牌请按0，否则按其他键（等待一秒）"<<endl;
		cin>>ch; 
	}while(ch!='0');
} 
void m()
{
	int i,j,k,t=0,ss=1;
	int vis[55]={0};
	char *ch;
	srand((unsigned)time(NULL));
	while(t!=54)
	{
	
		k=rand()%54+1;
		if(vis[k]==0)
		{
			ch=Print(k);
			if(t%12==0&&t<48)
			{
			cout<<ss<<':';
			ss++;
		    }
			cout<<ch<<" ";
			vis[k]=1;
			t++;
			if(t%12==0&&t!=0)
			cout<<endl; 
			
		}
		else
		continue; 
	}
	cout<<endl;
}
