#include<string.h>
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<string.h>
#include<list>
#include<queue>
using namespace std;
struct node
{
	long long value, count;
};

const int M = 100010;
node a[M];
node b[M];
int n, m, t;
bool cmp(const node &a1, const node &a2)
{
	return a1.value < a2.value;
};
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%lld %lld", &a[i].value, &a[i].count);
		for(int i = 1; i <= m; i++)
			scanf("%lld %lld", &b[i].value, &b[i].count);
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + m + 1, cmp);
		long long ans = 0;
		int pos = 1;
		long long last = 0, current = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i != 1)
				current = last / a[i - 1].count * a[i].count;
			for(int j = pos; j <= m; j++)
			{
				if(a[i].value > b[j].value)
					current += b[j].count * a[i].count;
				else
					break;
				pos = j + 1;
			}
			ans += current;
			last = current;
		}
		printf("%lld\n", ans);
	}
	return 0;
}