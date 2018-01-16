#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

string A, T;
deque<char> left_stack;
int L;

bool check_left()
{
	if (left_stack.size() >= T.size())
	{
		string tmp;
		for (int i = 0; i < T.size(); ++i)
		{
			tmp += left_stack.back();
			left_stack.pop_back();
		}

		reverse(tmp.begin(), tmp.end());
		if (tmp.compare(T))
		{
			for (int i = 0; i < T.size(); ++i)
			{
				left_stack.push_back(tmp[i]);
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
	for (L = 0; L < A.size(); ++L)
	{
		left_stack.push_back(A[L]);
		check_left();
	}
	if (left_stack.empty())
	{
		printf("FRULA\n");
		return 0;
	}
	while (!left_stack.empty())
	{
		printf("%c", left_stack.front());
		left_stack.pop_front();
	}
	printf("\n");
}