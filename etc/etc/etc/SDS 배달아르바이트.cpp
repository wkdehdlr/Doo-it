//#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
const int IMPOSSIBLE = 1000000000;
const int MAX_V = 1010;
const int INF = 1000000000;
typedef pair<int, int> P;
int T, N, M, K, S;
vector<int> town;
vector<P> vec[1001];
int dist[MAX_V][MAX_V];
bool visited[MAX_V][MAX_V];
priority_queue<P, vector<P>, greater<P>> PQ;
int dp[12][1 << 13];
void input()
{
	memset(dp, -1, sizeof(dp));
	town.clear();
	while (!PQ.empty())PQ.pop();
	for (int i = 1; i <= N; ++i)vec[i].clear();

	scanf("%d %d %d %d", &N, &M, &K, &S);
	town.push_back(S);
	for (int i = 0; i < K; ++i) {
		int tmp;
		scanf("%d", &tmp);
		town.push_back(tmp);
	}
	sort(town.begin(), town.end());
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		vec[v1].push_back(P(v2, 1));
		vec[v2].push_back(P(v1, 1));
	}
}
void dijkstra()
{
	for (int i = 1; i <= N; ++i) {
		fill(dist[i], dist[i] + (N + 1), INF);
		fill(visited[i], visited[i] + (N + 1), 0);
		// 다익스트라 알고리즘
		dist[i][i] = 0; // 시작점으로의 거리는 0
		PQ.push(P(0, i)); // 시작점만 PQ에 넣고 시작
		while (!PQ.empty()) { // PQ가 비면 종료
			int curr;
			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[i][curr]); // curr가 방문한 정점이면 무시
			// 더 이상 방문할 수 있는 정점이 없으면 종료
			if (visited[i][curr]) break;

			visited[i][curr] = true; // 방문
			for (auto &p : vec[curr]) {
				int next = p.first, d = p.second;
				// 거리가 갱신될 경우 PQ에 새로 넣음
				if (dist[i][next] > dist[i][curr] + d) {
					dist[i][next] = dist[i][curr] + d;
					PQ.push(P(dist[i][next], next));
				}
			}
		}
	}
}
int func(int current, int visit)
{
	int &ret = dp[current][visit];
	if (ret != -1) return ret;
	// base case: 모든 마을을 방문함
	if (visit == (1 << (K + 1)) - 1) {
		if (dist[town[current]][town[0]] != INF) return dist[town[current]][town[0]];
		return IMPOSSIBLE; // 시작점으로 갈 수 없음
	}

	ret = IMPOSSIBLE;
	for (int i = 0; i <= K; i++) {
		// i번 마을을 이미 방문했거나 i번 마을로 갈 수 없음
		if (visit & (1 << i) || dist[town[current]][town[i]] == INF) continue;
		// 그 외
		ret = min(ret, func(i, visit | (1 << i)) + dist[town[current]][town[i]]);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		input();
		dijkstra();
		printf("#%d %d\n", tc + 1, func(0, 1));
	}
}