#pragma warning(disable : 4996)
#include<cstdio>
int N, M;
int arr[301][301];
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= 300; ++i) {
		arr[i][1] = i - 1;
		for (int j = 2; j <= 300; ++j) {
			arr[i][j] = arr[i][j - 1] + i;
		}
	}
	printf("%d\n", arr[N][M]);
}