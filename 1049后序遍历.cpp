#include<string>
#include<iostream>
#include<map>
#include<stack>
using namespace std;

int m[26];
void dfs(string &pre, int p_l, int p_r, string &inorder, int i_l, int i_r)
{
	if(p_l > p_r || i_l > i_r)
		return;
	int in_pos = m[pre[p_l]-'A'];
	int left_nums = in_pos - i_l, right_nums = i_r - in_pos;
	dfs(pre, p_l + 1, p_l + left_nums, inorder, i_l, in_pos-1);
	dfs(pre, p_l+left_nums+1, p_r, inorder, in_pos+1, i_r);
	cout<<(char)pre[p_l];
}
int main()
{
	string pre, inorder;
	cin>>pre>>inorder;
	for(int i = 0; i < inorder.length(); i++)
		m[inorder[i] - 'A'] = i;
	dfs(pre, 0, pre.length()-1, inorder, 0, inorder.length()-1);
	return 0;
}