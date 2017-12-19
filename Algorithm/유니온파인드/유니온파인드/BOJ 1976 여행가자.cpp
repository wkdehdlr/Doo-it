#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int N, M, temp;
int arr[201];
int n1, n2;

int find(int);
void merge(int, int);

int main()
{
	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &temp);
			if (temp)
				merge(i, j);
		}
	}

	scanf("%d", &n1);
	for (int i = 2; i <= M; ++i)
	{
		scanf("%d", &n2);
		if (find(n1) != find(n2))
		{
			printf("NO\n");
			return 0;
		}
		n1 = n2;
	}
	printf("YES\n");
}

int find(int n)
{
	if (arr[n] < 0)return n;
	return arr[n] = find(arr[n]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)return;
	arr[b] = a;
}