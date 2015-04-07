#include<time.h>
#include<iostream>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<fstream>
#include<string.h>
using namespace std;


const int N = 1010;
int color[N];
bool flag[N];
int match[N];
vector<int> e[N];
int n, m;

void doColor(int i, int c)
{
	int size = e[i].size();
	color[i] = c;
	for(int j = 0; j < size; j++)
	{
		if(color[e[i][j]] == 0)
			doColor(e[i][j], -c);
	}
}

bool dfs(int i)
{
	int size = e[i].size();
	for(int j = 0; j < size; j++)
	{
		int nei = e[i][j];
		if(flag[nei])
			continue;
		flag[nei] = true;
		if(match[nei] == 0 || dfs(match[nei]))
		{
			match[i] = nei;
			match[nei] = i;
			return true;
		}
	}
	return false;
}
int main()
{
	memset(color, 0, sizeof(color));
	memset(match, 0, sizeof(match));
	scanf("%d %d", &n, &m);
	for(int i = 1, j, k; i <= m; i++)
	{
		scanf("%d %d", &j, &k);
		e[j].push_back(k);
		e[k].push_back(j);
	}
	for(int i = 1; i <= n; i++)
		if(color[i] == 0)
		{
			color[i] = 1;
			doColor(i, 1);
		}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 1 && match[i] == 0)
		{
			memset(flag, false, sizeof(flag));
			if(dfs(i))
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}