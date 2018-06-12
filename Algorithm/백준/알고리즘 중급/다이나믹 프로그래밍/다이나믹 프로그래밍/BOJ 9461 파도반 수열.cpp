#pragma warning(disable : 4996)
#include<cstdio>
typedef long long ll;
ll arr[101];
int N, T;
int main()
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i <= 100; ++i)
		arr[i] = arr[i - 1] + arr[i - 5];
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
}