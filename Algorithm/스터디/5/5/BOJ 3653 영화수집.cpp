#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int loca[100001];
int arr[(1 << 19) + 1];
int T, N, M, dep_s, dep_e;
void update(int idx, int data)
{
	//idx += (dep_e - N);
	arr[idx] = data;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
	}
}
int sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		dep_s = 1;
		memset(loca, 0, sizeof(loca));
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &M);
		while (N + M + 1 > dep_s)dep_s *= 2;

		dep_e = dep_s * 2;
		for (int i = 0; i < N; ++i)
		{
			update(dep_e - N + i, 1);
			loca[i + 1] = dep_e - N + i;
		}

		for (int i = 0; i < M; ++i)
		{
			int idx;
			scanf("%d", &idx);
			printf("%d ", sum(dep_s, loca[idx] - 1, 1, dep_s, dep_e - 1));
			update(loca[idx], 0);//현재위치를 0으로 갱신한다
			loca[idx] = dep_e - N - i - 1;
			update(loca[idx], 1);//새로운 위치에 1로 갱신
		}
		printf("\n");
	}
}