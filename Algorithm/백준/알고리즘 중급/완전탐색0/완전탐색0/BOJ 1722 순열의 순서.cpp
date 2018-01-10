#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

bool visited[21];
long long tmp[21];
int arr[21];
int new_arr[21];
int N, pro;

void check_per(long long num)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (!visited[j])
			{
				if (tmp[N - i] >= num)
				{
					visited[j] = true;
					new_arr[i] = j;
					break;
				}
				else
					num -= (tmp[N - i]);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		printf("%d ", new_arr[i]);
	}
	printf("\n");
}
void check()
{
	long long cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
 		int temp = 0;
		visited[arr[i]] = true;
		for (int j = 1; j <= arr[i]; ++j)
		{
			if (!visited[j])
			{
				temp++;
			}
		}
		cnt += ((long long)temp)*(tmp[N - i]);
	}
	printf("%lld\n", cnt + 1);
}
int main()
{
	scanf("%d %d", &N, &pro);
	tmp[0] = 1;
	tmp[1] = 1;
	for (long long i = 2; i <= N; ++i)
		tmp[i] = tmp[i - 1] * i;

	if (pro == 1)
	{
		long long num;
		scanf("%lld", &num);
		check_per(num);
	}
	else
	{
		for (int i = 1; i <= N; ++i)
			scanf("%d", &arr[i]);
		check();
	}
}