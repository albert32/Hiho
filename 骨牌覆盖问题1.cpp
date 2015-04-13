#include<string.h>
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<fstream>
#include<queue>
#include<math.h>
using namespace std;

struct node
{
	long long  a, b;
	long long  c, d;
};
node e[30];
int mode = 19999997;
void compute(int i)
{
	long long a, b, c, d;
	a= e[i - 1].a;
	b = e[i - 1].b;
	c = e[i - 1].c;
	d = e[i - 1].d;
	e[i].a = ((a*a)%mode + (b*c)%mode) % mode;
	e[i].b = ((a*b)%mode + (b*d)%mode) % mode;
	e[i].c = ((a*c)%mode + (c*d)%mode) % mode;;
	e[i].d = ((c*b)%mode + (d*d)%mode) % mode;

}
void multi(node &n1, node &n2)
{
	long long a = n2.a;
	long long b = n2.b;
	long long c = n2.c;
	long long d = n2.d;
	long long n1a = n1.a*a + n1.b*c;
	long long n1b = n1.a*b + n1.b*d;
	long long n1c = n1.a*c + n1.c*d;
	long long n1d = n1.c*b + n1.d*d;
	n1.a = n1a % mode;
	n1.b = n1b % mode;
	n1.c = n1c % mode;
	n1.d = n1d % mode;
}
int main()
{
	int n;
	cin>>n;
	e[1].a = 0, e[1].b = e[1].c = e[1].d = 1;
	int counter = 2;
	for(int i = 2; i <= 30 && counter <= n; i++)
	{
		compute(i);
		counter <<= 1;
	}
	node base;
	base.a = 1; base.b = 0; base.c = 0; base.d = 1;
	counter = 1;
	while(n > 0)
	{
		long flag = n & 1;
		if(flag == 1)
			multi(base, e[counter]);
		n >>= 1;
		counter++;
	}
	cout<<base.d%mode;
	return 0;
}