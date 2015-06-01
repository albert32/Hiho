#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;

const int N = 100010;
struct node
{
	int l, r, sum;
	int s, add;
};
node tree[N*4];
int price[N];
int n, m;

void initial(int l, int r, int pos)
{
	if(l > r)
		return;
	tree[pos].add = 0;
	tree[pos].s = 0;
	tree[pos].l = l;
	tree[pos].r = r;
	if(l == r)
		tree[pos].sum = price[l];
	else
	{
		int mid = (l + r) >> 1;
		initial(l, mid, pos*2 + 1);
		initial(mid + 1, r, pos*2+ 2);
		tree[pos].sum = tree[pos*2 + 1].sum + tree[pos*2+2].sum;
	}
}

void update(int l, int r, int value, int op, int pos)
{
	if(tree[pos].l == l && tree[pos].r == r)
	{
		if(op == 0)
		{
			tree[pos].sum += value * (tree[pos].r - tree[pos].l + 1);
			tree[pos].add += value;
		}
		else
		{
			tree[pos].sum = value * (tree[pos].r - tree[pos].l + 1);
			tree[pos].s = value;
			tree[pos].add = 0;
		}
		return;
	}
	if(tree[pos].s != 0)
	{
		tree[pos*2 + 1].s = tree[pos].s;
		tree[pos*2 + 1].sum = tree[pos*2+1].s * (1 + tree[pos*2+1].r - tree[pos*2+1].l);
		tree[pos*2 + 2].s = tree[pos].s;
		tree[pos*2 + 2].sum = tree[pos*2+2].s * (1 + tree[pos*2+2].r - tree[pos*2+2].l);
		
		tree[pos].s = 0;
		tree[pos*2+1].add = 0;
		tree[pos*2+2].add = 0;
	}
	if(tree[pos].add != 0)
	{
		tree[pos*2 + 1].add += tree[pos].add;
		tree[pos*2 + 1].sum += tree[pos].add * (1 + tree[pos*2+1].r - tree[pos*2+1].l);
		tree[pos*2 + 2].add += tree[pos].add;
		tree[pos*2 + 2].sum += tree[pos].add * (1 + tree[pos*2+2].r - tree[pos*2+2].l);

		tree[pos].add = 0;
	}

	int mid = (tree[pos].l + tree[pos].r) /2;
	if(l > mid)
		update(l, r, value, op, pos*2 + 2);
	else if(r <= mid)
		update(l, r, value, op, pos*2 + 1);
	else
	{
		update(l, mid, value, op, pos*2 + 1);
		update(mid+1, r, value, op, pos*2 + 2);
	}
	tree[pos].sum = tree[pos*2+1].sum + tree[pos*2+2].sum;
}
int main()
{
	int op, l, r, value;
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i++)
		scanf("%d", price + i);
	initial(0, n, 0);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d %d", &op, &l, &r, &value);
		update(l, r, value, op, 0);
		printf("%d\n", tree[0].sum);
	}
	return 0;
}