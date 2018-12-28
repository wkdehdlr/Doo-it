#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
	int n;
	int dep;
};
int N;
int arr[200001];
int visited[200001];
vector<vector<int> > vec(200001);
queue<node> q;
int cnt = 0;
int mx = 0;
void BFS()
{
	while (!q.empty()) {
		node n = q.front();
		q.pop();

		for (int k = 0; k < vec[n.n].size(); ++k) {
			int ver = vec[n.n][k];
			if (visited[ver])continue;
			cnt += (arr[ver] * n.dep);
			visited[ver] = true;
			q.push({ ver,n.dep + 1 });
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	for (int i = 0; i < N - 1; ++i) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		vec[v1].push_back(v2);
		vec[v2].push_back(v1);
	}

	for (int i = 1; i <= N; ++i) {
		q.push({ i, 1 });
		visited[i] = true;
		BFS();
		mx = max(mx, cnt);
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	printf("%d\n", mx);
}