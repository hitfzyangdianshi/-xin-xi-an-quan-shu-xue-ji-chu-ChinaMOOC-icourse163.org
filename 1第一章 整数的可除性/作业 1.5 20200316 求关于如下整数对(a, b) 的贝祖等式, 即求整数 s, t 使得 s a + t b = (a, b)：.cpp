/*作业 1.5 20200316
求关于如下整数对(a, b) 的贝祖等式, 即求整数 s, t 使得 s a + t b = (a, b)：

1)  (166, 332). 

2) (984, 1038).

3) (1124, 1213).

4) (1281, 2019).

5) (1338, 2018).*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

int div_gauss (int a, int b)
{
	int c;
	c=a/b;
	if(c<0 && a%b!=0)return c-1;
	return c;
}

int *bezout(int a, int b)
{
	int s[100],t[100],rr[110],r[100],q[100],j;
	//r_-2 = a, r_-1 =b, (s t)_-2 = (1,0), (s,t)_-1 = (0,1) 
	memset(r,-1,sizeof(r));
	q[0]=div_gauss(a,b);
	r[0]=-q[0]*b+a;
	for(j=0;;j++)
	{
        if(j-2>=0)
		{
		    s[j]=(-q[j])*(s[j-1])+s[j-2];
		    t[j]=(-q[j])*(t[j-1])+t[j-2];
		    q[j+1]=div_gauss(r[j-1],r[j]);//q[j+1]=r[j-1]/r[j];
		    r[j+1]=(-q[j+1])*r[j]+r[j-1];
		}
        else if(j==0)
		{
    		s[j]=(-q[j])*(0)+1;
        	t[j]=(-q[j])*(1)+0;
			q[j+1]=div_gauss(b,r[j]);//q[j+1]=b/r[j];
			r[j+1]=(-q[j+1])*r[j]+b;
        }
        else if (j==1)
        {
        	s[j]=(-q[j])*(s[j-1])+0;
		    t[j]=(-q[j])*(t[j-1])+1;
		    q[j+1]=div_gauss(r[j-1],r[j]);//q[j+1]=r[j-1]/r[j];
		    r[j+1]=(-q[j+1])*r[j]+r[j-1];
		}
        if(r[j+1]==0)
       	{
        	cout<<s[j]<<"\t"<<t[j]<<endl;
        	int result[2]={s[j],t[j]};
        	return result;
		}
	}
}

bool bezout_check(int a,int b)
{
	int gcdresult=gcd(a,b);
	int *bezoutresult=bezout(a,b);	
	printf("%d和%d的最大公约数为：%d，Bézout贝祖等式结果为s=%d，t=%d\n",a,b,gcdresult,bezoutresult[0],bezoutresult[1]);
	if(bezoutresult[0]*a+bezoutresult[1]*b==gcdresult) return true;
	return false;
}

int main()
{
	cout<<boolalpha<<bezout_check(166, 332)<<endl<<endl;
	cout<<boolalpha    <<bezout_check (984, 1038)<<endl<<endl;
	cout<<boolalpha   <<bezout_check (1124, 1213)<<endl<<endl;
	cout<<boolalpha    <<bezout_check (1281, 2019)<<endl<<endl;
	cout<<boolalpha    <<bezout_check(1338, 2018)<<endl<<endl;
	
	return 0;
}
