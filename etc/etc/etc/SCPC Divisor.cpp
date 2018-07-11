#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int T, N, M, L, R, num;
int arr[100001];
vector<vector<int> > vec(1000001);
int func(int n, int l, int r)
{
	int cnt = 0;
	for (int i = 0; i < vec[n].size(); ++i) {
		bool ok = true;
		for (int left = l; left <= r; ++left) {
			if (arr[left] % vec[n][i] == 0) {
				ok = false;
				break;
			}
		}
		if (ok)cnt++;
	}
	return cnt;
}
int main()
{
	for (int i = 1; i <= 1000000; ++i) {
		int sqr = sqrt(i);
		if (i % sqr == 0)vec[i].push_back(sqr);
		for (int j = 1; j < sqr; ++j) {
			if (i % j == 0) {
				vec[i].push_back(j);
				vec[i].push_back(i / j);
			}
		}
		sort(vec[i].begin(), vec[i].end());
	}

	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		int ret = 0;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
		for (int i = 1; i <= M; ++i) {
			scanf("%d %d %d", &num, &L, &R);
			ret += func(num, L, R);
		}
		printf("Case #%d\n%d\n", tc + 1, ret);
	}
}