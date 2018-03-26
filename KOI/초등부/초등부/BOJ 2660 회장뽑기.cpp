#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
int arr[51][51];
int N;
struct info {
	int idx, num;
};
bool operator<(info f, info g)
{
	if (f.num == g.num) {
		return f.idx > g.idx;
	}
	else {
		return f.num > g.num;
	}
}
priority_queue<info> q;
queue<info> res;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			arr[i][j] = (i == j ? 0 : 1000000000);
		}
	}
	int x, y;
	while (scanf("%d%d", &x, &y) != EOF) {
		if (x == -1 && y == -1)break;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}



	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	info inf;
	for (int i = 1; i <= N; ++i)
	{
		inf.idx = i;
		inf.num = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] > inf.num) {
				inf.num = arr[i][j];
			}
		}
		q.push(inf);
	}
	int mx = q.top().num;
	while (!q.empty() && q.top().num == mx) {
		res.push(q.top());
		q.pop();
	}
	printf("%d %d\n", res.front().num, res.size());
	while (!res.empty()) {
		printf("%d ", res.front().idx);
		res.pop();
	}
	return 0;
}