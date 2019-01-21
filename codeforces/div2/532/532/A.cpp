#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int mx = 0;
int v1 = 0, v2 = 0;
int n, k;
int arr[110];
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1)v1++;
		else v2++;
	}

	for (int b = 1; b <= k; ++b) {
		int b1 = 0, b2 = 0;
		int s = (1 - b) / k;
		int e = (n - b) / k;
		for (; s <= e; ++s) {
			int idx = b + s * k;
			if (idx >= 1 && idx <= n) {
				if (arr[idx] == 1)b1++;
				else b2++;
			}
		}
		mx = max(mx, abs((v1 - b1) - (v2 - b2)));
	}
	printf("%d\n", mx);
}