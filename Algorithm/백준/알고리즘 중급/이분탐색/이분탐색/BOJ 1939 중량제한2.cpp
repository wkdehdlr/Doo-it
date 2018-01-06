#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int maxN = 0;
bool visited[10001];
vector<pair<int, int> > vec[100001];
queue<int> q;
int N, M;
int endd;

bool BFS(int mid)
{
	while (!q.empty())
	{
		int start = q.front();
		q.pop();
		if (start == endd)
			return true;
		visited[start] = true;
		for (auto &p : vec[start])
		{
			if (!visited[p.first] && p.second >= mid)
				q.push(p.first);
		}
	}
	return false;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int sum1, sum2, w;
		scanf("%d %d %d", &sum1, &sum2, &w);
		vec[sum1].push_back({ sum2, w });
		vec[sum2].push_back({ sum1, w });
	}
	int start;
	scanf("%d %d", &start, &endd);
	int left = 1;
	int right = 1000000000;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		memset(visited, false, sizeof(visited));
		while (!q.empty())q.pop();
		q.push(start);
		if (BFS(mid))
			left = mid+1;
		else
			right = mid-1;
	}
	printf("%d\n", right);
}