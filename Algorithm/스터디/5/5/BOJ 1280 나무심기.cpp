#pragma warning(disable : 4996)
#include<cstdio>

long long tree_sum[1 << 19];
long long tree_cnt[1 << 19];
int N;
long long res = 1;
void update_sum(int idx)
{	
	int i = idx + (262144);//1<<18
	tree_sum[i] += idx;
	while (i > 1)
	{
		i /= 2;
		tree_sum[i] = tree_sum[i * 2] + tree_sum[i * 2 + 1];
	}
}
void update_cnt(int idx)
{
	idx += (262144);//1<<18
	tree_cnt[idx]++;
	while (idx > 1)
	{
		idx /= 2;
		tree_cnt[idx] = tree_cnt[idx * 2] + tree_cnt[idx * 2 + 1];
	}
}
long long sum_cnt(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return tree_cnt[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum_cnt(L, R, nodeNum * 2, nodeL, mid) + sum_cnt(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
long long sum_sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return tree_sum[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum_sum(L, R, nodeNum * 2, nodeL, mid) + sum_sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		long long tot = 0;
		int loca;
		scanf("%d", &loca);
		update_sum(loca);
		update_cnt(loca);
		if (i) {
			if (loca) {
				tot += (sum_cnt(0, loca - 1, 1, 0, (1 << 18) - 1) *loca - sum_sum(0, loca - 1, 1, 0, (1 << 18) - 1));//왼쪽
				tot += (sum_sum(loca + 1, (1 << 18) - 1, 1, 0, (1 << 18) - 1) - sum_cnt(loca + 1, (1 << 18) - 1, 1, 0, (1 << 18) - 1) *loca);//오른쪽
			}
			else {
				tot += (sum_sum(loca + 1, (1 << 18) - 1, 1, 0, (1 << 18) - 1) - sum_cnt(loca + 1, (1 << 18) - 1, 1, 0, (1 << 18) - 1) *loca);//오른쪽
			}
			res *= (tot % 1000000007);
			res %= 1000000007;
		}
	}
	printf("%lld\n", res % 1000000007);
}