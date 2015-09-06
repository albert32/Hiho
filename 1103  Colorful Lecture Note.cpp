#include<string>
#include<iostream>
#include<map>
#include<stack>
using namespace std;

#define red 1100
#define yellow 1101
#define blue 1102
int getColor(char c)
{
	if(c == 'y')
		return yellow;
	else if(c == 'b')
		return blue;
	else
		return red;
}
int main()
{
	map<int, int> counter;
	counter[red] = 0, counter[yellow] = 0, counter[blue] = 0;
	string s;
	getline(cin, s);
	stack<int> stk;
	int i = 0;
	while(i < s.length())
	{
		if(s[i] == ' ')
		{
		    i++;
			continue;
		}
		if(s[i] == '<' && s[i+1] != '/') //start
		{
			i++;
			int c = getColor(s[i]);
			while(s[i] != '>')
				i++;
			i++;
			stk.push(c);
		}
		else if(s[i] == '<' && s[i+1] == '/') //end
		{
			int num = 0;
			while(!stk.empty() && stk.top() < 1100)
			{
				num += stk.top();
				stk.pop();
			}
			stk.pop();
			i += 2;
			int c = getColor(s[i]);
			counter[c] = counter[c] + num;
			while(s[i] != '>')
				i++;
			i++;
		}
		else
		{
			int num = 0;
			while(i < s.length() && s[i] != '<')
			{
				if(s[i] != ' ')
					num++;
				i++;
			}
			stk.push(num);
		}

	}
	cout<<counter[red]<<" "<<counter[yellow]<<" "<<counter[blue]<<"\n";
	return 0;
}