#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
	int y;
	int h;
};
bool operator<(info f, info g)
{
	return f.y < g.y;
}
vector<int> vec;
int arr[10001];
int lis[301];
info mrr[301];
int N, M, K, T;
int func()
{
	vec.clear();
	int ret = 0;
	vec.push_back(-1);
	for (int i = 0; i < M; i++) {
		if (vec.back() < lis[i]) {
			vec.push_back(lis[i]);
			ret++;
		}
		else {
			auto it = lower_bound(vec.begin(), vec.end(), lis[i]);
			*it = lis[i];
		}
	}
	return vec.size()-1;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d %d", &N, &M, &K);
		/*if (K) {
			printf("Case #%d\n%d\n", tc + 1, 1);
			continue;
		}*/
		for (int i = 0; i < N; ++i)scanf("%d", &arr[i]);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &mrr[i].y);
			mrr[i].h = i;
		}
		sort(mrr, mrr + M);
		int ret = 0;
		for (int i = 0; i + M <= N; ++i) {
			for (int j = 0; j < M; ++j)lis[j] = arr[mrr[j].h + i];
			if (M - func() <= K)ret++;
		}
		printf("Case #%d\n%d\n", tc + 1, ret);
	}
}