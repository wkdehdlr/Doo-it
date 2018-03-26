#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int res[100001];
int main()
{	
	int idx = 1;
	scanf("%d %d", &N, &res[0]);

	for (int i = 1; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (res[idx - 1] < tmp) {
			res[idx++] = tmp;
		}
		else {
			*lower_bound(res, res + idx, tmp) = tmp;
		}
	}
	printf("%d\n", N - idx);
}