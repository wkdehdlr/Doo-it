#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M;
int arr[101][2];
int dp[10001];
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i][0]);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i][1]);

	for (int i = 1; i <= N; ++i) 
		for (int j = 10000; j >= arr[i][1]; --j) //j�� ���
				dp[j] = max(dp[j], dp[j - arr[i][1]] + arr[i][0]);
				//n��° ���� ��Ȱ��ȭ ������ ���� �� �ִ� �ִ� �޸�

	int ret = 0;
	while (dp[ret] < M)ret++;
	printf("%d\n", ret);
}