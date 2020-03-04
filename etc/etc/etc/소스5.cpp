#pragma warning(disable : 4996)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;

struct node
{
	int a, b, c, d;
};
bool operator<(node f, node g) {
	if (f.b != g.b) {
		return f.b > g.b;
	}
	else {
		if (f.c != g.c) {
			return f.c > g.c;
		}
		else {
			return f.d > g.d;
		}
	}
}
vector<node> ans;
node arr[1001];
int N, K, res = 1;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d %d %d %d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d);
		ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	
	for (int i = 1; i < N; ++i) {
		if (ans[i - 1].a == K) {
			printf("%d\n", res);
			return 0;
		}
		if (ans[i - 1].b != ans[i].b || ans[i - 1].c != ans[i].c || ans[i - 1].d != ans[i].d ) res = i + 1;
	}
	printf("%d\n", res);
}