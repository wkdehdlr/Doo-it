#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
int sort_arr[100001];
int T, N;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &arr[i]);
			sort_arr[i] = arr[i];
		}
		sort(sort_arr, sort_arr + N);
		bool done = false;
		while (!done)
		{
			done = true;
			for (int i = 0; i < N - 2; ++i)
			{
				if (arr[i] > arr[i + 2]) {
					done = false;
					swap(arr[i], arr[i + 2]);
				}
			}
		}
		printf("Case #%d: ", tc + 1);
		done = true;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] != sort_arr[i]) {
				done = false;
				printf("%d\n", i);
				break;
			}
		}
		if (done)printf("OK\n");
	}
}