#include <iostream>
#include <cstring>
#include <cmath>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 110, M = 110;
char e[N][M];
int step[N][M];
const int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int n, m;
bool inMap(int x, int y)
{
	  return (0 <= x && x < n && 0 <= y && y < m) && (e[x][y] == '.' || e[x][y] == 'S');
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", e[i]);
	int startx, starty;
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			step[i][j] = 9999999;
			if(e[i][j] == 'H')
			{
				startx = i;
				starty = j;
				q.push(make_pair(i, j));
				step[i][j] = 0;
			}
		}
	while(!q.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			int x = q.front().first + dir[i][0];
			int y = q.front().second + dir[i][1];
			if(inMap(x, y) && step[x][y] == 9999999)
			{
				step[x][y] = step[q.front().first][q.front().second] + 1;
				if(e[x][y] != 'S')
					q.push(make_pair(x, y));
			}
		}
		q.pop();
	}
	int ans = 9999999;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(e[i][j] == 'S' && step[i][j] < 9999999 && step[i][j] != 0)
			{
				if(i > 0 && e[i-1][j] == 'S' && step[i-1][j] < 9999999 && step[i-1][j] != 0) 
					ans = min(ans, step[i][j] + step[i-1][j]);
				if(j > 0 && e[i][j-1] == 'S' && step[i][j-1] < 9999999 && step[i][j-1] != 0)
					ans = min(ans, step[i][j] + step[i][j-1]);
			}
		}
	if(ans == 9999999)
	    printf("Hi and Ho will not have lunch.\n");
	else
	    printf("%d\n", ans);
    return 0;
}
