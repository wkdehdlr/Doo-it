#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int N, K, N2 = 1;
int arr[1 << 18];
void update(int idx, int data)
{
	idx += N2;
	arr[idx] = data;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx] = arr[idx * 2] * arr[idx * 2 + 1];
	}
}
int mul(int L, int R, int nodeNum, int NodeL, int NodeR)
{
	if (R < NodeL || NodeR < L)return 1;
	if (L <= NodeL && NodeR <= R)return arr[nodeNum];

	int mid = (NodeL + NodeR) / 2;
	return mul(L, R, nodeNum * 2, NodeL, mid) * mul(L, R, nodeNum * 2 + 1, mid + 1, NodeR);
}
int main()
{
	while (~scanf("%d", &N)) {
		scanf("%d", &K);
		N2 = 1;
		memset(arr, 0, sizeof(arr));
		while (N > N2) {
			N2 *= 2;
		}
		for (int i = 0; i < N; ++i) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp > 0)tmp = 1;
			else if (tmp < 0)tmp = -1;
			else tmp = 0;
			update(i, tmp);
		}
		for (int i = 0; i < K; ++i)
		{
			char str[2];
			int idx, V;
			scanf("%s %d %d", str, &idx, &V);
			if (str[0] == 'C') {
				if (V > 0)V = 1;
				else if (V < 0)V = -1;
				else V = 0;
				update(idx - 1, V);
			}
			else {//V
				int res = mul(idx - 1, V - 1, 1, 0, N2 - 1);
				if (res==0)printf("0");
				else if (res > 0)printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
}