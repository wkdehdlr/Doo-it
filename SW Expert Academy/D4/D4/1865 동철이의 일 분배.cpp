#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;

struct info {
	int x;
	int y;
	int data;
};
priority_queue<info> max_pq;
priority_queue<info> pq[16];
bool operator<(info t, info u) {
	return t.data < u.data;
}
int visited[16];
int N, T,temp;
double sum;

void func();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		sum = 1;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%d", &temp);
				pq[i].push({i, j,temp });
			}
		}
		for (int i = 0; i < N; ++i)
		{
			max_pq.push(pq[i].top());
			pq[i].pop();
		}
		func();
		printf("#%d %lf\n", tc + 1, sum * 100);
		for (int i = 0; i < N; ++i)
		{
			visited[i] = 0;
			while (!pq[i].empty())
			{
				pq[i].pop();
			}
		}
	}
}
void func()
{
	while (!max_pq.empty())
	{
		int data = max_pq.top().data;
		int x = max_pq.top().x;
		int y = max_pq.top().y;
		max_pq.pop();
		if (!visited[y])
		{
			visited[y] = data;
		}
		else
		{
			max_pq.push(pq[x].top());
			pq[x].pop();
		}
	}

	for (int i = 0; i < N; ++i)
	{
		sum *= (visited[i] * 0.01);
	}
}