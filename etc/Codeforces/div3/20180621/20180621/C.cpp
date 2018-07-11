#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

struct info {
	char a;
	int idx;
};
bool operator<(info f, info g)
{
	return f.idx > g.idx;
}
priority_queue<info> pq;
int N, K;
char str[400001];
vector<char> vec;
priority_queue<int, vector<int>, greater<int>> arr[30];

void func()
{
	for (int i = 0; i < 26; ++i) {
		if (!arr[i].empty()) {
			arr[i].pop();
			return;
		}
	}
}

int main()
{
	scanf("%d %d %s", &N, &K, str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		arr[str[i] - 'a'].push(i);
	}
	for (int i = 0; i < K; ++i) {
		func();
	}
	for (int i = 0; i < 26; ++i) {
		while (!arr[i].empty()) {
			pq.push({ (char)(i + 'a') ,arr[i].top() });
			arr[i].pop();
		}
	}
	while (!pq.empty()) {
		printf("%c", pq.top().a);
		pq.pop();
	}
}