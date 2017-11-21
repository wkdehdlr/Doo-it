#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

vector<int> new_arr(6);
int T, num, cnt, N;
char temp[10];
int maxN;
void func(int,vector<int>);
int main()
{
	vector<int> arr(6);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%s %d", temp, &cnt);
		N = strlen(temp);//몇자리 숫자인지
		for (int i = 0; i < N; ++i)
		{
			arr[i] = temp[i] - '0';
		}
		maxN = 0;
		func(0,arr);
		printf("#%d %d\n", tc + 1, maxN);
	}
}
void func(int knt,vector<int> arr)
{
	if (knt == cnt)
	{
		int n = 0;
		for (int i = 0; i < N; ++i)
		{
			n *= 10;
			n += arr[i];
		}
		if (maxN < n)
			maxN = n;
	}
	else
	{
		vector<int> vec(6);
		int mask = 1 << N;
		int flag = 0;

		for (int i = 0; i < mask; ++i)
		{
			flag = 0;
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
				{
					new_arr[flag] = j;
					flag++;
				}
			}
			if (flag == 2)
			{
				int temp;
				vec = arr;
				temp = vec[new_arr[0]];
				vec[new_arr[0]] = vec[new_arr[1]];
				vec[new_arr[1]] = temp;
				//두개 바꾸고 다음 호출
				func(knt + 1, vec);
			}
		}
	}
}