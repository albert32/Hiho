#include<string>
#include<stdlib.h>
#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
const int N = 100010;

vector<int> e[N];
int c[N];
int d[N];
int n, m, k;
const int mod = 142857;
int main()
{
	memset(d, 0, sizeof(d));
	memset(c, 0, sizeof(c));
	scanf("%d %d %d", &n, &m, &k);
	//
	for(int j, i = 0; i < k; i++)
	{
		scanf("%d", &j);
		c[j]++;
	}
	for(int j, jj, i = 1; i <= m; i++)
	{
		scanf("%d %d", &j, &jj);
		e[j].push_back(jj);
		d[jj]++;
	}
	long long ans = 0;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(d[i] == 0)
			q.push(i);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		ans = ( ans + c[cur] ) % mod;
		for(int i = 0; i < e[cur].size(); i++)
		{
			int nex = e[cur][i];
			c[nex] = (c[cur] + c[nex]) % mod;
			d[nex]--;
			if(d[nex] == 0)
				q.push(nex);
		}
		c[cur] = 0;
	}
	for(int i = 1; i <= n; i++)
		if(c[i] != 0)
			ans = (ans + c[i]) % mod;
	printf("%d\n", ans);
	return 0;
}