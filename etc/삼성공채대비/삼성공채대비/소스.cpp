#include<cstdio>
#include<algorithm>
using namespace std;

int tmp[3];
bool visited[7];

void DFS(int idx, int dep)
{
	if (dep == 3)
	{
		for (int i = 0; i < 3; ++i)
			printf("%d", tmp[i]);
		printf("\n");
	}
	else
	{
		for (int i = idx + 1; i <= 6; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				tmp[dep] = i;
				DFS(i , dep + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	for (int i = 1; i <= 6; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			tmp[0] = i;
			DFS(i,1);
			visited[i] = false;
		}
	}
}
