/*�� ii) ���� m = 199, ���� c = m^e mod n;  �ټ��� m' = c^d mod n. ���Ƚ� m' �� m.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long c, e, n,d,mm,d1;
    c=1223394;
    d=3337073;
    n=2011*2017;
    long long a=1,b;
    b=c;
    d1=d;
    int tag=0,n0;
    while(d1!=0)
    {
    	d1=d>>tag;
    	n0=d1%2;
    	if(n0==1)
    	{
    		a=a*b;
    		a=a%n;
		}
		b=((b%n)*(b%n))%n;
    	printf("n%d=%d, a%d=%lld, b%d=%lld (mod %ld)\n",tag,n0,tag,a,tag,b,n);
    	tag++;
	}

    return 0;
} 
