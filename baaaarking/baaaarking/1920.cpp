#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, ans;
vector<int> vec(100001);
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", &vec[i]);
	scanf("%d", &M);
	sort(vec.begin(), vec.begin() + N);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &ans);
		auto it = lower_bound(vec.begin(), vec.begin() + N, ans);
		if (ans == vec[it - vec.begin()])printf("1\n");
		else printf("0\n");
	}
	return 0;
}