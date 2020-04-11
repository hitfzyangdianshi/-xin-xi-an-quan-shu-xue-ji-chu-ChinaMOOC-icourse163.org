/*作业 1.4  20200316
1（5分）
计算如下整数的最大公因数：

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

int bezout(int a, int b)
{
	int s,t;
	
}

int main()
{
	cout<<"gcd:  "<<endl;
	cout<<gcd(166, 332)<<endl
		<<gcd(984, 1038)<<endl
		<<gcd(1124, 1213)<<endl
		<<gcd(1281, 2019)<<endl
		<<gcd(1338, 2018)<<endl;
	cout<<"***********************"<<endl;
		
		
	
	return 0;
}
