#pragma warning(disable : 4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int arr2[100000];
int arr[1001];
int min;

int main()
{
	int t,N;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		memset(arr2, 0, sizeof(arr2));
		min = 1000000;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			int temp = 0;
			scanf("%d", &arr[i]);
			if (arr[i] > 0)
				temp = arr[i];
			else
				temp = -arr[i];

			if (min > temp)
				min = temp;				

			arr2[temp]++;
		}
		printf("#%d %d %d\n", tc + 1, min, arr2[min]);
	}
}