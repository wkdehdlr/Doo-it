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
				new_arr[flag] = arr[j];//�׳� arrũ�⸸ŭ ���� new_arr�� �����ϸ� flag�� ���� ó�������ʿ����
								
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
