#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N, M, K;
int main()
{
	int cnt = 0;
	scanf("%d %d %d", &N, &M, &K);
	while (N >= 2 && M >= 1)
	{
		N -= 2;
		M--;
		cnt++;
	}

	while (N + M < K && cnt)
	{
		cnt--;
		N += 2;
		M++;
	}
	printf("%d\n", cnt);
}