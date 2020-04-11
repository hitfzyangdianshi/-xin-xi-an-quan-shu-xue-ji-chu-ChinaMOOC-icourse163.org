//求模n的非负最小简化剩余系 
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	int c=1;
	if(a<b)swap(a,b);
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
} 

int main(int argc, char** argv)
{
	int n,i;
	cin>>n;
	cout<<"模"<<n<<"的非负最小简化剩余系包括\t1";
	for(i=2;i<n;i++)
		if(gcd(n,i)==1)cout<<","<<i;
	cout<<endl;
	
	return 0;	
}
