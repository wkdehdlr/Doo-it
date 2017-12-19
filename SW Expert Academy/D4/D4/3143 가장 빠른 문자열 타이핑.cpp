#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int cnt = 0;
bool flag;
int T;
char str1[10001];
char str2[101];
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%s %s", str1, str2);
		cnt = 0;
		int i = 0; int j = 0;
		for (; str1[i] != '\0'; ++i)
		{
			if (str1[i] == str2[j])
			{
				flag = true;
				for (++i, ++j; str2[j] != '\0'; ++j, ++i)
				{
					if (str1[i] != str2[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					cnt++;
				else
					cnt += j;
				--i;
				j = 0;
			}
			else
				cnt++;
		}
		printf("#%d %d\n", tc + 1, cnt);
	}
}