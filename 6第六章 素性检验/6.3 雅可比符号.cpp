#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
/* 
inline long xy(int x,long y)
{
	if(y==0)return 1;
	if(y==1)return x;
	else return x*xy(x,y-1);
}*/

bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return false;
	}
	return true;
}

int result[100];
void factor(int n)
{
	result[0]=0;
	for(int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            result[result[0]+1]=i;
        //    printf("%d,",i);
            n/=i;
            result[0]++;
        }
	}
//	printf("a\n");
//	return result;
}

int Legendre(int a, int p)
{
	if(a%p==0)return 0;
	if(a>p )return Legendre(a-p, p);
	if(a==1)return 1;
	else if (a==-1)
	{
		if( p%4==1)return 1;
		else return -1;// p%4==3
	}
	//return xy(a,(p-1)/2)%p;
	int pi=(p-1)/2,a0=a%p;
	for(int i=2;i<=pi;i++)
	{
		a0=a0*(a%p);
		a0=a0%p;
	}
//	cout<<"\ta0"<<a0<<"\t";
	if(1%p==a0%p)return 1;
	else return -1;
}

int Jacobi(int a, int p)
{
	if(a%p==0)return 0;
	if(a>p )return Jacobi(a-p, p);
	if(gcd(a,p)>1)return 0;
	if(a==1)return 1;
	if(isprime(p)==true)return Legendre(a,p);
	else if(a==-1)
	{
		if( ((p-1)/2)%2==0 )return 1;
		else return -1;
	}
	else if(a==2)
	{
		if( ((p*p-1)/8)%2==0 )return 1;
		else return -1;
	}
	factor(p);
	int total=1;
//	cout<<"check***\n";
	for(int i=1;i<=result[0];i++)
	{
		total=total*Legendre(a,result[i]);
	//	cout<<total<<",";
	}
	return total;
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
		if(gcd(b,n)!=1)continue; // ?(b=0时二者也可能相等，但是根据教材，Euler 伪素数要求b与n互素) 
		cout<<"Jacobi("<<b<<","<<n<<")="<<Jacobi(b,n)<<",\tb^((n-1)/2) mod n="<<bemodn(b,(n-1)/2,n);
		if(Jacobi(b,n)==bemodn(b,(n-1)/2,n)){cout<<"\t n为基b的Euler伪素数";    numberfakeprime++;}
		cout<<endl;
	}
	cout<<numberfakeprime;
	return 0;
}


