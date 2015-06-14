#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;

const int N = 10010;
int n, m;
vector<int> e[N];
int degree[N];
bool vis[N];
int num;
void dfs(int pos)
{
	if(vis[pos] == false)
	{
		num++;
		vis[pos] = true;
		for(int i = 0; i < e[pos].size(); i++)
			if(vis[e[pos][i]] == false)
				dfs(e[pos][i]);
	}
}
int main()
{
	num = 0;
	memset(vis, false, sizeof(vis));
	memset(degree, 0, sizeof(degree));
	scanf("%d %d", &n, &m);
	for(int i = 0, j, k; i < m; i++)
	{
		scanf("%d %d", &j, &k);
		e[j].push_back(k);
		e[k].push_back(j);
		degree[j]++;
		degree[k]++;
	}
	dfs(1);
	if(num != n)
		cout<<"Part\n";
	else
	{
		int sum = 0;
		for(int i = 1; i <= n; i++)
			if(degree[i] % 2 == 1)
				sum++;
		if(sum <= 2)
			cout<<"Full\n";
		else
			cout<<"Part\n";
	}
	return 0;
}