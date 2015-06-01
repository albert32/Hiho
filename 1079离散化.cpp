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
#include<queue>
#include<set>
#include<stack>
using namespace std;
const int N = 100010;
struct node
{
	int l, r;
};
struct node2
{
	int l, r;
	int c;
	bool used;
};
node poster[N];
node2 seg[N * 4];
int x[N * 2];
int n, l;
int ans;
bool vis[N];
void buildTree(int l, int r, int pos)
{
	seg[pos].used = true;
	seg[pos].c = 0;
	seg[pos].l = l;
	seg[pos].r = r;
	if(l == r - 1)
	{
		buildTree(l, l, pos * 2);
		buildTree(r, r, pos * 2 + 1);
	}
	else if(l < r - 1)
	{
		int mid = (l + r) >> 1;
		buildTree(l, mid, pos * 2);
		buildTree(mid, r, pos * 2 + 1);
	}
}
void insert(int l, int r, int c, int pos)
{
	if(seg[pos].l == l && seg[pos].r == r)
	{
		seg[pos].c = c;
		return;
	}
	if(seg[pos].c > 0 && seg[pos].c != c)
	{
		seg[pos*2].c = seg[pos].c;
		seg[pos * 2 + 1].c = seg[pos].c;
		seg[pos].c = 0;
	}
	int mid = (seg[pos].l + seg[pos].r) >> 1;
	if(r <= mid)
		insert(l, r, c, pos*2);
	else if(l >= mid)
		insert(l, r, c, pos *2 + 1);
	else
	{
		insert(l, mid, c, pos*2);
		insert(mid, r, c, pos * 2 + 1);
	}
};
void search(int pos)
{
	if(pos >= 4*N || seg[pos].used == false)
		return;
	if(seg[pos].c != 0)
	{
		if(!vis[seg[pos].c])
		{
			vis[seg[pos].c] = true;
			ans++;
		}
		return;
	}
	search(2 * pos);
	search(2*pos + 1);
};
int main()
{
	memset(vis, false, sizeof(vis));
	ans = 0;
	scanf("%d %d", &n, &l);
	int pos = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &poster[i].l, &poster[i].r);
		x[pos++] = poster[i].l;
		x[pos++] = poster[i].r;
	}
	sort(x, x + pos);
	unordered_map<int, int> m;
	m.insert(make_pair(x[0], 0));
	int value = 1;
	for(int i = 1; i < pos; i++)
	{
		if(x[i] == x[i - 1])
			continue;
		m[x[i]] = value++;
	}
	for(int i = 1; i <= n; i++)
	{
		poster[i].l = m[poster[i].l];
		poster[i].r = m[poster[i].r];
	}
	l = value;
	buildTree(0, l, 1);
	for(int i = 1; i <= n; i++)
		insert(poster[i].l, poster[i].r, i, 1);
	search(1);
	cout<<ans;
	return 0;
}