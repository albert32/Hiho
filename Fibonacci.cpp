// Trivial.cpp : 定义控制台应用程序的入口点。

#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<time.h>
#include<sstream>
#include<fstream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int limit = 100000;
int f[30];
int a[1000000];
int k;
int mod = 1000000007;
int main()
{
	unordered_map<int, int> pos;
	int p1 = 1, p2 = 1;
	pos.insert(make_pair(1, 2));
	int next1 = p1 + p2, p = 3;
	while(next1 <= limit)
	{
		pos.insert(make_pair(next1, p));
		p++;
		p1 = p2;
		p2 = next1;
		next1 = p1 + p2;
	}
	memset(f, 0, sizeof(0));
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
		scanf("%d", a + i);
	unordered_map<int,int>::iterator it;
	for(int i = 0; i < k; i++)
	{
		it = pos.find(a[i]);
		if(it != pos.end())
		{
			p = it->second;
			f[p] = (f[p - 1] + f[p]) % mod;
			if(a[i] == 1)
				f[1] += 1;
		}
	}
	int ans = 0;
	for(int i = 1; i < 27; i++)
		ans = (ans + f[i]) % mod;
	printf("%d", ans);
	return 0;
}