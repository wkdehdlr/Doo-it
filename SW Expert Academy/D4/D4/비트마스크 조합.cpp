#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
#include<cmath>
using namespace std;

int new_arr[4];
int arr[4] = { 1,2,3,4 };

int main()
{

	int mask = 1 << 4;
	int flag = 0;

	for (int i = 0; i < mask; ++i)
	{
		flag = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (i & (1 << j))
			{
				new_arr[flag] = arr[j];//그냥 arr크기만큼 같이 new_arr도 선언하면 flag에 따라 처리해줄필요없다
								
				flag++;
			}
		}
		if (flag == 2)
		{
			for (int k = 0; k < flag; ++k)
			{
				printf("%d", new_arr[k]);
			}
			printf("\n");
		}
	}

}
