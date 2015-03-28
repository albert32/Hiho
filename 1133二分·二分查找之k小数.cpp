#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int N = 1000010;
int a[N];
int n, k;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void random(int l, int mid, int r)
{
	if(a[mid] < a[l])
		swap(&a[mid], &a[l]);
	if(a[r] < a[mid])
		swap(&a[r], &a[mid]);
	if(a[mid] < a[l])
		swap(&a[mid], &a[l]);
	swap(&a[mid], &a[r]);
}
int split(int l, int r)
{
	int mid = (l + r) / 2;
	if(r - l > 2)
		random(l ,mid, r);
	int x = a[r], i = l - 1;
	for(int j = l; j < r; j++)
		if(a[j] < x)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	swap(&a[r], &a[i+1]);
	return i + 1; 
}
int recursive(int left, int right, int k)
{
	if(left == right)
		return a[left];
	int mid = split(left, right);
	if(mid - left + 1 == k)
		return a[mid];
	else if(mid - left >= k)
		return recursive(left, mid - 1, k);
	else return recursive(mid + 1, right, k - (mid - left + 1));
}
int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	if(k > n || k < 1)
		cout<<"-1";
	else
		cout<<recursive(1, n, k);
	return 0;
}
 