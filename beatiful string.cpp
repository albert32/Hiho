#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
const int N = 10*1024*1024+10;
struct node
{
	char c;
	int count;
};
char s[N];
node dp[N];
int main()
{
	int t, num, pos;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &num);
		pos = 0;
		scanf("%s", s);
		dp[pos].c = s[0];
		dp[pos].count = 1;
		for(int i = 1; i < num; i++)
		{
			if(s[i] == dp[pos].c)
				dp[pos].count++;
			else
			{
				pos++;
				dp[pos].count = 1;
				dp[pos].c = s[i];
			}
		}
		int ans = 0;
		for(int i = 2; i <= pos; i++)
		{
			if(dp[i].count >= dp[i-1].count && dp[i-2].count >= dp[i-1].count && 
				dp[i].c - 1 == dp[i-1].c && dp[i-1].c-1 == dp[i-2].c)
			{
				ans = 1;
				break;
			}
		}
		if(ans == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}