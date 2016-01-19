#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//用来形成一张牌，用字符数组装数据（ch[0]->花色，ch[1]->点数）  
//n是范围是1-54的随机数 
//返回字符指针 
char *Print(int n);
//发牌函数
void m(); 

char *Print(int n)        //分解n构成ch[0],ch[1] 
{                  
	int Huase,Dian;
	char ch[10],c;
	Huase=n/13+1;    //其范围是1-4，代表花色 
	Dian=n%13;       //其范围是0-12，代表点数     
	if(Dian==10)     //点数是10,11,12,13的要特殊考虑 
    c='+';
    else if(Dian==11)
    c='J';
    else if(Dian==12)
    c='Q';
    else if(Dian==0)
    c='K';
    else 
    c=char (Dian+'0');  //实现数字n->字符n（n范围是1-9） 
    

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
	else if(Huase==1)  //黑桃 
	{
		ch[0]=6;
		ch[1]=c;
	}
	else if(Huase==2)  //红桃 
	{
		ch[0]=5;
		ch[1]=c;
	}
	else if(Huase==3)  //棉花 
	{
		ch[0]=4;
		ch[1]=c;
	}
	else if(Huase==4)  //方块 
	{
	    ch[0]=3;
		ch[1]=c;
	}
	ch[2]='\0';        //字符串结束符号 
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
	int vis[55]={0};       //用vis[n]=0代表，第n张牌已经发过 
	char *ch;
	srand((unsigned)time(NULL));
	while(t!=54)           //发54张牌 
	{
	
		k=rand()%54+1;
		if(vis[k]==0)
		{
			ch=Print(k);        //构造牌的数据 
			if(t%12==0&&t<48)
			{
			cout<<ss<<':';
			ss++;
		    }
			cout<<ch<<" ";
			vis[k]=1;
			t++;             //计数器，记已发的牌数 
			if(t%12==0&&t!=0) 
			cout<<endl; 			
		}
		else
		continue; 
	}
	cout<<endl;
}
