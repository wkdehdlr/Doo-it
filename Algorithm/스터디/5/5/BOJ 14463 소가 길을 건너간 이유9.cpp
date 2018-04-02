#pragma warning(disable : 4996)
#include<cstdio>

struct info {
	int one, two;
};
info inf[50001];
int arr[100001];
bool visited[50001];
int N;
int res = 0;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= 2 * N; ++i)
	{
		int num;
		scanf("%d", &num);
		arr[i] = num;
		if (inf[num].one) {
			inf[num].two = i;
		}
		else {
			inf[num].one = i;
		}
	}

	for (int i = 1; i <= 2 * N; ++i)
	{
		if (visited[arr[i]])continue;
		visited[arr[i]] = true;

		int L = inf[arr[i]].one;
		int R = inf[arr[i]].two;
		res += (R - L - 1);
		for (int j = L + 1; j < R; ++j)
		{
			if (L < inf[arr[j]].one && inf[arr[j]].two < R)res--;
		}
	}
	printf("%d\n", res / 2);
}