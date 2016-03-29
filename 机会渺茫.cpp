#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
typedef long long ll;
using namespace std;



ll gcd(ll a, ll b)
{
	if(a < b)
		return gcd(b, a);
	while(a % b != 0)
	{
		ll c = a % b;
		a = b;
		b = c;
	}
	return b;
}
int nums(ll a)
{
	int r = 0;
	ll half = sqrt(1.0*a);
	for(int i = 1; i <= half; i++)
		if(a % i == 0)
			r += 2;
	if(half * half == a)
		r -= 1;
	return r;
}
int main()
{
	ll a, b;
	cin>>a>>b;
	ll aa = nums(a) * nums(b);
	ll bb = nums(gcd(a, b));
	ll cc = gcd(aa, bb);
	cout<<aa/cc<<" "<<bb/cc<<"\n";
	return 0;
}