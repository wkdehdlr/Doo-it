#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

#define min(x,y) x>y?y:x;
int N, K;
int main()
{
	scanf("%d %d", &N, &K);

	int left = 1;
	int right = 1000000000;
	int mid;
	while (left <= right)
	{
		int cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; ++i)
		{
			cnt += min(mid / i, N);//행마다 mid보다 작은수가 몇개인지 구함
		}

		if (cnt >= K)
		{
			right = mid - 1;
		}
		else if (cnt < K)
		{
			left = mid + 1;
		}
	}
	printf("%d\n", left);
}