#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}

inline int xy(int x,int y)
{
	if(y==0)return 1;
	else if(y==1)return x;
	else return x*xy(x,y-1);
}

bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return false;
	}
	return true;
}

long bemodn(int b, int e, int n)
{
	long b0=b;
	int i;
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
	int n=23*47,b,numberfakeprime=0;
	for(b=0;b<n;b++)
	{
		//if(gcd(b,n)!=1)continue; // ?根据教材，设b与n互素) 
	//	cout<<"Jacobi("<<b<<","<<n<<")="<<Jacobi(b,n)<<",\tb^((n-1)/2) mod n="<<bemodn(b,(n-1)/2,n);
	//	if(Jacobi(b,n)==bemodn(b,(n-1)/2,n)){cout<<"\t n为基b的Euler伪素数";    numberfakeprime++;}
		cout<<"b="<<b<<"\tb^(n-1) mod n="<<bemodn(b,(n-1)/2,n);
		cout<<endl;
	}
	cout<<"\n\n";
	for(b=0;b<n;b++)
	{
		if(gcd(b,n)!=1)continue;
		int n1=n-1;
		while(n1%2==0)
		{
			n1=n1/2;
			if(n1%2==0)continue;
			if(bemodn(b,n1,n)==1)
			{
				cout<<"b="<<b<<",t="<<n1<<endl;
				numberfakeprime++;
				break;
			}
			int s;
			for(s=1;;s++)
			{
				if(xy(2,s)==(n-1)/n1)break;
			}
			for(int r=0;r<s;r++)
			{
				if(bemodn(b,xy(2,r)*n1,n)==n-1)
				{
					cout<<"b="<<b<<",r="<<r<<",t="<<n1<<",s="<<s<<endl;
					numberfakeprime++;
					break;
				}
			}
		}
			
	}
	
	 
	cout<<endl<<numberfakeprime;
	return 0;
}


