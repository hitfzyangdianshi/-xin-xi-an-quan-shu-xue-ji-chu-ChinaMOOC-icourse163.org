#include<bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}	
	return true;
}

int main()
{
	
	cout<<boolalpha
	    <<191<<"\t"<<prime(191)<<endl
	    <<193<<"\t"<<prime(193)<<endl
		<<197<<"\t"<<prime(197)<<endl
		<<199<<"\t"<<prime(199)<<endl<<"*********************"<<endl
	    <<221<<"\t"<<prime(221)<<endl
		<<223<<"\t"<<prime(223)<<endl
		<<227<<"\t"<<prime(227)<<endl
		<<229<<"\t"<<prime(229)<<endl<<"*********************"<<endl
		<<391<<"\t"<<prime(391)<<endl
		<<397<<"\t"<<prime(397)<<endl
		<<401<<"\t"<<prime(401)<<endl
		<<403<<"\t"<<prime(403)<<endl ;
	
	return 0;
}
