#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char P[31];
int arr[31];
int T, D, len;
int cur, tot;

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %s", &D, P);
		len = strlen(P);
		cur = 1;
		tot = 0;
		bool done = true;
		for (int i = 0; i < len; ++i)
		{
			if (P[i] == 'C') {
				arr[i] = -1;
				cur *= 2;
				done = false;
			}
			else {
				arr[i] = cur;
				tot += cur;
			}
		}

		printf("Case #%d: ", tc + 1);
		if (D >= tot)
		{
			printf("0\n");
		}
		else
		{
			if (done)printf("IMPOSSIBLE\n");
			else
			{
				int cnt = 0;
				bool done = true;
				while (tot > D)
				{
					done = true;
					for (int i = len - 1; i > 0; --i)
					{
						if (arr[i] && arr[i - 1] == -1)
						{
							done = false;
							cnt++;
							arr[i] /= 2;
							tot -= arr[i];
							swap(arr[i], arr[i - 1]);
							break;
						}
					}
					if (done)
						break;
				}
				if (done)printf("IMPOSSIBLE\n");
				else printf("%d\n", cnt);
			}
		}
	}
}