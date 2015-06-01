#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == 'H')
			ans ^= (i + 1);
	if(ans == 0)
		cout<<"Bob\n";
	else
		cout<<"Alice\n";
	return 0;
}