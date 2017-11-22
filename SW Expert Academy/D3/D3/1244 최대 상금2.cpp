#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

bool kflag;
int digit_cnt[10];
int arr[6];
char input_first[10];
char input_max[10];
vector<char> temp2;
int T, cnt, N, maxN;
void func(int, int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		kflag = false;
		memset(input_max, 0, sizeof(input_max));
		temp2.clear();
		temp2.resize(10);
		for (int i = 0; i < 10; ++i)
			digit_cnt[i] = 0;

		scanf("%s %d", input_first, &cnt);
		N = strlen(input_first);//몇자리 숫자인지		
		for (int i = 0; i <= N; ++i)
		{
			temp2[i] = input_first[i];
			digit_cnt[input_first[i] - '0']++;
			if (digit_cnt[input_first[i] - '0'] >= 2)
				kflag = true;
		}
		sort(temp2.begin(), temp2.end(), greater<int>());
		for (int i = 0; i <= N; ++i)
		{
			input_max[i] = temp2[i];
		}

		func(1,0);
		printf("#%d %d\n", tc + 1, atoi(input_first));
	}
}
void func(int knt,int idx)
{
	if (knt == cnt)
	{
		if (!strcmp(input_first, input_max))//같으면 0
		{
			if (kflag == false)
			{
				char ch;
				ch = input_first[N - 2];
				input_first[N - 2] = input_first[N - 1];
				input_first[N - 1] = ch;
			}
		}
		else//다르면 최대에 가깝게 만듬
		{
			int maxNum = 0;
			int maxNum_idx = 0;
			while (1)
			{
				maxNum = 0;
				maxNum_idx = 0;
				for (int i = N - 1; i >= idx; --i)
				{
					if (maxNum < input_first[i] - '0')
					{
						maxNum = input_first[i] - '0';
						maxNum_idx = i;
					}
				}
				if (idx != maxNum_idx)
					break;
				idx++;
			}
			char ch;
			ch = input_first[idx];
			input_first[idx] = input_first[maxNum_idx];
			input_first[maxNum_idx] = ch;
		}
	}
	else
	{
		if (!strcmp(input_first, input_max))//같으면 0
		{
			if (kflag == false)
			{
				char ch;
				ch = input_first[N - 2];
				input_first[N - 2] = input_first[N - 1];
				input_first[N - 1] = ch;
				func(knt + 1, N - 2);
			}
		}
		else//다르면 최대에 가깝게 만듬
		{
			int maxNum = 0;
			int maxNum_idx = 0;
			while (1)
			{
				maxNum = 0;
				maxNum_idx = 0;
				for (int i = N - 1; i >= idx; --i)
				{
					if (maxNum < input_first[i] - '0')
					{
						maxNum = input_first[i] - '0';
						maxNum_idx = i;
					}
				}
				if (idx != maxNum_idx)
					break;
				idx++;
			}
			char ch;
			ch = input_first[idx];
			input_first[idx] = input_first[maxNum_idx];
			input_first[maxNum_idx] = ch;

			func(knt + 1, idx + 1);
		}
	}
}