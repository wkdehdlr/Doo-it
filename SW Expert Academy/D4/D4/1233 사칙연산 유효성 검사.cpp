#pragma warning ( disable : 4996)
#include<iostream>
using namespace std;

char temp[255];
int arr[201][3];
int N;

int main()
{
	int flag = 0;
	int node_num = 0;
	for (int t = 0; t < 10; t++)
	{
		flag = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &node_num);
			scanf("%c", &arr[node_num][1]);
			scanf("%c", &arr[node_num][1]);

			arr[node_num][0] = 0; arr[node_num][2] = 0;

			if(node_num * 2 == N)
			{
				scanf("%d", &arr[node_num][0]);
				//continue;
			}

			if (node_num * 2 < N)
			{
				scanf("%d %d", &arr[node_num][0],&arr[node_num][2]);
				//continue;
			}

			if (arr[node_num][0] == 0 && arr[node_num][2] == 0)//리프면 숫자여야함
			{
				if (arr[node_num][1] == 42 || arr[node_num][1] == 43 || arr[node_num][1] == 45 || arr[node_num][1] == 47)
				{
					flag = i;
					printf("#%d 0\n", t + 1);
					break;
					//리프인데 연산자인경우 실패임
				}
			}
			else//리프가 아니면 연산자여야함
			{
				if (!(arr[node_num][1] == 42 || arr[node_num][1] == 43 || arr[node_num][1] == 45 || arr[node_num][1] == 47))
				{
					flag = i;
					printf("#%d 0\n", t + 1);
					break;
					//리프가 아닌데도 연산자가 아닌경우이므로 실패임
				}
			}

		}
		if (flag == 0)
		{
			printf("#%d 1\n", t + 1);
		}
		else
		{
			for (;flag <= N; flag++)
			{
				fgets(temp, sizeof(temp), stdin);
			}
		}
	}
}