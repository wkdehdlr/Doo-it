#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
char str[11];
int T, K, len, cnt;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		cnt = 0;
		scanf("%s %d", str, &K);
		len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == '-' && i + K <= len)
			{

			}
		}
	}
}