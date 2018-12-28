#pragma warning(disable : 4996)
#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<int, int> unmap, tmp;
int T, N, M, tot;
int arr[1010];
void input()
{
	tot = 0;
	unmap.clear();
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int value;
		scanf("%d", &value);
		unmap[i] = value;
		tot += value;
	}
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
}
int func()
{
	for (int i = 1; i <= N; ++i) {
		bool ok = true;
		tmp = unmap;
		for (int j = 0; j < tot; ++j) {
			if (tmp[arr[i+j]] == 0) {
				ok = false;
				break;
			}
			else tmp[arr[i+j]]--;
		}
		if (ok)return i;
	}
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		input();
		printf("#%d %d\n", tc + 1, func());
	}
}