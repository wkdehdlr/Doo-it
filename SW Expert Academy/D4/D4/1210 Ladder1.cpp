#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int dr[3] = { 0,0,1 };
int dc[3] = { -1,1,0 };
int arr[100][100];

int min = 0x7fffffff;
int max_start = 0;

int gogo(int, int, int, int,int);
int main()
{
	int T, N;

	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &T);
		min = 0x7fffffff;
		max_start = 0;
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		printf("#%d ", tc + 1);
		for (int j = 0; j < 100; ++j)
		{
			 gogo(0,j,2,j,0);
		}
		printf("%d\n", max_start);
	}
}


int gogo(int i,int j,int dir, int start,int cnt)
{
	if (i == 99)
	{
		if (min > cnt)
		{
			min = cnt;
			max_start = start;
		}
		else if (min == cnt)
		{
			if (max_start < start)
				max_start = start;
		}
		return 1;
	}
	else
	{
		int r, c, k;
		if (dir == 2)//아래로 내려갈때는 좌우를 먼저 살핀다.
		{
			for (k = 0; k < 3; ++k)
			{
				r = i + dr[k];
				c = j + dc[k];
				if (r >= 0 && r < 100 && c >= 0 && c < 100 && arr[r][c] != 0)
					break;
			}
			return gogo(r, c, k, start,cnt+1);
		}
		else if (dir == 1)//오른쪽 이동중일때는 아래먼저보고 다시 오른쪽본다//왼쪽은 안본다
		{
			for (k = 2; 0 < k; k--)
			{
				r = i + dr[k];
				c = j + dc[k];
				if (r >= 0 && r < 100 && c >= 0 && c < 100 && arr[r][c] != 0)
					break;
			}
			return gogo(r, c, k, start,cnt+1);
		}
		else if (dir == 0)
		{
			for (k = 2; 0 <= k; k -= 2)
			{
				r = i + dr[k];
				c = j + dc[k];
				if (r >= 0 && r < 100 && c >= 0 && c < 100 && arr[r][c] != 0)
					break;
			}
			return gogo(r, c, k, start,cnt+1);
		}
		return 0;
	}
}