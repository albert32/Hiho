#include <iostream>
#include <math.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<fstream>
#include<map>
#include<time.h>
using namespace std;
const int N = 2110;
int dp[N][N];
int f[N][N];
char s1[N];
char s2[N];
int main()
{
	s1[0] = s2[0] = 'a';
	memset(dp, 0, sizeof(dp));
	memset(f, 0, sizeof(f));
	scanf("%s", s1+1);
	scanf("%s", s2+1);
	int len1 = 1, len2 = 1;
	while(s1[len1] != '\0')
		len1++;
	while(s2[len2] != '\0')
		len2++;
	for(int i = 1; i < len1; i++)
		for(int j = 1; j < len2; j++)
		{
			if(s1[i] == s2[j])
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = 0;
		}
	for(int i = 1; i < len1; i++)
		for(int j = 1; j < len2; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			if(f[i][j] >= 3)
				dp[i][j]= max(dp[i][j],max(dp[i - 3][j - 3] + 3, dp[i - f[i][j]][j - f[i][j]] + f[i][j]));
		}
	printf("%d\n", dp[len1-1][len2-1]);
	return 0;
}