/*�� $(5^{1/2}+1)/2$ �ļ���������ǰ6�������
��Բ���� $\pi$ �ļ���������ǰ6�������
����Ȼ������ $e$ �ļ���������ǰ6�������
��������� $20190122/2017$ �ļ���������ǰ6�������*/
#include<bits/stdc++.h>
using namespace std;
//***1/double֮�������������ȡ�������⣬���á�ֻ�����������pi��e����ʾ�� 
//#define PI acos(-1.0)
#define PI 3.1415926535897932385
#define e exp(1)

int main(int argc, char **argv)
{
	cout<<"i\ta_i\tx_i\tP_i\tQ_i"<<endl;
	double n=sqrt(2011*2017);
	n=2013.9977656393;
	__int64 a[100],P[102],Q[102],i;
	long double x[100];
	a[0]=floor(n);
	x[0]=n-a[0];
	for(i=1;i<100;i++)
	{
		if(i-1==0){
			P[i-1]=a[i-1]*1+0;
			Q[i-1]=a[i-1]*0+1;
		}
		else if(i-1==1){
			P[i-1]=a[i-1]*P[i-2]+1;
			Q[i-1]=a[i-1]*Q[i-2]+0;
		}
		else{
			P[i-1]=a[i-1]*P[i-2]+P[i-3];
			Q[i-1]=a[i-1]*Q[i-2]+Q[i-3];
		}
		cout<<i-1<<"\t"<<a[i-1]<<"\t"<<x[i-1]<<"\t"<<P[i-1]<<"\t"<<Q[i-1]<<endl;
		if(fabs(x[i-1]-0)<=1e-9)break;
		a[i]=floor(1.0/x[i-1]);
		x[i]=1.0/x[i-1]-a[i];
	}
	
	
	return 0;
}
