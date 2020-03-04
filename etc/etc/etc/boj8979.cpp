#pragma warning(disable : 4996)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
struct data
{
	int a, b, c, d;
};
bool operator<(data f, data g) {
	if (f.b != g.b) {
		return f.b < g.b;
	}
	else {
		if (f.c != g.c) {
			return f.c < g.c;
		}
		else {
			return f.d < g.d;
		}
	}
}
vector<data> ans;
data data[1001];
int N, K;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d %d %d %d", &data[i].a, &data[i].b, &data[i].c, &data[i].d);
		ans.push_back(data[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < N; ++i) {
		if(ans[i].a == K)
	}

}