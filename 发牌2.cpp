#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//�����γ�һ���ƣ����ַ�����װ���ݣ�ch[0]->��ɫ��ch[1]->������  
//n�Ƿ�Χ��1-54������� 
//�����ַ�ָ�� 
char *Print(int n);
//���ƺ���
void m(); 

char *Print(int n)        //�ֽ�n����ch[0],ch[1] 
{                  
	int Huase,Dian;
	char ch[10],c;
	Huase=n/13+1;    //�䷶Χ��1-4������ɫ 
	Dian=n%13;       //�䷶Χ��0-12���������     
	if(Dian==10)     //������10,11,12,13��Ҫ���⿼�� 
    c='+';
    else if(Dian==11)
    c='J';
    else if(Dian==12)
    c='Q';
    else if(Dian==0)
    c='K';
    else 
    c=char (Dian+'0');  //ʵ������n->�ַ�n��n��Χ��1-9�� 
    

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
	else if(Huase==1)  //���� 
	{
		ch[0]=6;
		ch[1]=c;
	}
	else if(Huase==2)  //���� 
	{
		ch[0]=5;
		ch[1]=c;
	}
	else if(Huase==3)  //�޻� 
	{
		ch[0]=4;
		ch[1]=c;
	}
	else if(Huase==4)  //���� 
	{
	    ch[0]=3;
		ch[1]=c;
	}
	ch[2]='\0';        //�ַ����������� 
	return ch;
	
}
int main()
{
	char ch;
	do
	{   cout<<"����:"<<endl;
		m();
		cout<<"ֹͣ�����밴0���������������ȴ�һ�룩"<<endl;
		cin>>ch; 
	}while(ch!='0');
} 
void m()
{
	int i,j,k,t=0,ss=1;
	int vis[55]={0};       //��vis[n]=0������n�����Ѿ����� 
	char *ch;
	srand((unsigned)time(NULL));
	while(t!=54)           //��54���� 
	{
	
		k=rand()%54+1;
		if(vis[k]==0)
		{
			ch=Print(k);        //�����Ƶ����� 
			if(t%12==0&&t<48)
			{
			cout<<ss<<':';
			ss++;
		    }
			cout<<ch<<" ";
			vis[k]=1;
			t++;             //�����������ѷ������� 
			if(t%12==0&&t!=0) 
			cout<<endl; 			
		}
		else
		continue; 
	}
	cout<<endl;
}
