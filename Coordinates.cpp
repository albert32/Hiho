
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int p, q;
	scanf("%d %d", &p, &q);
	vector<int> v;
	v.reserve(1000);
	for(int i = 1; i <= q/2; i++)
		if(q % i == 0)
			v.push_back(i);
	v.push_back(q);
	for(int j = 1; j <= p/2; j++)
		if(p % j == 0)
			for(int i = 0; i < v.size(); i++)
				printf("%d %d\n", j, v[i]);

	for(int i = 0; i < v.size(); i++)
		printf("%d %d\n", p, v[i]);	
	return 0;
}