#include<cstdio>
int T;
int N;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		printf("%d\n", (N / 7) + 1);
	}
}