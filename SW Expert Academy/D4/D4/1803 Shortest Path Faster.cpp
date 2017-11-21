#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


struct info {
	int des;
	int weight;
};

struct info2{
	int num;
	int weight;
};

bool operator<(info2 t, info2 u) {
	return t.weight > u.weight;
}

priority_queue<info2> pq;
vector<info> d[100001];
bool visited[1000001];
int dist[100001];
int T, N, M, S, E;
int node1, node2, weight;

void Dijkstra();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(visited, false, sizeof(bool)*100001);
		for (int i = 0; i < 100001; ++i)
		{
			dist[i] = 0x7fffffff;
		}

		scanf("%d %d %d %d", &N, &M, &S, &E);
		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d %d", &node1, &node2, &weight);
			d[node1].push_back({ node2,weight });
			d[node2].push_back({ node1,weight });
		}
		dist[S] = 0;
		visited[S] = true;
		pq.push({ S,0 });
		Dijkstra();

		printf("#%d %d\n", tc + 1, dist[E]);
		for (int i = 1; i <= N; ++i)
		{
			if (!d[i].empty())
			{
				d[i].clear();
			}
		}
	}
}
void Dijkstra()
{
	while (!pq.empty())
	{
		int num = pq.top().num;
		int weight = pq.top().weight;
		pq.pop();
		visited[num] = true;
		int size = d[num].size();
		for (int i = 0; i < size; ++i)
		{
			if (weight + d[num][i].weight < dist[d[num][i].des] && visited[d[num][i].des] == false)
			{
				dist[d[num][i].des] = weight + d[num][i].weight;
				pq.push({ d[num][i].des ,dist[d[num][i].des] });
			}
		}
	}
}