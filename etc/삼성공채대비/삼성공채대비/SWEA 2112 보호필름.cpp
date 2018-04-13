#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int visited[14];
vector<vector<int> > arr(14, vector<int>(21));
vector<vector<int> > vec;
int T, D, W, K;
int mn = 0x7fffffff;
bool go()
{
	bool done = true;
	for (int j = 1; j <= W; ++j)
	{
		done = true;
		for (int i = 1; i <= D - K + 1; ++i)
		{
			done = true;
			for (int k = i; k < i + K - 1; ++k)
			{
				if (vec[k][j] != vec[k + 1][j]) {
					done = false;
					break;
				}
			}
			if (done)break;
		}
		if (!done)break;
	}
	if (done)return true;
	else return false;
}
void DFS(int dep, int  cnt)
{
	if (cnt > mn)return;
	if (dep == D + 1)
	{
		vec = arr;
		for (int i = 1; i <= D; ++i)//행
		{
			if (visited[i] == 1){
				for (int j = 1; j <= W; ++j)
					vec[i][j] = 0;//0 열을 다 A로 바꿈
			}
			else if (visited[i] == 2){
				for (int j = 1; j <= W; ++j)
					vec[i][j] = 1;//1 열을 다 B로 바꿈
			}
		}
		if (go()) {
			if (mn > cnt)
				mn = cnt;
		}
	}
	else
	{
		visited[dep] = 0;
		DFS(dep + 1, cnt);
		visited[dep] = 1;
		DFS(dep + 1, cnt + 1);
		visited[dep] = 2;
		DFS(dep + 1, cnt + 1);
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		mn = 0x7fffffff;
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i <= D; ++i)
			for (int j = 1; j <= W; ++j)
				scanf("%d", &arr[i][j]);

		DFS(1, 0);
		printf("#%d %d\n", tc + 1, mn);
	}
}