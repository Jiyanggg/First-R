#include<iostream>
#include<time.h> 
#include<stdlib.h>
using namespace std;
struct puke
{
	char color;
	char num;
};//每张牌的花色和数字
void m();//发牌函数 
int main()
{
	char ch;
	do
	{   cout<<"发牌:";
		m();
		cout<<"停止发牌请按0，否则按其他键（等待一秒）"<<endl;
		cin>>ch; 
	}while(ch!='0');
		
}                                 
void m()
{
///////////////////////////////////////////////////////	
///////////用来给结构体数组pk[54]赋值//////////////////	
	srand((unsigned)time(NULL));    //产生随机数的种子 
	int i,j,t=1,ss,tt=0,person=1;
	char co=6,nn;                   //co=6,ascll码为6的字符模拟“黑桃” 
    struct puke pk[55];             //1-54张牌 
    for(i=0;i<4;i++)                //用双重for来给pk[]赋值(大王小王单独赋值） 
    {                                
    	for(j=0;j<=12;j++)
    	{
		    nn='1';        
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
			pk[t].color=co;       //给花色赋值          
    		pk[t].num=nn;         //给点数赋值 
    		t++;
		}
		co--;                     //改变当前花色 
	}
	pk[t].color='X';
	pk[t++].num='W';
	pk[t].color='D';
	pk[t].num='W';
	cout<<endl;
///////////////////////////////////////////////////////	
///////用来输出54张牌及格式控制////////////////////////	
	while(tt!=54)
	{
	
		ss=1+rand()%54;                    //产生随机数ss->pk[ss]->牌 （ss的范围是1-54） 
		if(pk[ss].color=='N')              //判断这张牌是否被"发过"   
		continue;
		else
		{
			if(tt==0||tt==12||tt==24||tt==36)
			{
				cout<<person<<":"; 
				person++;
			}
			cout<<pk[ss].color<<pk[ss].num<<"  "; //"发牌" 
			pk[ss].color='N';                     //标记"发过"的牌 
			tt++;                                 //计数器，记已发过的牌数     
		}
		if(tt%12==0)                      //每个人12张牌 
		{
			cout<<endl;
		}
	}
	cout<<endl;		
} 
