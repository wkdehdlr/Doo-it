#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[21];
int sum, N, cnt = 0;


void func(int n,int res)
{
	if (n == N)
	{
		if(res == sum)
			cnt++;
	}
	else
	{
		for (int i = 1; i >= 0; --i)
			i ? func(n + 1, res + arr[n]) : func(n + 1, res);
	}
}
int main()
{
	scanf("%d %d", &N, &sum);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	func(0,0);
	printf("%d\n", sum ? cnt : cnt - 1);
}