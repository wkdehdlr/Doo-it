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
		// ���ͽ�Ʈ�� �˰���
		dist[i][i] = 0; // ������������ �Ÿ��� 0
		PQ.push(P(0, i)); // �������� PQ�� �ְ� ����
		while (!PQ.empty()) { // PQ�� ��� ����
			int curr;
			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[i][curr]); // curr�� �湮�� �����̸� ����
			// �� �̻� �湮�� �� �ִ� ������ ������ ����
			if (visited[i][curr]) break;

			visited[i][curr] = true; // �湮
			for (auto &p : vec[curr]) {
				int next = p.first, d = p.second;
				// �Ÿ��� ���ŵ� ��� PQ�� ���� ����
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
	// base case: ��� ������ �湮��
	if (visit == (1 << (K + 1)) - 1) {
		if (dist[town[current]][town[0]] != INF) return dist[town[current]][town[0]];
		return IMPOSSIBLE; // ���������� �� �� ����
	}

	ret = IMPOSSIBLE;
	for (int i = 0; i <= K; i++) {
		// i�� ������ �̹� �湮�߰ų� i�� ������ �� �� ����
		if (visit & (1 << i) || dist[town[current]][town[i]] == INF) continue;
		// �� ��
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