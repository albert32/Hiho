#includestdlib.h
#includeiostream
#includestring
#includemath.h
typedef long long ll;
using namespace std;

ll add(ll a, ll b, ll n)
{
    if(a  100000000 && b  10000000)
        return (a  b) % n;
	if(b == 1)
		return a % n;
	else if((b & 1) == 0)
	{
		ll tmp = add(a, b1, n);
		return (tmp % n + tmp % n) % n;
	}
	else
	{
		ll tmp = add(a, b1, n);
		ll ans = (tmp % n + tmp % n) % n;
		return (ans + (a % n) ) % n;
	}
}
ll mode(ll a, ll u, ll n)
{
	if(u == 1)
		return a % n;
	if((u & 1) == 0)
	{
		ll tmp = mode(a, u  1, n) % n;
		return add(tmp, tmp, n);
	}
	else
	{
		ll tmp = mode(a, u 1 , n) % n;
		ll ans = add(tmp, tmp, n);
		return (ans  a) % n;
	}
}
bool isPrime(ll a, ll n)
{

	if(n = 1)
		return false;
	else if(n == 2)
		return true;
	else if((n & 1) == 0)
		return false;
	ll u = n - 1;
	while((u & 1)  == 0)
		u = 1;
	ll x = mode(a, u, n);
	while(u  n)
	{
		ll y = add(x , x, n);
		if(y == 1 && x != 1 && x != n-1)
			return false;
		x = y;
		u = 1;
	}
	if(x != 1)
		return false;
	return true;
}
int main()
{
	coutmode(2,3,12) (int)pow(2.0,3)%12n;
	const int a_nums = 12, test = 1;
	int a[a_nums] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	int t;
	ll n;
	cint;
	while(t--)
	{
		cinn;
		bool in = false;
		for(int i = 0; i  test; i++)
			if(a[i] == n)
				in = true;
		if(in == true)
		{
			coutYesn;
			continue;
		}
		int i;
		for(i = 0; i  test; i++)
		{
			if(!isPrime(a[i], n))
			{
				coutNon;
				break;
			}
		}
		if(i == test)
			coutYesn;
	}
	return 0;
}