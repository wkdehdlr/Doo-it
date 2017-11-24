#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int  T;
int temp;
int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &T);
		for (int i = 0; i < 8; ++i)
		{
			scanf("%d", &temp);
			q.push(temp);
		}
		int cnt = 1;
		while (1)
		{
			int data = q.front();
			q.pop();
			if (data - cnt <= 0)
			{
				q.push(0);
				break;
			}
			else
			{
				q.push(data - cnt);
			}
			cnt = (cnt % 5) + 1;
		}
		printf("#%d", tc + 1);
		while (!q.empty())
		{
			printf(" %d", q.front());
			q.pop();
		}
		printf("\n");
	}
}