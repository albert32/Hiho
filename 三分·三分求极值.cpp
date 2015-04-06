#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int a,b,c;
int x, y;
double b2a;

double dis(double xx)
{
	double xy = xx * xx * a + xx * b + c;
	double d = sqrt(pow(xx - x, 2) + pow(xy - y, 2));
	return d;
}
int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	b2a = (double)(-b) / (a << 1);
	double l, r, mid, mm;
	double c = (double)-b / (2 * a);
	if(y == x * x * a - x * b - c)
	{
		printf("%.3d", 0);
		return 0;
	}
	if(x < c)
	{
		l = -300;
		r = c;
	}
	else if(x > c)
	{
		l = c;
		r = 300;
	}
	mid = (l + r) / 2;
	mm = (mid + r) / 2;
	while(fabs(mid - mm) > 0.001)
	{
		double mid_y = dis(mid);
		double mm_y = dis(mm);
		if(mid_y < mm_y)
			r = mm;
		else
			l = mid;
		mid = (l + r) / 2;
		mm = (mid + r) / 2;
	}

	double ans = dis(mid);
	int remainder =  (int)ans * 1000  % 10;
	if(remainder >= 5)
		ans += 0.001;
	printf("%.3f", ans);
	return 0;
}
 