#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N, M;
int arr[100000];

int main()
{
	int maxN = 0;
	int right = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > maxN)
			maxN = arr[i];
		right += arr[i];
	}

	int left = maxN;
	int mid = right;
	int cnt = 1;
	while (1)
	{
		bool flag = false;
		int temp = mid;
		cnt = 1;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] <= temp)
				temp -= arr[i];
			else
			{
				temp = 0;
				while (temp < arr[i])
				{
					temp += mid;
					cnt++;
				}
				temp -= arr[i];
			}
		}

		if (cnt <= M)
			right = mid;
		else if (M < cnt)
		{
			flag = true;
			left = mid;
		}

		if (left == right)
			break;

		mid = (left + right) / 2;
		if (mid == left && flag)
			break;
	}
	printf("%d\n", right);
}