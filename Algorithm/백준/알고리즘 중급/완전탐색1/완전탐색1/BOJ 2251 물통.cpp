#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

bool visited[201][201][201];
struct info {
	int a, b, c;
};
priority_queue<int, vector<int> ,greater<int> > pq;
queue<info> q;
int arr[3];
int tmp_arr[3];
int start[3];

void BFS()
{
	while (!q.empty())
	{
		arr[0] = q.front().a;
		arr[1] = q.front().b;
		arr[2] = q.front().c;
		q.pop();

		if (!arr[0])pq.push(arr[2]);

		for (int i = 0; i < 3; ++i)
		{
			memcpy(tmp_arr, arr, sizeof(arr));
			if (tmp_arr[i])
			{
				for (int j = 0; j < 3; ++j)
				{
					memcpy(tmp_arr, arr, sizeof(arr));
					int res = start[j] - tmp_arr[j];
					if (i != j && res)
					{
						if (res <= tmp_arr[i])
						{
							tmp_arr[j] += res;
							tmp_arr[i] -= res;
						}
						else
						{
							tmp_arr[j] += tmp_arr[i];
							tmp_arr[i] = 0;
						}
						if (!visited[tmp_arr[0]][tmp_arr[1]][tmp_arr[2]])
						{
							visited[tmp_arr[0]][tmp_arr[1]][tmp_arr[2]] = true;
							q.push({ tmp_arr[0],tmp_arr[1],tmp_arr[2] });
						}
					}
				}
			}
		}
	}
	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}
	printf("\n");
}

int main()
{
	scanf("%d %d %d", &start[0], &start[1], &start[2]);
	visited[0][0][start[2]] = true;
	q.push({0,0,start[2]});
	BFS();
}