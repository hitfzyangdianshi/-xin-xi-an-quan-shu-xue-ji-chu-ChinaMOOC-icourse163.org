//3). 构造 mod 21 的加法(参见 例 2.3.11)
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nu[]={1,2,4,5,7,8,10,11,13,14,16,17,19,20},i,j;
	cout<<"a\\k"<<"\t";
	for(i=0;i<14;i++)
    {
    	cout<<nu[i]<<"\t";
	}
	cout<<endl;
	for(i=0;i<14;i++)
	{
		cout<<nu[i]<<"\t";
		for(j=0;j<14;j++)
		{
			cout<<(nu[i]*nu[j])%21<<"\t";
		}
		cout<<endl;
	}
    return 0;
} 
