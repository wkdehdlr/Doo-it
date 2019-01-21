#include<cstdio>
#include<unordered_set>
using namespace std;
long long n, m;
int input;
long long now = 0, tot = 0;
int pool[100010];
 
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &n, &m);
	tot = (n*(n + 1)) / 2;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &input);
		pool[input]++;
		if (pool[input] == 1)now += input;
		if (now == tot) {
			printf("1");
			now = 0;
			for (int k = 1; k <= n; ++k) {
				pool[k]--;
				if (pool[k])now += k;
			}
		}
		else printf("0");
	}
}