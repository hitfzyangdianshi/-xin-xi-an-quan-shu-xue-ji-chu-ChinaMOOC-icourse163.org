/*作业 1.8  20200316查看帮助返回

1.8 算术基本定理 整数分解

1（5分）
求如下整数的因数分解式:

1). 465, 510, 552, 592, 627.

2). 673, 713, 764, 812, 856. 

3). 890, 936, 984,  1038, 1124.


思考题：
算术基本定理的证明是否要用到广义欧几里得除法或贝祖等式
*/

#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
	int i,j;
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
    	j=0;
        while(n%i==0)
        {
            n/=i;
			j++;
        }
        if(j!=0)
		{
		    printf("%d^%d",i,j);
            if(n!=1) printf("*");
        }
    }
    printf("\n");
    return 0;
}

int main()
{
	cout<<endl<<"**** group 1 ****"<<endl;
	f(465);f(510); f(552); f(592); f(627);
	cout<<endl<<"**** group 2 ****"<<endl;
	f(673);f(713); f(764); f(812); f(856);
	cout<<endl<<"**** group 3 ****"<<endl;
	f(890);f(936); f(984); f(1038); f(1124);
	return 0;
}
