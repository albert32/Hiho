//#include "StdAfx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<iterator>
#include<sstream>
using namespace std;
int a[100010];
int b[100010];
long ans;
int n;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void mergeSort(int l, int r)
{
	if(l == r -1)
	{
		if(a[l] > a[r])
		{
			ans++;
			swap(&a[l], &a[r]);
		}
		return;
	}
	else if(l >= r)
		return;
	int mid = (l + r) >> 1;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	int count = 0;
	int index = l;
	int ll = l, rr = mid + 1;
	while(ll <= mid && rr <= r)
	{
		if(a[ll] <= a[rr])
		{
			b[index++] = a[ll];
			ll++;
			ans += count;
		}
		else 
		{
			b[index++] = a[rr];
			rr++;
			count++;
		}
	}
	while(ll <= mid)
	{
		b[index++] = a[ll++];
		ans += count;
	}
	while(rr <= r)
	{
		b[index++] = a[rr++];
	}
	for(int i = l; i <= r; i++)
		a[i] = b[i];
}
int main () 
{
	ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	mergeSort(1, n);
	cout<<ans;
}