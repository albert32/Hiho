#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<string.h>
#include<stack>
#include<time.h>
using namespace std;

struct node
{
	bool flag;
	int l, r, value;
};
const int N = 1000010;
node tree[4 * N];
int w[N];
int pos[N];
int build(int l, int r, int index)
{
	//返回值：该层的最小值
	//index:该区间对应的node数组的下标
	//l,r:该区间的左右边界，包含
	int ans;
	tree[index].flag = true;
	if(l == r)// 叶子节点
	{
		tree[index].l = tree[index].r = l;
		tree[index].value = w[l];
		pos[l] = index;
		return w[l];
	}
	else
	{
		int mid = (r - l) / 2;
		tree[index].l = l;
		tree[index].r = r;
		ans = build(l, l + mid, index * 2);
		int tmp = build(l + mid + 1, r, index * 2 + 1);
		if(ans > tmp)
			ans = tmp;
		tree[index].value = ans;
		return ans;
	}
};

void update(int p, int value)
{
	//w数组中第p个位置的数被更新为value
	int position = pos[p];
	w[p] = value;
	tree[position].value = value;
	int parent = position / 2;
	while(parent >= 1)
	{
		tree[parent].value = min(tree[parent * 2].value, tree[parent * 2 + 1].value);
		parent /= 2;
	}
};

int query(int l, int r, int index)
{
	int border = (tree[index].r - tree[index].l) / 2 + tree[index].l;
	if(tree[index].l == l && tree[index].r == r)
		return tree[index].value;
	else if(r <= border)
		return query(l, r, index * 2);
	else if(l > border)
		return query(l, r, index *2 + 1);
	else
	{
		int ans1 = query(l, border, index * 2);
		int ans2 = query(border + 1, r, index * 2 + 1);
		return ans1 < ans2 ? ans1 : ans2;
	}
};
int main()
{
	int n, q;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", w + i);
	
	build(1, n, 1);
	scanf("%d", &q);
	int a, b,c;
	while(q--)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0)
		{
			if(b + 1 == c)
				printf("%d\n", w[b] < w[c] ? w[b] : w[c]);
			else if(b == c)
				printf("%d\n", w[b]);
			else
				printf("%d\n", query(b, c, 1));
		}
		else
			update(b, c);
	}
	return 0;
}