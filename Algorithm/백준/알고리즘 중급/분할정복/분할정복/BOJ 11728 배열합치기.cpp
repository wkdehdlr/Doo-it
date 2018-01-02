#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[1000000];
int brr[1000000];
int crr[2000002];
int N, M, a, b, c;
int main()
{
	c = 0; a = 0; b = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < M; ++i)
		scanf("%d", &brr[i]);

	while (a < N && b < M)
	{
		if (arr[a] < brr[b])
			crr[c++] = arr[a++];
		else
			crr[c++] = brr[b++];
	}
	while (a < N)
	{
		crr[c++] = arr[a++];
	}
	while (b < M)
	{
		crr[c++] = brr[b++];
	}

	for (int i = 0; i < c; ++i)
		printf("%d ", crr[i]);
}