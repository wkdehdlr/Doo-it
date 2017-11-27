#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;

struct info {
	int num;
	int cnt;
};
queue<info> q;
priority_queue<int, vector<int>, greater<int> > q_end;
vector<vector<int> > vec(8, vector<int>());
char arr[8];
int usable[10];
int T, num;
void nck(int n, int k);
void BFS();
int main()
{
	vector<vector<int> > vec_temp(8, vector<int>());
	priority_queue<int, vector<int>, greater<int> > q_end_temp;
	queue<info> q_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		vec = vec_temp;
		q = q_temp;
		q_end = q_end_temp;
		for (int i = 0; i < 10; ++i)
		{
			scanf("%d", &usable[i]);
		}
		scanf("%d", &num);


		int length = 1;
		int data_temp = num;
		while (data_temp / 10)
		{
			length++;
			data_temp /= 10;
		}
		for (int kk = length; kk >= 1; kk--)
		{
			memset(arr, 0, sizeof(char) * 8);
			nck(0, kk);
		}


		q.push({ num,0 });
		BFS();
		if (!q_end.empty())
			printf("#%d %d\n", tc + 1, q_end.top());
		else
			printf("#%d -1\n", tc + 1);
	}
}
void BFS()
{
	while (!q.empty())
	{
		int data1 = q.front().num;
		int data2 = data1;
		int cnt = q.front().cnt;
		q.pop();

		while (usable[data2 % 10])
		{
			if (!data2)
				break;
			data2 /= 10;
		}

		if (!data2)//data2가 0이라는건 만들수있다는 이야기
		{
			int length = 1;
			int data_temp = data1;
			while (data_temp / 10)
			{
				length++;
				data_temp /= 10;
			}
			q_end.push(cnt + length + 1);
		}
		else//data2가 0이 되기전에 끝난건 만들수 없음
		{
			int length = 1;
			int data_temp = data1;
			while (data_temp / 10)
			{
				length++;
				data_temp /= 10;
			}

			for (int u = length; u >= 1; --u)
			{
				int size = vec[u].size();
				for (int r = 0; r < size; r++)
				{
					if (!(data1 % vec[u][r]))//나누어 떨어지면
					{
						q.push({ data1 / vec[u][r],cnt + u + 1 });
					}
				}
			}
		}
	}
}
void nck(int n, int k)
{
	if (n == k)
	{
		int div = atoi(arr);
		if (div != 0 && div != 1)
			vec[k].push_back(div);
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (usable[i])
			{
				arr[n] = i + '0';
				nck(n + 1, k);
			}
		}
	}
}