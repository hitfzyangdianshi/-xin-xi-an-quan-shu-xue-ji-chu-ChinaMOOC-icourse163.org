/*�� p = 19. �������� u = { u_k = a^k mod p |  k = 1, 2,  ..} ����С����

    (�μ����� B.0.1), ���� a = 2, 3 , 5, 7.
*/
#include<bits/stdc++.h>
using namespace std;

long long xy(long long a , long long b)
{
	if(b==1)return a;
	else if (b==0)return 1;
	else return a*xy(a,b-1);
}

int main()
{
	long long k=1;
	while(1)
	{
		cout<< xy(7,k) % 19 <<"\t";
		k++;
	}
    return 0;
} 
