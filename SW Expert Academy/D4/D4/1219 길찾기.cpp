#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int arr[100][2];
int size, num, data;

int check_des(int);
int main()
{

	for (int tc = 0; tc < 10; tc++)
	{
		memset(arr, -1, sizeof(arr));
		scanf("%d %d", &size, &size);
		for (int i = 0; i < size; ++i)
		{
			scanf("%d %d", &num, &data);
			if (arr[num][0] == -1)
				arr[num][0] = data;
			else
				arr[num][1] = data;
		}

		if (check_des(0))
			printf("#%d 1\n", tc + 1);
		else
			printf("#%d 0\n", tc + 1);
	}
}
int check_des(int num)
{
	if (num == 99)
	{
		return 1;
	}
	else if (num == -1)
	{
		return 0;
	}
	else
	{
		if (check_des(arr[num][0]))
			return 1;
		if (check_des(arr[num][1]))
			return 1;

		return 0;
	}
}