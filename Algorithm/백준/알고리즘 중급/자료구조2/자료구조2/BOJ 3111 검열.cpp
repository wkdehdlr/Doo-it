#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<stack>
#include<string.h>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string A, T;
stack<char> left_stack;
stack<char> right_stack;
int L, R;

bool check_right()
{
	if (right_stack.size() >= A.size())
	{
		string tmp;
		for (int i = 0; i < A.size(); ++i)
		{
			tmp += right_stack.top();
			right_stack.pop();
		}

		if (tmp.compare(A))
		{
			for (int i = A.size() - 1; i >=0 ; --i)
			{
				right_stack.push(tmp[i]);
			}
			return false;
		}
		else
			return true;
	}
	else
		return false;
}
bool check_left()
{
	if (left_stack.size() >= A.size())
	{
		string tmp;
		for (int i = 0; i < A.size(); ++i)
		{
			tmp += left_stack.top();
			left_stack.pop();
		}

		reverse(tmp.begin(), tmp.end());
		if (tmp.compare(A))
		{
			for (int i = 0; i < A.size(); ++i)
			{
				left_stack.push(tmp[i]);
			}
			return false;
		}
		else
			return true;
	}
	else
		return false;
}
int main()
{
	cin >> A >> T;
	string tmp;
	for (L = 0, R = T.size() - 1; L <= R; ++L)
	{
		left_stack.push(T[L]);
		if (check_left())
		{
			for (; R > L; --R)
			{
				right_stack.push(T[R]);
				if (check_right())
				{
					R--;
					break;
				}
			}
		}
	}
	while (!left_stack.empty())
	{
		right_stack.push(left_stack.top());
		left_stack.pop();
		check_right();
	}
	while (!right_stack.empty())
	{
		printf("%c", right_stack.top());
		right_stack.pop(); 
	}
	printf("\n");
}