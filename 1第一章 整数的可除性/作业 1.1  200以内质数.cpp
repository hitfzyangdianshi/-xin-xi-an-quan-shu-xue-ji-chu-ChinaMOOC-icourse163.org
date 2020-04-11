#include<bits/stdc++.h>
using namespace std;

int N=200;
int main()
{
	int i,j,tag;
	for (i=2;i<=N;i++) 
	{
		tag=0;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				tag=1;
				break;
			}
		}
		if(tag==0)cout<<i<<"\t";
		
	}
	
	return 0;
}
