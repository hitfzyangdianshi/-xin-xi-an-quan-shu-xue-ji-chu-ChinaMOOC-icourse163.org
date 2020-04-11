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

__int64 result[9000000];
void factor(__int64 n)
{
	result[0]=0;
	for(__int64 i=2;i<=n;i++)
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

bool isprime(__int64 n)
{
	for(__int64 i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return false;
	}
	return true;
}

inline int Legendre(__int64 a, __int64 p)
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
	for(__int64 i=2;i<=pi;i++)
	{
		a0=a0*(a%p);
		a0=a0%p;
	}
//	cout<<"\ta0"<<a0<<"\t";
	if(1%p==a0%p)return 1;
	else return -1;
}

inline int Jacobi(__int64 a, __int64 p)
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
	for(__int64 i=1;i<=result[0];i++)
	{
		total=total*Legendre(a,result[i]);
	//	cout<<total<<",";
	}
	return total;
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
		for(int t=1;t<=50;)
		{
			b++;
			if(gcd(b,n)!=1)
			{
				cout<<n<<"\t"<<"合数"<<endl;
				break;
			}
			r=bemodn(b,n-1,n);
			t++;
			if(r!=1 && r!=n-1)
			{
			    cout<<n<<"\t"<<"合数"<<endl;
				break;
			}
			int s=Jacobi(b,n);
			if(r!=s)
			{
			    cout<<n<<"\t"<<"合数"<<endl;
				break;
			}
		}
		if(r==1)cout<<n<<"\t可能是质数"<<endl;
	}
	
	return 0;
}



