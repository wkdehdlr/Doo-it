#pragma warning(disable : 4996)
#include<cstdio>

int N, N2 = 1;
int st[1 << 18];
int arr[100001];
void update(int idx, int data)
{
	idx += N2;
	st[idx] = data;
	while (idx > 1) {
		idx /= 2;
		st[idx] = st[idx * 2] + st[idx * 2 + 1];
	}
}
int sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R)return st[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main()
{
	scanf("%d", &N);
	while (N > N2)N2 *= 2;
	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);
		arr[temp] = i;
		update(i, 1);
	}

	for (int i = 0, num1 = 1, num2 = N; i < N; ++i) {
		int num = 0;
		if (!((i + 1) % 2)) {//Â¦¼ö
			num = num2--;
			printf("%d\n", sum(arr[num] + 1, N - 1, 1, 0, N2 - 1));
		}
		else {//È¦¼ö
			num = num1++;
			printf("%d\n", sum(0, arr[num] - 1, 1, 0, N2 - 1));
		}
		update(arr[num], 0);
	}
}