#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;

int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };
priority_queue<int, vector<int>, greater<int> > pq[11][11];
queue<int> tmp;
int arr[11][11];//현재양분
int arr2[11][11];//죽은나무양분
int arr3[11][11];//번식나무개수
int arr4[11][11];//입력양분
int N, M, K;
void input()
{
	memset(arr2, 0, sizeof(arr2));
	memset(arr3, 0, sizeof(arr3));
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &arr4[i][j]);
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		pq[x][y].push(age);
	}
}
void do_spring()
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int size = pq[i][j].size();
			if (!size)continue;
			while (size--) {
				int age = pq[i][j].top();
				pq[i][j].pop();
				if (arr[i][j] >= age) {
					arr[i][j] -= age;
					tmp.push(age + 1);
					if ((age + 1) % 5 == 0)arr3[i][j]++;
				}
				else arr2[i][j] += (age / 2);
			}
			while (!tmp.empty()) {
				pq[i][j].push(tmp.front());
				tmp.pop();
			}
		}
	}
}
void do_summer()
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!arr2[i][j])continue;
			arr[i][j] += arr2[i][j];
			arr2[i][j] = 0;
		}
	}
}
void do_fall()
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!arr3[i][j])continue;

			while (arr3[i][j]--) {
				for (int k = 0; k < 8; ++k) {
					int r = i + dr[k];
					int c = j + dc[k];
					if (r >= 1 && r <= N && c >= 1 && c <= N)pq[r][c].push(1);
				}
			}
			arr3[i][j] = 0;
		}
	}
}
void do_winter()
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			arr[i][j] += arr4[i][j];
		}
	}
}
void func()
{
	do_spring();
	do_summer();
	do_fall();
	do_winter();
}
int count()
{
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cnt += pq[i][j].size();
		}
	}
	return cnt;
}
int main()
{
	input();
	while (K--)
		func();
	printf("%d\n", count());
}