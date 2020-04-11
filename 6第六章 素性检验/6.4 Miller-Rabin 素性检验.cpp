#include<bits/stdc++.h>
using namespace std;

inline __int64 gcd(__int64 a, __int64 b)
{
	__int64 c=1;
	if(a<b)swap(a,b);
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
} 

bool isprime(__int64 n)
{
	for(__int64 i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return false;
	}
	return true;
}

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

int prime10000[1228];
void getprime10000()
{
	int i,flag=0;
	for(int n=2;n<=10000;n++)
	{
		int tag=1;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				tag=0;
				break;
			}
		}
		if(tag==1)
		{
			prime10000[flag]=n;
			flag++;
		}
	}
}


int main(int argc, char **argv)
{
    getprime10000();
	__int64 n,i;
	for(n=10000000000+17;;n=n+2)
	{
		__int64 b=1;
		__int64 r=0;
		for(i=0;i<1228;i++)
		{
			if(n%prime10000[i]==0)
			{
				cout<<n<<"\t"<<"合数"<<endl;
				r=-1;
				break;
			}
		}
		if(r==-1)continue;
		int s=0,t,n1=n-1;
		while(n1%2==0)
		{
			t=n1/2;
			n1=n1/2;
			s++;
		}
		for(int k=1;k<=50;)
		{
			b++;
			if(gcd(b,n)!=1)
			{
				cout<<n<<"\t"<<"合数"<<endl;
				break;
			}
			r=bemodn(b,t,n);
			k++;
			if(r==1 || r==n-1)
			{
			    //cout<<n<<"\t"<<"合数"<<endl;
			//	break;
				continue;
			}
			else for(__int64 j=3;j<=s+2;j++)
			{
				r=bemodn(r,2,n);
				if(r==n-1)break;
			}
			if(r==n-1)continue;	
			else break;
		}
		if(r==n-1||r==1)cout<<n<<"\t可能为质数"<<endl;
		else cout<<n<<"\t合数"<<endl;
	}
	
	return 0;
}



