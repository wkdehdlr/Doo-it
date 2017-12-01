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
priority_queue<info> pq_temp[16];
bool operator<(info t, info u) {
	return t.data < u.data;
}
int visited[16];
int N, T, temp;
double sum, maxN;

void func();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		maxN = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%d", &temp);
				pq[i].push({ i, j,temp });
			}
		}

		for (int i = 0; i < 16; ++i)
		{
			pq_temp[i] = pq[i];
		}

		for (int i = 0; i < N; ++i)
		{
			visited[pq[i].top().y] = pq[i].top().data;
			pq[i].pop();
			for (int j = 0; j < N; ++j)
			{
				if (i != j)
				{
					max_pq.push(pq[j].top());
					pq[j].pop();
				}
			}
			sum = 1;
			func();
			printf("%lf\n", sum * 100);
			//if (maxN < sum)
				//maxN = sum;
			for (int i = 0; i < N; ++i)
			{
				visited[i] = 0;
			}
			if (i == N - 1)
			{
				for (int i = 0; i < N; ++i)
				{
					while (!pq[i].empty())
					{
						pq[i].pop();
					}
				}
			}
			else
			{
				for (int i = 0; i < N; ++i)
				{
					pq[i] = pq_temp[i];
				}
			}
		}
		//printf("#%d %lf\n", tc + 1, maxN * 100);
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