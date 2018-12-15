#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> umap;
string str;
int N;
int dp[20010];
int func(int n)
{
	if (n == N)return 0;
	int&ret = dp[n];
	if (ret != -1)return ret;
	ret = 999999999;
	for (int j = 1; j <= 5 && n + j <= N; ++j) {
		if (umap[str.substr(n, j)]) {
			ret = min(ret, 1 + func(n + j));
		}
	}
	return ret;
}
int solution(vector<string> strs, string t)
{
	for (int i = 0; i < strs.size(); ++i)umap[strs[i]] = 1;
	N = t.size();
	str = t;
	memset(dp, -1, sizeof(dp));
	int ret = func(0);
	if (ret == 999999999)return -1;
	else return ret;
}