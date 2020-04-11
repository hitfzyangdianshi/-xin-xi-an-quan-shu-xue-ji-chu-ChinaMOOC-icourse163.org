//最小正简化剩余系各元素的指数
#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}

inline long xy(int x,long y)
{
	if(y==1)return x;
	else return x*xy(x,y-1);
}

long ord_a(int m, int a)
{
	long e;
	int a0=a;
	for(e=1;;e++)
	{
		//if(xy(a,e)%m==1)return e;
		if( a%m==1 )return e;
		else 
		{
			a=a	%m;
			a=a*a0;
		}	
	}
}

int main(int argc, char** argv)
{
	int n,i,phigroup[100]={1};
	cin>>n;
	cout<<"a\tord_p(a)"<<endl; 
	for(i=1;i<n;i++)
	{
		if(gcd(n,i)==1)
		{
			cout<<i<<"\t"<<ord_a(n,i)<<endl;
		}
	}
	
	return 0;	
}
