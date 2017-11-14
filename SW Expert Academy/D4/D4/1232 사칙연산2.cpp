#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

int arr[1001][3];

int N;//Á¤Á¡ÀÇ ÃÑ ¼ö

double order(int);
int main()
{
	char temp[200];
	int node_num;

	for (int t = 0; t < 10; t++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &node_num);
			scanf("%s", temp);
			arr[node_num][0] = 0; arr[node_num][2] = 0;

			if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/')
			{
				arr[node_num][1] = temp[0];
				scanf("%d %d", &arr[node_num][0], &arr[node_num][2]);
			}
			else
			{
				int sum = 0;
				for (int k = 0;temp[k]!='\0'; k++)
				{
					sum *= 10;
					sum += temp[k] - '0';
				}
				arr[node_num][1] = sum;
			}
		}
		printf("#%d %d\n", t + 1, (int)order(1));
	}
}
double order(int node_num)
{
	if (arr[node_num][1] == 0)
		return 0x7fffffff;

	double num1 = order(arr[node_num][0]);
	double num2 = order(arr[node_num][2]);

	if (num1 == 0x7fffffff && num2 == 0x7fffffff)
		return arr[node_num][1];

	if (arr[node_num][1] == '+')
	{
		return num1 + num2;
	}
	else if (arr[node_num][1] == '*')
	{
		return num1 * num2;
	}
	else if (arr[node_num][1] == '-')
	{
		return num1 - num2;
	}
	else if (arr[node_num][1] == '/')
	{
		return num1 / num2;
	}
}