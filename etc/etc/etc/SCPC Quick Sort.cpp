#pragma warning(disable : 4996)
#include<cstdio>
#include<unordered_map>
#include<algorithm>
using namespace std;

int arr[200001];
int arr2[200001];
int N, T;
unordered_map<int, int> ma;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		ma.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
			arr2[i] = arr[i];
		}
		sort(arr2, arr2 + N);
		for (int i = 0; i < N; ++i)ma[arr2[i]] = i;
		int ret = 0;
		int mx = arr[0];
		for (int i = 1; i < N; ++i) {
			if (ma[arr[i]] == i && ma[mx] == i - 1)ret++;
			if (mx < arr[i])mx = arr[i];
		}
		if (arr2[0] == arr[0])ret++;
		printf("Case #%d\n%d\n", tc + 1, ret);
	}
}