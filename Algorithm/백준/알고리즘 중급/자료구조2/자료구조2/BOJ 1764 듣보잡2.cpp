#pragma warning(disable : 4996)
#include<iostream>
#include<unordered_set>
#include<queue>
#include<string>
#include<functional>
using namespace std;

unordered_set<string> st;
priority_queue<string,vector<string>,greater<string> > pq;

int N, M;
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	N += M;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		if (!st.insert(name).second)
			pq.push(name);
	}
	cout << pq.size() << '\n';
	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
}