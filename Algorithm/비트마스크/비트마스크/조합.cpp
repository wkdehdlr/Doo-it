#include<cstdio>

int arr[4] = { 1,2,3,4 };
int new_arr[4];
int main()
{

	int max = 1 << 4;

	for (int i = 0; i < max; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (i & (1 << j))
			{
				new_arr[cnt] = arr[j];
				cnt++;
			}
		}
		if (cnt <= 2)
		{
			for (int k = 0; k < cnt; ++k)
			{
				printf("%d", new_arr[k]);
			}
			printf("\n");
		}
	}
}