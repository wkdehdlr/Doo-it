#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;


int N, T, K;
int arr[200010];
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
		sort(arr + 1, arr + N + 1);

		int ret = 0, mx = 0;;
		for (int i = 1, j = 2; i <= N; ++i) {
			ret = 0;
			if (i == j)j++;
			for (; j <= N; ++j) {
				if (arr[j] - arr[i] > K) {
					ret = j - i;
					break;
				}
			}
			if (j == N + 1)ret = j - i;
			mx = max(ret, mx);
		}
		printf("Case #%d\n%d\n", tc + 1, mx);
	}
}