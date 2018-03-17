#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
int N, M, K, N2;
ll arr[(1 << 21) + 1];
ll arrpow[21];
void update(int idx, int val)
{
	idx += (N2 - 1);
	arr[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
	}
}
ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	for (int i = 1; i <= 20; ++i)
	{
		arrpow[i] = 1 << i;
	}

	scanf("%d %d %d", &N, &M, &K);
	N2 = *(upper_bound(arrpow, arrpow + 20, N));
	for (int i = N2; i < 2 * N2; ++i)arr[i] = 0;
	for (int i = 1; i <= N; ++i) {
		ll temp;
		scanf("%lld", &temp);
		update(i, temp);
	}


	for (int i = 0; i < M + K; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(b, c);
		}
		else {
			printf("%lld\n", sum(b - 1, c - 1, 1, 0, N2 - 1));
		}
	}
}