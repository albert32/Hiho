
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<vector>
#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;
const int N = 1010;

int r[N][N];
int main()
{
	int n, k, order, tmp, result = 0;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		order = 0;
		for(int j = 1; j <= k+1; j++)
		{
			scanf("%d", &tmp);
			r[i][tmp] = order++;
		}
	}
	for(int i = k; i >= 1; i--)
	{
		int vote = 0;
		for(int j = 1; j <= n; j++)
			if(r[j][i] < r[j][result])
				vote++;
		if(vote > n/2)
			result = i;
	}
	if(result == 0)
		printf("otaku\n");
	else
		printf("%d\n", result);
	return 0;
}