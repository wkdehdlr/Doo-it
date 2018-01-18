#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

set<string> st;
string str;
int N, K;
struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

void preorder(node* cur)
{
	if (cur->left != NULL)
	{
		str += "L";
		preorder(cur->left);
		str += 'l';
	}
	if (cur->right != NULL)
	{
		str += "R";
		preorder(cur->right);
		str += 'r';
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		node root;
		node* cur = &root;
		cur->data = tmp;
		for (int j = 1; j < K; ++j)
		{
			cur = &root;
			scanf("%d", &tmp);
			while (1)
			{
				if (cur->data < tmp)
				{
					if (cur->right == NULL)
					{
						cur->right = new node;
						cur->right->data = tmp;
						break;
					}
					else
						cur = cur->right;
				}
				else
				{
					if (cur->left == NULL)
					{
						cur->left = new node;
						cur->left->data = tmp;
						break;
					}
					else
						cur = cur->left;
				}
			}
		}
		str="";
		cur = &root;
		preorder(cur);
		st.insert(str);
	}
	printf("%d\n", st.size());
}