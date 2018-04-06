#pragma warning(disable : 4996)
#include<cstdio>

long long arr[1000001];
int N, B, C;
long long res = 0;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%lld", &arr[i]);
	scanf("%d %d", &B, &C);
	for (int i = 1; i <= N; ++i)
	{
		res++;//총감독관증가
		arr[i] -= B;
		if (arr[i] <= 0)continue;
		res += (arr[i] / C);
		if (arr[i] % C)res++;
	}
	printf("%lld\n", res);
}