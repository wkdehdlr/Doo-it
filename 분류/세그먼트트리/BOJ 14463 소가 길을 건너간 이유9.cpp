#pragma warning(disable : 4996)
#include<cstdio>

int visit[50001];
int seg[1 << 18];
int N;
int dep = 1;
int tot = 0;
void update(int idx, int data)
{
	idx += dep;
	seg[idx] = data;
	while (idx > 1)
	{
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
int sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	scanf("%d", &N);
	while (2 * N > dep)dep *= 2;
	for (int i = 0; i < 2 * N; ++i)
	{
		int num;
		scanf("%d", &num);
		if (!visit[num]) {
			visit[num] = i + 1;
			update(i, 1);
		}
		else {
			update(visit[num] - 1, -1);//원래꺼 -1로 세팅
			update(i, 1);//현재를 1로 세팅
			tot += sum(visit[num] - 1, i, 1, 0, dep - 1);
		}
	}
	printf("%d\n", tot / 2);
}