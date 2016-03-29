#include<stdlib.h>
#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
	int a[1020];
	a[0] = INT_MAX;
	int l, r, n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(r = n; r >= 1; r--)
		if(a[r] <= a[r-1])
			break;
	if(r == 1)
	{
		cout<<1<<"\n";
		return 0;
	}
	for(int i = 1; i < r; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}