#include <iostream>
#include <cstring>
#include <cmath>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<string.h>
#include<set>
using namespace std;

const int N = 40, M = 21000, level = 150;
int f[N][M];
int c[N][level], w[N][level];
int n,m;
double d = 1.07;
int main()
{
	cin>>n>>m;
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	memset(w, 0, sizeof(w));
	int max_level = 0;
	for(int i, j, k = 1; k <= n; k++)
	{
		cin>>i>>j;
		int l = 1;
		while(j <= m)
		{
			c[k][l] = i * l;
			w[k][l] = j + w[k][l-1];
			j = d * j;
			l++;
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
		{
			f[i][j] = max(f[i][j], f[i-1][j]);
			for(int k = 1; k < level; k++)
			{
				if(w[i][k] == 0)
					break;
				if(j >= w[i][k])
					f[i][j] = max(f[i][j], f[i-1][j - w[i][k]] + c[i][k]);
			}
		}
	int ans = 0;
	for(int i = 0; i <= m; i++)
		ans = max(f[n][i], ans);
	cout<<ans<<"\n";
	return 0;
}