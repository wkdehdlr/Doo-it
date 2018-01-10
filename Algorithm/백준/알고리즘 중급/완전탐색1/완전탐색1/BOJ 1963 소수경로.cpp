#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int T, num1, num2;
bool arr[10000];
bool visited[10000];
int dist[10000];
queue<int> q;


void change(int num, int i, int j)
{
	int arr2[4];
	int tmp = 1000;
	int orig_num = num;
	for (int k = 0; k < 4; ++k, tmp /= 10)
	{
		arr2[k] = num / tmp;
		num %= tmp;
	}
	arr2[i] = j;
	int new_num = 0;
	for (int k = 0; k < 4; ++k)
	{
		new_num *= 10;
		new_num += arr2[k];
	}

	if (new_num >= 1000 && !arr[new_num] && !visited[new_num])
	{
		q.push(new_num);
		visited[new_num] = true;
		dist[new_num] = dist[orig_num] + 1;
		/*if (!dist[new_num])
		{
			dist[new_num] = dist[orig_num] + 1;
			return true;
		}
		if (dist[new_num] > dist[orig_num] + 1)
		{
			dist[new_num] = dist[orig_num] + 1;
			return true;
		}*/
	}
}
void BFS()
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		/*if (now == num2)
		{
			printf("%d\n", dist[now]);
			break;
		}*/
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				change(now, i, j);
			}
		}
	}
}

int main()
{
	for (int i = 2; i < 101; ++i)
	{
		int cnt = 2;
		while (cnt*i < 10000)
		{
			arr[i*cnt++] = true;
		}
	}

	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(visited, false, sizeof(visited));
		memset(dist, -1, sizeof(dist));
		scanf("%d %d", &num1, &num2);
		q.push(num1);
		dist[num1] = 0;
		visited[num1] = true;
		BFS();

		if (dist[num2] == -1)
			printf("Impossible\n");
		else
			printf("%d\n", dist[num2]);

		while (!q.empty())
			q.pop();
	}
}