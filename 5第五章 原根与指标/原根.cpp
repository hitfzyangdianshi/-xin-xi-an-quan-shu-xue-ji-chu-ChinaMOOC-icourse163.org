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

int eular(int n)
{
    int res=n;
    for(int i=2;i<=sqrt(n);i++)//判断n是否为质数
    {
        if(n%i==0)res=res/i*(i-1);//res=res*(1-1/i)先进行除法防止溢出 
        while(n%i==0)n/=i;
    }
    if(n>1)res=res/n*(n-1);
    return res;
}


int main(int argc, char **argv)
{
main_begin:	
	int n,i,phigroup[100]={1};
	cin>>n;
	cout<<"a\tord_p(a)==phi(m)"<<endl<<"模"<<n<<"的所有遍历原根为："; 
	for(i=1;i<n;i++)
	{
		if(gcd(n,i)==1)
		{
			int orda=ord_a(n,i);
			if(orda==eular(n))
				cout<<i<<",";
		}
	}
	cout<<endl<<endl;
	goto main_begin;
	return 0;	
}
