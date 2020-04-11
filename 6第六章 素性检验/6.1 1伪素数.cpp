#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
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

	int n;
	n=23*47;
	int b;
	for(b=0;b<n;b++)
	{
		if(bemodn(b,n-1,n)==1)cout<<b<<",";
	}
	
	return 0;
}
 
