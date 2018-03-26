#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

struct info {
	int num;
	int mx=0;
	int mn=0x7fffffff;
};
int N, M, N2;
info arr[1 << 18];
int twopow[19];

void update(int idx, int data)
{
	idx += N2;
	arr[idx].num = data;
	arr[idx].mn = data;
	arr[idx].mx = data;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx].mx = arr[idx * 2].mx < arr[idx * 2 + 1].mx ? arr[idx * 2 + 1].mx : arr[idx * 2].mx;
		arr[idx].mn = arr[idx * 2].mn > arr[idx * 2 + 1].mn ? arr[idx * 2 + 1].mn : arr[idx * 2].mn;
	}
}
info func(int L, int R, int nodeNum, int NodeL, int NodeR)
{
	if (R < NodeL || NodeR < L) return { 0, 0, 0x7fffffff };
	if (L <= NodeL && NodeR <= R)return arr[nodeNum];

	int mid = (NodeL + NodeR) / 2;
	info tmp1, tmp2;
	tmp1 = func(L, R, nodeNum * 2, NodeL, mid);	
	tmp2 = func(L, R, nodeNum * 2 + 1, mid + 1, NodeR);

	tmp1.mx < tmp2.mx ? tmp1.mx = tmp2.mx : tmp1.mx;
	tmp1.mn > tmp2.mn ? tmp1.mn = tmp2.mn : tmp1.mn;
	return tmp1;
}
int main()
{
	for (int i = 0; i < 19; ++i)twopow[i] = 1 << i;
	scanf("%d %d", &N, &M);
	N2 = *(upper_bound(twopow, twopow + 19, N));
	for (int i = 0; i < N; ++i)
	{
		int temp;
		scanf("%d", &temp);
		update(i, temp);
	}
	for (int i = 0; i < M; ++i) {
		info inf;
		int a, b;
		scanf("%d %d", &a, &b);
		inf = func(a - 1, b - 1, 1, 0, N2 - 1);
		printf("%d %d\n", inf.mn, inf.mx);
	}
}