#include<cstdio>

int T, ang;
int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &ang);
		int tot = 0;
		for (int i = 3; i <= 998244353; ++i) {
			int flag = 0;
			tot += 180;
			double end = (double)tot / (double)i;
			double tmp = (double)end / (double)(i - 2);
			for (double start = tmp; start <= end; start += tmp) {
				if (start == ang) {
					printf("%d\n", i);
					flag = 1;
				}
			}
			if (flag)break;
		}
	}
}