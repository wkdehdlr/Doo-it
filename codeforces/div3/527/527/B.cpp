#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int arr[110];
int main()
{
	int ans = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", &arr[i]);
	sort(arr, arr + N);
	for (int i = 0; i < N; i += 2) {
		ans += (arr[i + 1] - arr[i]);
	}
	printf("%d\n", ans);
}