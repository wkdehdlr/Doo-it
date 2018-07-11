#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int N, M, u, v, d, S, T;
vector< vector<tuple<int, int> > > edge;

vector<int> Dijkstra(int start) {
	vector<int> dist(N + 1, -1);
	priority_queue<pair<int, int> > pq; // first : dist , second : vertex_pos
	dist[start] = 0;
	pq.push(make_pair(-dist[start], start)); // Min-Heap처럼 사용하기 위해 앞의 거리 인자에 -값을 곱해줌.
	while (!pq.empty()) {
		int here = pq.top().second;
		int heredist = -pq.top().first;
		pq.pop();
		if (heredist > dist[here]) continue;
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i].first;
			int nextdist = heredist + edge[here][i].second;
			if (dist[there] == -1 || dist[there] > nextdist) { //최단 거리 갱신
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d", &N, &M);
		for (int m = 1; m <= M; ++m) {
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			edge[i].push_back(make_pair(j, k));
		}
		vector<int> dist = Dijkstra(1);
	}
}