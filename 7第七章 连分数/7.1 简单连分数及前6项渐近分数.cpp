/*求 $(5^{1/2}+1)/2$ 的简单连分数及前6项渐近分数
求圆周率 $\pi$ 的简单连分数及前6项渐近分数
求自然对数底 $e$ 的简单连分数及前6项渐近分数
求有理分数 $20190122/2017$ 的简单连分数及前6项渐近分数*/
#include<bits/stdc++.h>
using namespace std;
//***1/double之后如果是整数，取整有问题，慎用。只用这个程序算pi和e的演示。 
//#define PI acos(-1.0)
#define PI 3.1415926535897932385
#define e exp(1)

int main(int argc, char **argv)
{
	cout<<"i\ta_i\tx_i\tP_i\tQ_i"<<endl;
	double n=sqrt(2011*2017);
	n=2013.9977656393;
	__int64 a[100],P[102],Q[102],i;
	long double x[100];
	a[0]=floor(n);
	x[0]=n-a[0];
	for(i=1;i<100;i++)
	{
		if(i-1==0){
			P[i-1]=a[i-1]*1+0;
			Q[i-1]=a[i-1]*0+1;
		}
		else if(i-1==1){
			P[i-1]=a[i-1]*P[i-2]+1;
			Q[i-1]=a[i-1]*Q[i-2]+0;
		}
		else{
			P[i-1]=a[i-1]*P[i-2]+P[i-3];
			Q[i-1]=a[i-1]*Q[i-2]+Q[i-3];
		}
		cout<<i-1<<"\t"<<a[i-1]<<"\t"<<x[i-1]<<"\t"<<P[i-1]<<"\t"<<Q[i-1]<<endl;
		if(fabs(x[i-1]-0)<=1e-9)break;
		a[i]=floor(1.0/x[i-1]);
		x[i]=1.0/x[i-1]-a[i];
	}
	
	
	return 0;
}
