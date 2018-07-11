#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int T, N;
int arr[5] = { 0,0,10,100,1000 };
int dp[10001];
int dp2[10001][5];
vector<int> vec;
stack<int> st;
bool func3(int n,int cnt, int k)
{
	if (cnt == k && n == 0)return true;
	if (cnt == k && n != 0)return false;
	for (int i = vec.size() - 1; i >= 0; --i) {
		if (n >= vec[i]) {
			if (func3(n - vec[i], cnt + 1, k)) {
				st.push(vec[i]);
				return true;
			}
		}
	}
	return false;
}
int func2(int n, int cnt)
{
	if (n == 0)return cnt;
	if (cnt == 3 && n != 0)return 987654321;

	int& ret = dp2[n][cnt];
	if (ret != -1)return ret;
	ret = 987654321;
	for (int i = vec.size() - 1; i >= 0; --i) {
		if (n >= vec[i]) {
			//if(cnt==0)
				//printf("%d %d\n", vec[i], n - vec[i]);
			ret = min(ret, func2(n - vec[i], cnt + 1));
		}
	}
	return ret;
}
int func(int n, int k)
{
	if (k == 2) {
		if (n == 0)return 1;
		if (n < 10)return 0;
	}
	int& ret = dp[n];
	if (ret != -1)return ret;
	if (k == 1)return ret = 1;
	if (k == 2) {
		if (n / arr[k] == n % arr[k])return ret = 1;
		else return ret = 0;
	}

	int f = n / arr[k];
	int e = n % arr[2];
	if (f == e && func((n - f * arr[k] - e) / 10, k - 2))
		return ret = 1;
	else return ret = 0;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	for (int i = 1; i < 10000; ++i) {
		if (i < 10) {
			if (func(i, 1))vec.push_back(i);
			continue;
		}
		else if (i < 100) {
			if (func(i, 2))vec.push_back(i);
			continue;
		}
		else if (i < 1000) {
			if (func(i, 3))vec.push_back(i);
			continue;
		}
		else if(i<10000){
			if (func(i, 4))vec.push_back(i);
			continue;
		}
	}
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		int res = func2(N, 0);
		func3(N, 0, res);
		printf("Case #%d\n%d ", tc + 1, res);
		while (!st.empty()) {
			printf("%d ", st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}