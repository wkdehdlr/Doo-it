#pragma warning(disable : 4996)
#include<cstdio>


int N;
int arr[1000];
int tmp[1000];

int func(int left, int right, int data)
{
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (tmp[mid] >= data)//data���� ū ���߿��� ���� �������� ã�´�!!!
		{
			right = mid;
		}
		else if (tmp[mid] < data)
		{
			left = mid + 1;
		}
	}
	return left;
}

//1 2 3 4 <- ���⿡ 2�� ����

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int i = 0, j = 0;
	tmp[i] = arr[i];
	++i;
	while (i < N)
	{
		if (tmp[j] < arr[i])
		{
			tmp[++j] = arr[i];
		}
		else
		{
			tmp[func(0, j, arr[i])] = arr[i];
		}
		++i;
	}
	printf("%d\n", j + 1);
}