#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int n, m,T;
int flag, a, b;
int arr[1000001];
int find(int);
void merge(int, int);
int main()
{

	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		printf("#%d ", tc+1);
		memset(arr, -1, sizeof(arr));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &flag, &a, &b);
			if (flag)//find
				if (find(a) == find(b))
					printf("1");
				else
					printf("0");
			else//ÇÕÁýÇÕ
				merge(a, b);
		}
		printf("\n");
	}
}
int find(int n)
{
	if (arr[n] < 0)return n;
	arr[n] = find(arr[n]);
	return arr[n];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)return;
	arr[b] = a;
}