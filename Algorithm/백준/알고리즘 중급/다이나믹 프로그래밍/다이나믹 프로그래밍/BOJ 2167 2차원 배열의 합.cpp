#pragma warning(disable : 4996)
#include<cstdio>

int arr[301][301];
int N, M, K;
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	scanf("%d", &K);
	for (int tc = 0; tc < K; ++tc) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2 && y1 == y2) {
			printf("%d\n", arr[x1][y1] - arr[x1][y1 - 1]);
			continue;
		}
		if (x1 == x2) {
			printf("%d\n", arr[x1][y2] - arr[x1][y1 - 1]);
			continue;
		}
		if (y1 == y2) {
			int ret = 0;
			for (int i = x1; i <= x2; ++i) {
				ret += (arr[i][y1] - arr[i][y1 - 1]);
			}
			printf("%d\n", ret);
			continue;
		}
		int ret = 0;
		for (int i = x1; i <= x2; ++i) {
			ret += (arr[i][y2] - arr[i][y1 - 1]);
		}
		printf("%d\n", ret);
	}
}