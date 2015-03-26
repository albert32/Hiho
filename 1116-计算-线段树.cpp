// LC.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

// LC.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<string.h>
using namespace std;
#define setValue(index, le, right) (tree[index].f = tree[index].l = tree[index].r = tree[index].s = 0)
struct node
{
	int l, r, s, f;
};
const int N = 100002;
node tree[N * 4];
int pos[N];
int n,q;
const int mode = 10007;
/*
void setValue(int index, int le, int right)
{
	tree[index].f = tree[index].l = tree[index].r = tree[index].s = 0;
};
*/
void build(int le, int right, int index)
{
	//本层处理的区间le right， 本层对应tree的index
	setValue(index, le, right);
	int split = (right + le) >> 1;
	if(le == right)
	{
		pos[le] = index;
	}
	else
	{
		build(le, split, index << 1);
		build(split + 1, right, (index << 1) + 1);
	}
};

void update(int index, int value)
{
	//首先更新叶子节点的信息，由于叶子节点没有子节点，所以特殊处理。
	//对于叶子的父亲节点，则通过规律，递归的更新
	
	int position = pos[index];
	if(tree[position].f == (value % mode))
	    return;
	tree[position].f = tree[position].l = tree[position].r = tree[position].s = (value % mode);
	position >>= 1;
	int son1, son2;
	while(position >= 1)
	{
		son1 = position << 1;
		son2 = son1 + 1;
		tree[position].s = (tree[son1].s * tree[son2].s) % mode;
		tree[position].l = (tree[son1].l + tree[son1].s * tree[son2].l) % mode;
		tree[position].r = (tree[son2].r + tree[son2].s * tree[son1].r) % mode;
		tree[position].f = (tree[son1].f + tree[son2].f + tree[son1].r * tree[son2].l) % mode;
		position >>= 1;
	}
};
int main()
{
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	int index, value;
	while(q--)
	{
		scanf("%d %d", &index, &value);
		update(index, value);
		printf("%d\n", tree[1].f);
	}
	return 0;
}