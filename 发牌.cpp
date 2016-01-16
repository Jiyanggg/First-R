#include<iostream>
#include<time.h> 
#include<stdlib.h>
using namespace std;
struct puke
{
	char color;
	char num;
};//ÿ???Ļ?ɫ????
void m();
int main()
{
	char ch;
	do
	{   cout<<"???:";
		m();
		cout<<"ֹͣ??????0????????????ȴ?һ???"<<endl;
		cin>>ch; 
	}while(ch!='0');
		
 }                                 
void m()
{
	srand((unsigned)time(NULL));    //???????????
	int i,j,t=1,ss,tt=0,person=1;
	char co='A',nn;
    struct puke pk[55];             //1-54?? 
    for(i=0;i<4;i++)                //?˫?for????pk[]??ֵ(???С???????ֵ?? 
    {
    	for(j=0;j<=12;j++)
    	{
		    nn='1';
    		pk[t].color=co;
    		if(j==9)
    		nn='+';
    		else if(j==10)
    		nn='J';
    		else if(j==11)
    		nn='Q';
    		else if(j==12)
    		nn='K';
    		else
    		nn=nn+j;             
    		pk[t].num=nn;
    		t++;
		}
		co++;
	}
	pk[t].color='X';
	pk[t++].num='W';
	pk[t].color='D';
	pk[t].num='W';
	cout<<endl;
	while(tt!=54)
	{
	
		ss=1+rand()%54;                    //???????ss->pk[ss]->? ??ss?ķ?Χ?1-54?? 
		if(pk[ss].color=='N')              //??????Ƿ?????"   
		continue;
		else
		{
			if(tt==0||tt==12||tt==24||tt==36)
			{
				cout<<person<<":"; 
				person++;
			}
			cout<<pk[ss].color<<pk[ss].num<<"  "; //"???" 
			pk[ss].color='N';                     //??"????"???
			tt++;
		}
		if(tt%12==0)                      //ÿ???12?? 
		{
			cout<<endl;
		}
	}
	cout<<endl;
		
} 
