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

struct info2 {
	int num;
	int weight;
};

bool operator<(info2 t, info2 u) {
	return t.weight > u.weight;
}

priority_queue<info2> pq;
vector<info> d[20001];
bool visited[20001];
int dist[20001];
int T, V, E, S;
int node1, node2, weight;

void Dijkstra();
int main()
{
	memset(dist, 100, sizeof(dist));
	scanf("%d %d %d", &V, &E, &S);
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &node1, &node2, &weight);
		d[node1].push_back({ node2,weight });
		//d[node2].push_back({ node1,weight });
	}
	dist[S] = 0;
	visited[S] = true;
	pq.push({ S,0 });
	Dijkstra();

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == 1684300900)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
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