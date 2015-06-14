#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<math.h>
#include<fstream>
using namespace std;



vector<int> c(4, 0);
string s[4];
string getString(int i)
{
	if(i == 11)
		return "J";
	else if(i == 12)
		return "Q";
	else if(i == 13)
		return "K";
	else if(i == 14)
		return "A";
	else if(i == 10)
		return "10";
	else 
	{
		ostringstream os;
		os<<i;
		return os.str();

	}
}
void toNum(vector<int> &c, string &s, int pos)
{
	if(s[0] == 'J')
		c[pos] = 11;
	else if(s[0] == 'Q')
		c[pos] = 12;
	else if(s[0] == 'K')
		c[pos] = 13;
	else if(s[0] == 'A')
		c[pos] = 14;
	else
	{
		int tmp = 0;
		for(int i = 0; i < s.length() - 1; i++)
			tmp = tmp * 10 + s[i] - '0';
		c[pos] = tmp;
	}
}
bool work(string ss)
{
	int i = 0;
	int nums = 0;
	for(i = 0; i < 4; i++)
		if(s[i].at(s[i].length()-1) == ss.at(ss.length()-1))
			nums++;
	if(nums == 4)
		return false;
	vector<int> tmp = c;
	tmp.push_back(1);
	toNum(tmp, ss, 4);
	sort(tmp.begin(), tmp.end());
	for(int i = 1; i < 5; i++)
		if(tmp[i] - tmp[i-1] != 1)
			return false;
	return true;
}
int main()
{
	int num = 4;
	set<string> st;
	for(int i = 0; i < num; i++)
	{
		cin>>s[i];
		toNum(c, s[i], i);
		st.insert(s[i]);
	}
	int ans = 0;
	for(int i = 2; i <= 14; i++)
	{
		string ss = getString(i);
		string sss = ss+"S";
		if(st.find(sss) == st.end() && work(sss))
			ans++;
		sss = ss + "H";
		if(st.find(sss) == st.end() && work(sss))
			ans++;
		sss = ss + "C";
		if(st.find(sss) == st.end() && work(sss))
			ans++;
		sss = ss + "D";
		if(st.find(sss) == st.end() && work(sss))
			ans++;
	}
	if(ans == 0)
	{
		cout<<"0/1\n";
		return 0;
	}
	int total = 48;
	for(int i = 2; i <= 24; i++)
	{
		if(ans % i == 0 && total % i == 0)
		{
			ans /= i;
			total /= i;
			i = 1;
		}
	}
	cout<<ans<<"/"<<total<<"\n";
	return 0;
}
