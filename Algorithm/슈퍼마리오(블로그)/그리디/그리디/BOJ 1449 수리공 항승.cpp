#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

bool visited[1001];
int arr[1001];
int N, L;
int cnt = 0;
int main()
{
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N + 1);
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[arr[i]])
		{
			cnt++;
			for (int k = arr[i], t = k + L - 1; k <= t; ++k)
			{
				visited[k] = true;
			}
		}
	}
	printf("%d\n", cnt);
}