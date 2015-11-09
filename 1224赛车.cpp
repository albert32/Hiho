#include<string>
#include<stdio.h>
#include<iostream>
#include<map>
#include<stack>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<unordered_set>
using namespace std;

const int N = 100010;
struct node
{
	vector<int> son;
	int parent, value;
};
node e[N];
bool vis[N];
int max_depth, max_node, second_depth;
int dfs(int pos, int value)
{
	e[pos].value = 1;
	if(value > max_depth)
	{
		max_depth = value;
		max_node = pos;
	}
	for(int i = 0; i < e[pos].son.size(); i++)
	{
		int t = dfs(e[pos].son[i], value+1);
		e[pos].value = max(e[pos].value, t+1);
	}
	return e[pos].value;
};
void reverse(int root)
{
	while(true)
	{
		vis[root] = true;
		if(root == 1)
			break;
		root = e[root].parent;
	}
};
void second(int pos, int value)
{
	if(vis[pos])
		return;
	if(value > second_depth)
		second_depth = value;
	for(int i = 0; i < e[pos].son.size(); i++)
		second(e[pos].son[i], value+1);
}
int main()
{
	int n;
	cin>>n;
	max_depth = -1, max_node = -1, second_depth = 0;
	for(int j,k,i=1; i < n; i++)
	{
		//cin>>j>>k; //j->k
		scanf("%d %d", &j, &k);
		e[j].son.push_back(k);
		e[k].parent = j;
	}
	memset(vis, false, sizeof(vis));
	dfs(1, 0);
	reverse(max_node);
	for(int i = 2; i <= n; i++)
		if(!vis[i])
			second_depth = max(second_depth, e[i].value);
	cout<<max_depth+second_depth;
	return 0;
}