#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;
struct info {
	int num1, num2;
};
bool compare(info f, info g)
{
	if (f.num1 == g.num1)
		return f.num2 < g.num2;
	return f.num1 < g.num1;
}
info inf[1000];
int dp[1001];
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		num1 > num2 ? (inf[i].num1 = num1, inf[i].num2 = num2) : (inf[i].num1 = num2, inf[i].num2 = num1);
	}

	sort(inf, inf + N, compare);
	dp[0] = inf[0].num2;
	int idx = 1;
	int mx = 0;
	for (int i = 1; i < N; ++i)
	{
		if (inf[i].num2 >= dp[idx - 1])
		{
			dp[idx] = inf[i].num2;
			idx++;
		}
		else
		{
			*upper_bound(dp, dp + idx, inf[i].num2) = inf[i].num2;
		}
	}
	//return 0;
	printf("%d\n", idx);
}