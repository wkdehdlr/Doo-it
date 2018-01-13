#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

queue<pair<int,string> > q;
int T, num1, num2;
bool visited[10000];
void BFS()
{
	while (!q.empty())
	{
		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num == num2)
		{
			for (int i = 0; i < str.size(); ++i)
			{
				printf("%c", str[i]);
			}
			printf("\n");
			break;
		}
		
		int D_num = (2 * num) % 10000;
		int S_num = num ? num - 1 : 9999;
		int L_num = (num % 1000) * 10 + num / 1000;
		int R_num = (num % 10) * 1000 + num / 10;

		if (!visited[D_num])
		{
			visited[D_num] = true;
			q.push({ D_num,str + "D" });
 		}

		if (!visited[S_num])
		{
			visited[S_num] = true;
			q.push({ S_num,str + "S" });
		}

		if (!visited[L_num])
		{
			visited[L_num] = true;
			q.push({ L_num,str + "L" });
		}

		if (!visited[R_num])
		{
			visited[R_num] = true;
			q.push({ R_num,str + "R" });
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(visited, false, sizeof(visited));
		while (!q.empty())
			q.pop();
		scanf("%d %d", &num1, &num2);
		q.push({ num1,"" });
		visited[num1] = true;
		BFS();
	}
}