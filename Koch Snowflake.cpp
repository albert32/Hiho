#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int get(int i, int n)
{
	if(n == 0)
		return 0;
	if(i % 4 == 2 || i % 4 == 3)
		return n;
	else if(i % 4 == 0)
		return get(i / 4, n-1);
	else return get(i / 4 + 1, n-1);
}
int main()
{
	int t,i,n;
	cin>>t;
	while(t--)
	{
		cin>>i>>n;
		cout<<get(i, n)<<"\n";
	}
	return 0;
}