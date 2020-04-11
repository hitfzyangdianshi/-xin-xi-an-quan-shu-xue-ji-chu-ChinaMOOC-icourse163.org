//作业 2.3 20200330 1). 构造 mod 19 的简化剩余系及乘法表(例 2.3.10).
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nu[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},i,j;
	cout<<"a\\k"<<"\t";
	for(i=0;i<18;i++)
    {
    	cout<<nu[i]<<"\t";
	}
	cout<<endl;
	for(i=0;i<18;i++)
	{
		cout<<nu[i]<<"\t";
		for(j=0;j<18;j++)
		{
			cout<<(nu[i]*nu[j])%19<<"\t";
		}
		cout<<endl;
	}
    return 0;
} 
