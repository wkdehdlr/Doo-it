#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
struct ext {
	int x, y;
};
struct person {
	int num, tm1, tm2;
	bool ok;
};
ext ex[3];
vector<person> ps(11);
queue<int> q1, q2;
int team[11];
int arr[11][11];
int T, N;
bool visited[11];
int mn = 0x7fffffff;
int cnp = 1;
int go()
{
	int tm = 0;
	vector<person> pt = ps;
	while (1)
	{
		int size = q1.size();
		for (int i = 0; i < size; ++i)
		{
			int num = q1.front();
			q1.pop();
			if (num)
				q1.push(num - 1);
		}
		size = q2.size();
		for (int i = 0; i < size; ++i)
		{
			int num = q2.front();
			q2.pop();
			if (num)
				q2.push(num - 1);
		}

		for (int i = 1; i < cnp; ++i)
		{
			if (pt[i].num == 1 && !pt[i].tm1 && !pt[i].ok && q1.size() < 3) {
				pt[i].ok = true;
				q1.push({ arr[ex[1].x][ex[1].y] - 1 });
			}
			if (pt[i].num == 2 && !pt[i].tm2 && !pt[i].ok && q2.size() < 3) {
				pt[i].ok = true;
				q2.push({ arr[ex[2].x][ex[2].y]  - 1});
			}
		}

		for (int i = 1; i < cnp; ++i)
		{
			if (pt[i].num == 1 && pt[i].tm1)pt[i].tm1--;
			if (pt[i].num == 2 && pt[i].tm2)pt[i].tm2--;
		}
		tm++;
		if (q1.empty() && q2.empty())
		{
			bool done = true;
			for (int i = 1; i < cnp; ++i)
			{
				if (!pt[i].ok) {
					done = false;
				}
			}
			if (done)return tm;
		}
	}
}
void func()
{
	int tm = 0;
	for (int k = 0; k <= cnp / 2; ++k)
	{
		int mx = 1 << cnp;
		for (int i = 0; i < mx / 2; ++i)
		{
			int idx = 0;
			for (int j = 0; j < cnp; ++j)
			{
				if (i & (1 << j))
				{
					team[idx++] = j + 1;
				}
			}
			if (idx == k)
			{
				memset(visited, 0, sizeof(visited));
				for (int i = 0; i < idx; ++i)
				{
					visited[team[i]] = true;
				}

				for (int i = 1; i < cnp; ++i)
				{
					if (visited[i])ps[i].num = 1;
					else ps[i].num = 2;
				}
				tm = go();
				if (tm < mn)
					mn = tm;
				for (int i = 1; i < cnp; ++i)
				{
					if (visited[i])ps[i].num = 2;
					else ps[i].num = 1;
				}
				tm = go();
				if (tm < mn)
					mn = tm;
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		mn = 0x7fffffff;
		cnp = 1;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] && arr[i][j] != 1) {
					ex[cnp].x = i; ex[cnp].y = j;
					cnp++;
				}
			}

		cnp = 1;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				if (arr[i][j] == 1) {
					ps[cnp].tm1 = abs(ex[1].x - i) + abs(ex[1].y - j);
					ps[cnp].tm2 = abs(ex[2].x - i) + abs(ex[2].y - j);
					cnp++;
				}
			}
		//cnp--;
		func();
		printf("#%d %d\n", tc + 1, mn);
	}
}