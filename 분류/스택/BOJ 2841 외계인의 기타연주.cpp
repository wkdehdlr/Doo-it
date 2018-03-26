#pragma warning(disable : 4996)
#include<cstdio>
#include<stack>
using namespace std;

int N;
int P;
stack<int> st[7];
int cnt = 0;

int main()
{
	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; ++i)
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		if (st[num1].empty())//비어있으면 추가
		{
			st[num1].push(num2);
			cnt++;
		}
		else//이미 들어있으면
		{
			if (st[num1].top() > num2)//탑이 더 크면
			{
				while (!st[num1].empty() && st[num1].top() > num2)
				{
					st[num1].pop();
					cnt++;
				}

				if (st[num1].empty())
				{
					st[num1].push(num2);
					cnt++;
				}
				else
				{
					if (st[num1].top() != num2)
					{
						st[num1].push(num2);
						cnt++;
					}
				}
			}
			else if (st[num1].top() < num2)//탑이 더 작으면
			{
				st[num1].push(num2);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

