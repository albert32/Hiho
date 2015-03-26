#include "stdafx.h"
#include<string.h>
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<string.h>
#include<list>
#include<queue>
using namespace std;
const int N = 10010;
const int M = 40010;
list<int> node[M];
int t, m, n;
int color[N];
bool remains[N];
bool flag;
int getRemains()
{
	for(int i = 1; i <= n; i++)
		if(remains[i])
			return i;
	return -1;
};
bool bfs()
{
	queue<int> q;
	int now = getRemains();
	while(now != -1)
	{
		q.push(now);
		remains[now] = false;
		color[now] = 1;
		while(q.size() > 0)
		{
			int e = q.front();
			int c = color[e];
			q.pop();
			for(list<int>::iterator it = node[e].begin(); it != node[e].end(); it++)
			{
				int current = *it;
				if(color[current] == 0)
				{
					color[current] = c % 2 + 1;
					q.push(current);
					remains[current] = false;
				}
				else if(color[current] == c)
					return false;
			}
		}
		now = getRemains();
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		memset(color, 0, sizeof(color));
		memset(remains, false, sizeof(remains));
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			node[i].clear();
		int j, k;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d", &j, &k);
			node[j].push_back(k);
			node[k].push_back(j);
			remains[j] = true;
			remains[k] = true;
		}
		if(bfs())
			printf("Correct\n");
		else
			printf("Wrong\n");

	}
	return 0;
}
