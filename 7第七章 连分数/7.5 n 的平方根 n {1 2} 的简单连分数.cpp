#include<bits/stdc++.h>
using namespace std;
//***1/double之后如果是整数，取整有问题，慎用。
//#define PI acos(-1.0)
#define PI 3.1415926535897932385
#define e1 exp(1)

__int64 bemodn(__int64 b, __int64 e, __int64 n)
{
	__int64 b0=b;
	__int64 i;
	b0=b0%n;
	for(i=2;i<=e;i++)
	{
		b0=b0*(b%n);
		b0=b0%n;
	}
	return b0;	
}


int main(int argc, char **argv)
{
//	cout<<"i\ta_i\tx_i\tP_i\tQ_i"<<endl;
	cout<<"k\tP_k\tP_k^2 mod n"<<endl;
	int n0=2011*2017;
	double n=2013.9977656393;//=sqrt(n0);
	__int64 a[100],P[102],Q[102];
	int i;
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
		//if(P[i-1]>n0)P[i-1]=P[i-1]%n0;
		cout<<i-1<<"\t"<<P[i-1]%n0<<"\t"<<bemodn(P[i-1],2,n0)<<endl;
		if(fabs(x[i-1]-0)<=1e-9)break;
		a[i]=floor(1.0/x[i-1]);
		x[i]=1.0/x[i-1]-a[i];
	}
	
	
	return 0;
}
