#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > vec;
int N;
int dp[1000001][2];
bool visit[1000001];
void func(int idx)
{
	visit[idx] = true;
	if (vec[idx].empty()) {
		dp[idx][0] = 0; dp[idx][1] = 1;
		return;
	}
	for (int i = 0; i < vec[idx].size(); ++i)
	{
		if (visit[vec[idx][i]])continue;
		func(vec[idx][i]);
		dp[idx][0] += dp[vec[idx][i]][1];
		dp[idx][1] += min(dp[vec[idx][i]][1], dp[vec[idx][i]][0]);
	}
	dp[idx][1]++;
}
int main()
{
	scanf("%d", &N);
	vec.resize(N + 1);
	int a, b;
	while (~scanf("%d %d", &a, &b)) 
	{
		vec[b].push_back(a);
		vec[a].push_back(b);
	}
	func(1);
	printf("%d\n", min(dp[1][1], dp[1][0]));
}