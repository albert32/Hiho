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
using namespace std;

const int N = 100010;
struct node
{
	long long value;
	long long count;
};
node a[N];
int pri[10000];
bool prime[N+1];
int p;
bool cmp(const node &n1, const node &n2)
{
	return n1.count > n2.count;
};
long long  doCount(long long  value)
{
	if(value == 1)
		return 1;
	long long  ans = 1;
	for(int i = 0; i < p && pri[i] <= value; i++)
	{
		if(value < N && prime[value] == false)
			break;
		if(value % pri[i] == 0)
		{
			int t = 1;
			while(value % pri[i] == 0)
			{
				t++;
				value /= pri[i];
			}
			ans *= t;
		}
	}
	if(value > 1)
		ans *= 2;
	return ans;
}
void countPrimes(int n) 
{
    for(int i = 2; i < n; i++)
    {
    	if(prime[i] == false)
    		for(int j = i + i; j < n; j += i)
    			prime[j] = true;
    }
	p = 0;
    for(int i = 2; i < n; i++)
    	if(!prime[i])
			pri[p++] = i;
}
int main()
{
	int n;
	countPrimes(N);
	long long ans = 0;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i].value);
		a[i].count = doCount(a[i].value);

	}
	sort(a + 1, a + n + 1, cmp);
	int pos = 100;
	for(int i = 1; i <= pos && i <= n; i++)
		for(int j = 1; j <= pos && i <= n; j++)
		{
			long long tmp = doCount(a[i].value * a[j].value);
			if(tmp > ans)
				ans = tmp;
		}
	printf("%lld\n", ans);;
 	return 0;
}