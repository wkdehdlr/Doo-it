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
		if (maxN < arr[i])
			maxN = arr[i];
		right += arr[i];
	}

	int mid = right;
	int left = maxN;
	int temp = 0;
	int cnt = 1;

	while (1)
	{
		bool flag = false;
		temp = 0;
		cnt = 1;
		for (int i = 0; i < N; ++i)
		{
			temp += arr[i];
			if (temp > mid)
			{
				cnt++;
				temp = 0;
				temp += arr[i];
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

		mid = (right + left) / 2;
		if (mid == left && flag)
			break;
	}
	printf("%d\n", right);
}