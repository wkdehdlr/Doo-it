#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

char temp[52];
int T;
char ch;

int main()
{
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		int cnt = 0;
		scanf("%s", temp);
		ch = temp[0];
		for (int i = 1; temp[i] != '\0'; ++i)
		{
			if (ch != temp[i])
				cnt++;
			ch = temp[i];
		}
		if (temp[0] == '1')
			cnt++;
		printf("#%d %d\n", tc + 1, cnt);
	}
}