#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

bool kflag;
char input_first[10];
bool visited[11][1000000];
vector<int> arr;
int T, cnt, N, maxN;
void func(int, vector<int>);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		arr.clear();
		memset(visited, false, sizeof(visited));
		scanf("%s %d", input_first, &cnt);
		N = strlen(input_first);//몇자리 숫자인지		
		for (int i = 0; i < N; ++i)
		{
			arr.push_back(input_first[i] - '0');
		}
		maxN = 0;
		func(0, arr);
		printf("#%d %d\n", tc + 1, maxN);
	}
}
void func(int knt, vector<int> vec)
{
	if (knt == cnt)
	{
		int mul = 0;
		for (int k = 0; k < N; ++k)
		{
			mul *= 10;
			mul += vec[k];
		}
		if (mul > maxN)
			maxN = mul;
	}
	else
	{
		int save = 0;
		vector<int> vec2;
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				vec2 = vec;
				save = vec2[i];
				vec2[i] = vec2[j];
				vec2[j] = save;

				int mul = 0;
				for (int k = 0; k < N; ++k)
				{
					mul *= 10;
					mul += vec2[k];
				}

				if (!visited[knt + 1][mul])
				{
					visited[knt + 1][mul] = true;
					func(knt + 1, vec2);
				}
			}
		}
	}
}