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
#include<set>
using namespace std;

const int N = 101;
int a[N];
int b[N][14];
int n;
int maxPos = 0;
void conver2binary(int pos)
{
	int index = 0;
	while(a[pos] > 0)
	{
		b[pos][index++] = a[pos] & 1;
		a[pos] = a[pos] >> 1;
	}
	if(index > maxPos)
		maxPos = index;
}
int main()
{
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		conver2binary(i);
	}
	for(int i = 0; i < maxPos; i++)
	{
		int ans = 0;
		for(int j = 1; j <= n; j++)
			ans += b[j][i];
		if(ans % 2 == 1)
		{
			cout<<"Alice\n";
			return 0;
		}
	}
	cout<<"Bob\n";
 	return 0;
}