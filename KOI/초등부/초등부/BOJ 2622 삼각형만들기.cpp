#pragma warning(disable : 4996)
#include<cstdio>
int N;
int cnt = 0;
int main()
{
	scanf("%d", &N);
	for (int a = 1; a < N; ++a) {
		for (int b = a; b < N; ++b) {
			int c = N - (a + b);
			if (b > c)break;
			if (a + b > c)cnt++;
		}
	}
	printf("%d\n", cnt);
}