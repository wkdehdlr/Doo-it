#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[3][3];
int tmp[3][3];
queue<int> q;
unordered_map<int, int> ma;

int change()
{
	int num = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			num *= 10;
			num += arr[i][j];
		}
	}
	return num;
}
void BFS()
{
	while (!q.empty())
	{
		int num = q.front();
		int orig = num;
		q.pop();
		if (num == 123456780)
		{
			printf("%d\n", ma[num]);
			return;
		}

		int res = 100000000;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				tmp[i][j] = num / res;
				num %= res;
				res /= 10;
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					int x = i + dr[k];
					int y = j + dc[k];
					if (x >= 0 && x < 3 && y >= 0 && y < 3 && !tmp[x][y])
					{
						memcpy(arr, tmp, sizeof(tmp));
						arr[x][y] = arr[i][j];
						arr[i][j] = 0;
						int re = change();
						if (!ma[re])
						{
							ma[re] = ma[orig] + 1;
							q.push(re);
						}
					}
				}
			}
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	int num = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			scanf("%d", &arr[i][j]);
			num *= 10;
			num += arr[i][j];
		}
	}
	q.push(num);
	ma[num] = 0;
	BFS();
}