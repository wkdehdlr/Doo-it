#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;
struct info {
	int y;
	int h;
};
bool operator<(info f, info g)
{
	return f.y < g.y;
}
int arr[10001];
info mrr[301];
int N, M, K, T;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d %d", &N, &M, &K);
		if (K) {
			printf("Case #%d\n%d\n", tc + 1, 1);
			continue;
		}
		for (int i = 0; i < N; ++i)scanf("%d", &arr[i]);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &mrr[i].y);
			mrr[i].h = i;
		}
		sort(mrr, mrr + M);
		int ret = 0;
		for (int i = 0; i + M <= N; ++i) {
			bool ok = true;
			for (int j = 0; j < M - 1; ++j) {
				if (arr[mrr[j].h + i] > arr[mrr[j + 1].h + i]) {
					ok = false;
					break;
				}
			}
			if (ok)ret++;
		}
		printf("Case #%d\n%d\n", tc + 1, ret);
	}
}