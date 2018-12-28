#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct edge {
	long long w;
	int v1, v2;
};
bool operator<(edge f, edge g)
{
	return f.w < g.w;
}
vector<edge> vec;
struct node {
	long long w;
	int idx;
}arr[200005];
bool operator<(node f, node g)
{
	return f.w < g.w;
}
int uf[200005]; // union-find 배열

// union-find의 find 연산
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

// union-find의 union 연산
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}
int N, M;
int main()
{
	memset(uf, -1, sizeof(uf));
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	if (N == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &arr[i].w);
		arr[i].idx = i;
	}
	sort(arr + 1, arr + (N + 1));
	for (int i = 2; i <= N; ++i) {
		vec.push_back({ arr[1].w + arr[i].w,arr[1].idx,arr[i].idx });
	}
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		long long w;
		scanf("%d %d %lld", &v1, &v2, &w);
		vec.push_back({ w,v1,v2 });
	}
	sort(vec.begin(), vec.end());

	long long res = 0, cnt = 0;
	for (int i = 0; ; i++) {
		if (merge(vec[i].v1, vec[i].v2)) {
			res += vec[i].w;
			if (++cnt == N - 1) break; // N-1개 간선을 뽑으면 나감
		}
	}
	printf("%lld\n", res);
}