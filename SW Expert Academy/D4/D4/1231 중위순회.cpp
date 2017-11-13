#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

int arr[101][3];
int N;

void inorder(int);
int main()
{	
	int node_num = 0;

	for (int t = 0; t < 10; t++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &node_num);
			scanf("%c", &arr[node_num][1]);
			scanf("%c", &arr[node_num][1]);

			arr[node_num][0] = 0; arr[node_num][2] = 0;

			if (node_num * 2 == N)
			{
				scanf("%d", &arr[node_num][0]);
				continue;
			}

			if (node_num * 2 < N)
			{
				scanf("%d %d", &arr[node_num][0], &arr[node_num][2]);
				continue;
			}
		}

		printf("#%d ", t + 1);
		inorder(1);
		printf("\n");
	}
}
void inorder(int node_num)
{
	if (arr[node_num][1] != 0)
	{
		inorder(arr[node_num][0]);
		printf("%c", arr[node_num][1]);
		inorder(arr[node_num][2]);
	}
}