#pragma warning(disable : 4996)
#include<cstdio>
//#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int N, T, max_cnt = 0;
char max_ch = 'A';
char str[100001];
int alpha[27];
int main()
{
	//ios::sync_with_stdio(false);
	scanf("%d %d", &N, &T);
	scanf("%s", str);
	//cin >> N >> T >> str;
	for (int tc = 0; tc < T; ++tc)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		//cin >> start >> end;
		start--, end--;
		for (int i = start; i <= end; ++i)
		{
			alpha[str[i] - 'A']++;
			if (alpha[str[i] - 'A'] > max_cnt)
			{
				max_cnt = alpha[str[i] - 'A'];
				max_ch = str[i];
			}
			else if (alpha[str[i] - 'A'] == max_cnt)
			{
				if (str[i] < max_ch)
					max_ch = str[i];
			}
		}
		printf("%c\n", max_ch);
		memset(alpha, 0, sizeof(alpha));
		max_ch = 'A'; max_cnt = 0;
	}
}