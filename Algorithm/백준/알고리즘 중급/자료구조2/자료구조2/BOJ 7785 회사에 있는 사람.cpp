#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

set<string> st;
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string name, log;
		cin >> name >> log;
		if (!log.compare("enter"))
		{
			st.insert(name);
			continue;
		}
		if (!log.compare("leave"))
		{
			st.erase(name);
			continue;
		}
	}
	for (auto it = st.rbegin(); it != st.rend(); ++it)
		cout << *it << '\n';
}