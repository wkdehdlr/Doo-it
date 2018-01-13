#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int L, C;
char arr[15], tmp;
char new_arr[15];
void func(int n, string str)
{
	if (n == C)
	{
		if (str.size() == L)
		{
			int moumm = 0;
			int zaumm = 0;
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u' ||  str[i] == 'o')
					moumm++;
				else
					zaumm++;
			}
			if (moumm >= 1 && zaumm >= 2)
				cout << str << '\n';
		}
	}
	else
	{
		for (int i = 1; i >= 0; --i)
		{
			i ? func(n + 1, str + arr[n]) : func(n + 1, str);
		}
	}
}

int main()
{
	string str;
	scanf("%d %d%c", &L, &C, &tmp);

	for (int i = 0; i < C; ++i)
	{
		scanf("%c%c", &arr[i], &tmp);
	}
	sort(arr, arr + C);
	func(0,str);
	return 0;
}