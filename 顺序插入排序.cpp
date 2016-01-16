#include<iostream>
using namespace std;
int main()
{
	int i=0,k=0,j;
	int a[20];
	cout<<"请输入十个数字，我将为你排序：";
	for(i=1;i<=10;i++)
	{
		cin>>a[i];
	}
	for(j=2;j<=10;j++)
	{
		if(a[j]<a[j-1])
		{
		a[0]=a[j];
	    k=j-1;
		while(a[0]<a[k])
	    {
		   a[k+1]=a[k];
		   k--;
	    }
		a[k+1]=a[0];
      	}
	} 
	cout<<endl;
	for(i=1;i<=10;i++)
	cout<<a[i]<<endl;
	return 0;
 } 
