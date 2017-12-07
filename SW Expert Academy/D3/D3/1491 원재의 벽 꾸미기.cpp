#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

long long minN,A,B,R,C;
int T, N;
long long origin_N;
int arr[100001];
bool check[100001];
void func();
int main()
{
	//제곱근을 미리 계산해놓는다.
	int start = 1;
	arr[1] = 1;
	for (int i = 2; i <= 100000; ++i)
	{
		if (i == (start + 1)*(start + 1))
		{
			arr[i] = start + 1;
			start++;
		}
		else
		{
			arr[i] = start;
		}
	}
	for (int i = 2; i <= 10; ++i)
	{
		int k = i;
		if (check[k])
			continue;
		while (k <= 100000)
		{
			check[k] = true;
			k += i;
		}
	}
	check[2] = check[3] = check[5] = false;


	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %lld %lld", &N, &A, &B);
		origin_N = N;
		int sqrt = arr[N]; sqrt *= sqrt;
		minN = 0x7fffffff;
		for (; sqrt <= N; N--)
		{
			func();
			if (!minN)
				break;
		}
		printf("#%d %lld\n", tc + 1, minN);
	}
}
void func()
{
	if (check[N])//소수가아님
	{
		for (int i = 1; i <= arr[N]; ++i)
		{
			if (!(N % i))//나누어떨어짐 ->약수임
			{
				R = N / i;
				C = i;
				long long res1 = A * (R - C);
				long long res2 = B * (origin_N - (R * C));
				if (res1 + res2 < minN)
					minN = res1 + res2;
			}
		}
	}
	else//소수임
	{
		R = N;
		C = 1;
		long long res1 = A * (R - C);
		long long res2 = B * (origin_N - R * C);
		if (res1 + res2 < minN)
			minN = res1 + res2;
	}
}