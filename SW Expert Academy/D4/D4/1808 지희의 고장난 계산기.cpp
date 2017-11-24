#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;

struct info {
	int num;
	int cnt;
};

queue<info> q;
priority_queue<int,vector<int>,greater<int> > q_end;

int usable[10];
int T, num;

void BFS();
int main()
{
	priority_queue<int, vector<int>, greater<int> > q_end_temp;
	queue<info> q_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		q = q_temp;
		q_end = q_end_temp;
		for (int i = 0; i < 10; ++i)
		{
			scanf("%d", &usable[i]);
		}
		scanf("%d", &num);
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

		while (usable[data2%10])
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
			for (int i = 9; i >= 1; --i)
			{
				if (usable[i])
				{
					int mul = 0;
					for (int k = 0; k < 8; ++k)
					{
						mul *= 10;
						mul += i;
						if (mul == 1)
							continue;
						if (!(data1 % mul))//나누어 떨어지면
						{
							q.push({ data1 / mul,cnt + 2 + k });
						}
					}
				}
			}
		}
	}
}