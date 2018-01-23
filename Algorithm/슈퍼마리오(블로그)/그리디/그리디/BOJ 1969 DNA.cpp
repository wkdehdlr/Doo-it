#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int N, M;
char arr[1001][51];
int alpha[27];
char res[51];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < M; ++i)
	{
		memset(alpha, 0, sizeof(alpha));
		for (int j = 0; j < N; ++j)
		{
			alpha[arr[j][i] - 'A']++;
		}
		int maxn = 0;
		char max_ch = 'A';
		for (int j = 0; j < 27; ++j)
		{
			if (alpha[j] > maxn)
			{
				maxn = alpha[j];
				max_ch = j + 'A';
			}
			else if (alpha[j] == maxn)
			{
				if (j + 'A' < max_ch)
					max_ch = j + 'A';
			}	
		}	
		res[i] = max_ch;
	}
	int point = 0;
	res[M] = '\0';
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (res[i] != arr[j][i])
				point++;
		}
	}
	printf("%s\n%d\n", res, point);
}