#pragma warning(disable : 4996)
#include<cstdio>

bool arr[101];
bool arr2[101];
int main()
{
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	for (int i = 0; i < n; ++i)
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		if (num1)arr[num2] = true;
		else arr2[num2] = true;
	}

	int mx = 1;
	int len = 0;
	int idx = 0;
	for (int i = 0; i <= x; ++i)
	{
		if (arr[i]) {
			len = i - idx;
			idx = i;
			if (len > mx)
				mx = len;
		}
	}
	len = x - idx;
	if (len > mx)
		mx = len;

	len = 0;
	idx = 0;
	int mx2 = 1;
	for (int i = 0; i <= y; ++i)
	{
		if (arr2[i]) {
			len = i - idx;
			idx = i;
			if (len > mx2)
				mx2 = len;
		}
	}
	len = y - idx;
	if (len > mx2)
		mx2 = len;
	printf("%d\n", mx*mx2);
}