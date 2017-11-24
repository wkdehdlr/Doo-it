#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int score[101];
int data;
int T;
int max_cnt, maxN;

int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &T);
		max_cnt = 0;
		maxN = 0;
		memset(score, 0, sizeof(int) * 101);
		for (int i = 0; i < 1000; ++i)
		{		
			scanf("%d", &data);
			score[data]++;
			if (score[data] > max_cnt)
			{
				max_cnt = score[data];
				maxN = data;
			}
			else if (score[data] == max_cnt)
			{
				if (maxN < data)
					maxN = data;
			}
		}
		printf("#%d %d\n", tc + 1, maxN);
	}
}