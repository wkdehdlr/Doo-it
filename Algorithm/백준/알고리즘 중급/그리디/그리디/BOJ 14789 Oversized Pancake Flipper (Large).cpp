#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

char S[1001];
int T, K;
int func()
{
	int cnt = 0;
	int len = strlen(S);
	for (int i = 0; i < len; ++i)
	{
		if (S[i] == '-') {
			if (len <= i + K - 1)return -1;
			cnt++;
			for (int j = i; j < i + K; ++j) {
				S[j] == '-' ? S[j] = '+' : S[j] = '-';
			}
		}
	}
	return cnt;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%s %d", S, &K);
		int res = func();
		if (res != -1)
			printf("Case #%d: %d\n", tc + 1, res);
		else printf("Case #%d: IMPOSSIBLE\n", tc + 1);
	}
}