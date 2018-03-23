#pragma warning(disable : 4996)
#include<cstdio>
int arr[101][101];
int tot = 0;

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int r = x1; r < x2; ++r) 
		{
			for (int c = y1; c < y2; ++c)
			{
				if (!arr[r][c])
				{
					arr[r][c] = 1;
					tot++;
				}
			}
		}
	}
	printf("%d\n", tot);
}