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

		func(1, 0);
		printf("#%d %d\n", tc + 1, atoi(input_first));
	}
}
void func(int knt, int idx)
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
		int min_idx = 0, min_num = 0x7fffffff, min_cnt = 0;
		int max_idx = 0, max_num = 0, max_cnt = 0;;

		for (int i = 0; i < N; ++i)
		{
			if (input_first[i] < min_num)
				min_num = input_first[i];
			else if (input_first[i] == min_num)
				min_cnt++;
			//3727  32888
			if (input_first[i] > max_num)
				max_num = input_first[i];
			else if (input_first[i] == max_num)
				max_cnt++;
		}

		func(knt + 1, idx + 1);
	}

}