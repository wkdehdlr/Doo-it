#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

struct info {
	int y;
	int h;
};
bool operator<(info f, info g) {
	return f.y > g.y;
}
info arr[10001];
int maxlist[10001];
int T, N;
int mx = 1200000000;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		mx = 1200000000;
		scanf("%d", &N);
		int top = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d %d %d", &top, &arr[i].y, &arr[i].h);
		}
		sort(arr, arr + N);

		top = 0;
		maxlist[0] = mx;
		for (int i = 0; i < N; i++)
		{
			bool ck = false;
			if (maxlist[top] >= arr[i].y)
			{
				maxlist[top + 1] = maxlist[top] - arr[i].h < arr[i].y ? maxlist[top] - arr[i].h : arr[i].y;
				ck = true;
			}
			maxlist[top] -= arr[i].h;
			int tmp, t = top - 1;
			for (int t = top - 1; t >= 0; t--)
			{
				if (maxlist[t] >= arr[i].y)
				{
					tmp = maxlist[t] - arr[i].h < arr[i].y ? maxlist[t] - arr[i].h : arr[i].y;
					maxlist[t + 1] = maxlist[t + 1]> tmp ? maxlist[t + 1] : tmp;
				}
				maxlist[t] -= arr[i].h;
			}
			if (ck) top++;
		}
		printf("Case #%d\n%d\n", tc + 1, N - top);
		for (int i = 0; i < 10001; ++i)maxlist[i] = 0;
	}
}