#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;


int main()
{
	int n, t, x, ans = 0;
	bool flag = false;
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if(x <= t)
			ans++;
		if(x == t)
			flag = 1;
	}
	if(!flag)
		cout<<"-1";
	else
		cout<<ans;
	return 0;
}