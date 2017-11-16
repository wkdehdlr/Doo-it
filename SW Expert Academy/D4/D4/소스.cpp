#pragma warning(disable:4996)
#include<cstdio>
using namespace std;

int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int new_arr[5];

int main()
{
	int num = 1 << 10;
	int cnt = 0;

	for (int i = 0; i < num; ++i)
	{
		cnt = 0;
		for (int j = 0; j < 10; ++j)
		{
			if (i & (1 << j))
			{
				new_arr[cnt] = arr[j];
				cnt++;
			}
		}
		if (cnt == 5)
		{
			for (int k = 0; k < 5; ++k)
			{
				printf("%d", new_arr[k]);
			}
			printf("\n");
		}
	}

}