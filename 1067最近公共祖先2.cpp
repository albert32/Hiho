#include"string.h"
#include"stdio.h"
#include"stdlib.h"
#include"iostream"
#include"vector"
#include"string"
#include"map"
#include"time.h"
#include"unordered_map"
#include"queue"
#include"set"
using namespace std;

struct node
{
	int parent;
	vector<int> son;
};

struct question
{
	int ans;
	int p[2];
	bool has;
	question()
	{
		has = false;
	};
};
unordered_map<string, int> father;
unordered_map<int, string> fatherInt;

int num;
unordered_map<string, int>::iterator it;
int n, m;


const int nums = 100010;
node people[nums];
question ques[nums];
vector<int> questionIndex[nums];
int color[nums];
int getIndex(string s)
{
	it = father.find(s);
	if(it == father.end())
	{
		num++;
		people[num].parent = -1;
		father.insert(make_pair(s, num));
		fatherInt.insert(make_pair(num, s));
		return num;
	}
	return it->second;
}

int getIndex2(string s)
{
	it = father.find(s);
	if(it == father.end())
		return -1;
	return it->second;
}

void visit(int index)
{
	color[index]++;
}
int findParent(int index)
{
	if(color[index] == 1)
		return index;
	people[index].parent = findParent(people[index].parent);
	return people[index].parent;
}
void dfs(int nextNode, int fatherNode)
{
	visit(nextNode);
	vector<int> &vec = questionIndex[nextNode];
	for(int i = 0; i < vec.size(); i++)
	{
		int check;
		if(ques[vec.at(i)].has == true)
			continue;
		if(ques[vec.at(i)].p[0] != nextNode)
			check = ques[vec.at(i)].p[0];
		else
			check = ques[vec.at(i)].p[1];

		if(color[check] == 0)
			continue;
		check = findParent(check);
		ques[vec.at(i)].ans = check;
		ques[vec.at(i)].has = true;

	}
	for(int i = 0; i < people[nextNode].son.size(); i++)
			dfs(people[nextNode].son.at(i), nextNode);
	visit(nextNode);
}
int main()
{
	num = -1; 
	cin>>n;
	string s1, s2;
	int index1, index2;
	memset(color, 0, sizeof(color));
	for(int i = 0; i < n; i++)
	{
		cin>>s1>>s2;
		index1 = getIndex(s1);
		index2 = getIndex(s2);
		people[index2].parent = index1;
		people[index1].son.push_back(index2);
	}

	cin>>m;
	for(int i = 0; i < m; i++)
	{
		cin>>s1>>s2;
		index1 = getIndex2(s1);
		index2 = getIndex2(s2);
		ques[i].p[0] = index1;
		ques[i].p[1] = index2;
		questionIndex[index1].push_back(i);
		questionIndex[index2].push_back(i);

	}
	dfs(0, 0);
	for(int i = 0; i < m; i++)
		cout<<fatherInt[ques[i].ans]<<"\n";
	return 0;
}