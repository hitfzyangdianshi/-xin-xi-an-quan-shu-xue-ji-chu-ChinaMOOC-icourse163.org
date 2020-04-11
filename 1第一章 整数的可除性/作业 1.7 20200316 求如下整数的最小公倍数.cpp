/*作业 1.7 20200316

1.7 最小公倍数

1. 求如下整数的最小公倍数：

1). [888, 1036]

2). [1094, 1152]

3). [1190, 1227]

4). [1274, 1342]

5). [936, 984]


*/
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

int lcm(int a, int b)
{
	return a*b/gcd(a,b);	
}

int main()
{
	cout<<"lcm:  "<<endl;
	cout<<lcm(888, 1036)<<endl;
	cout	<<lcm(1094, 1152)<<endl;
	cout	<<lcm(1190, 1227)<<endl;
	cout	<<lcm(1274, 1342)<<endl;
	cout	<<lcm(936, 984)<<endl;
	cout<<"***********************"<<endl;
		
		
	
	return 0;
}
