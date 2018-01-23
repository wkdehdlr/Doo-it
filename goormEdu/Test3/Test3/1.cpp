#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string inp;
int point = 0;
int flag = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
	{
		if (inp[i] == 'O')
			point += flag++;
		else
			flag = 1;
	}
	cout << point << '\n';
}