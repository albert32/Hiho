#include<iostream>
#include<algorithm>
#include<string>
#include<iterator>
#include<unordered_map>
using namespace std;

struct node
{
	string key;
	node *next, *pre;
};
unordered_map<string, node *> cache;
node *head, *tail;
int n, m;
int size = 0;
string removeLast()
{
	node *t = tail->pre;
	string ans = t->key;
	node *t1 = t->pre;
	t1->next = tail;
	tail->pre = t1;
	delete t;
	return ans;
};
void insertToHead(node *t)
{
	node *next = head->next;
	head->next = t;
	t->pre = head;

	t->next = next;
	next->pre = t;
}
void removeNoDelete(node *t)
{
	node *pre = t->pre;
	node *next = t->next;
	pre->next = next;
	next->pre = pre;
}
int main () 
{
	head = new node();
	tail = new node();
	head->pre = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->pre = head;
	cin>>n>>m;
	string s;
	unordered_map<string, node*>::iterator it;
	while(n--)
	{
		cin>>s;
		if(s.length() == 0)
		{
			n++;
			continue;
		}
		it = cache.find(s);

		//没在缓存
		if(it == cache.end())
		{
			node *tmp = new node();
			tmp->key = s;
			//插入缓存
			cache.insert(make_pair(s, tmp));
			if(size >= m)
			{
				string ans = removeLast();
				cache.erase(ans);
			}
			size++;
			insertToHead(tmp);
			printf("Internet\n");
		}
		else
		{
			node *t = it->second;
			removeNoDelete(t);
			insertToHead(t);
			printf("Cache\n");
		}
	}
	return 0;
}
 