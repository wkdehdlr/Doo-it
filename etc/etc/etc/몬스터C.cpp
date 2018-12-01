#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;

struct info {
	int a, b, c;
};
bool operator<(info f, info g) {
	return f.b < g.b;
}
vector<int> healths = { 200,120,150 };
vector<vector<int>> items = { {30,100},{500,30},{100,400} };
priority_queue<info> pq;
vector<int> ans;
int N;
int main()
{
	N = healths.size();
	sort(healths.begin(), healths.end(), greater<int>());
	while (N--)pq.push({ items[N][0],items[N][1], N + 1});
	int i = 0;
	int ret = 0;
	while (!pq.empty() || i < N) {
		info tmp = pq.top();
		pq.pop();
		if (healths[i] - tmp.b >= 100) {
			ret += tmp.a;
			i++;
			ans.push_back(tmp.c);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ret);
}