#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;
int ha[256];
int fibo[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}; 
bool isF(string &s, int i, int j)
{
	memset(ha, 0, sizeof(ha));
	for(int k = i; k <= j; k++)
		ha[s[k]]++ ;
	int count = 0;
	for(int k = 0; k < 256; k++)
		if(ha[k] != 0)
			count++;
	for(int i = 0; i < 11; i++)
		if(count == fibo[i])
			return true;
	return false;
}
int main()
{
	string s;
	cin>>s;
	set<string> ans;
	for(int i = 0; i < s.length(); i++)
		for(int j = i; j < s.length(); j++)
			if(isF(s, i, j))
				ans.insert(s.substr(i, j - i + 1));
	for(set<string>::iterator it = ans.begin(); it != ans.end(); it++)
		cout<<*it<<"\n";
 	return 0;
}