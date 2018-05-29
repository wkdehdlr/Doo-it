#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<vector<int> > vec(500001);
int N, M;
int arr[500001];
bool visit[500001];
void DFS(int idx, int num)
{
	if (visit[idx])return;
	visit[idx] = true;
	arr[idx] += num;
	//if (vec[idx].empty())return;
	for (int i = 0; i < vec[idx].size(); ++i)
	{
		DFS(vec[idx][i], num);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d", &arr[1]);
	for (int i = 2; i <= N; ++i)
	{
		int idx;
		scanf("%d %d", &arr[i], &idx);
		vec[idx].push_back(i);
	}
	for (int i = 1; i <= M; ++i)
	{
		char str[2];
		scanf("%s", str);
		if (str[0] == 'p')
		{
			int idx, num;
			scanf("%d %d", &idx, &num);
			//if (vec[idx].empty())continue;
			memset(visit, 0, sizeof(visit));
			for (int i = 0; i < vec[idx].size(); ++i)
				DFS(vec[idx][i], num);
		}
		else
		{
			int idx;
			scanf("%d", &idx);
			printf("%d\n", arr[idx]);
		}
	}
}