#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int row[4];
int col[4];
int dr[5] = { 0,0,0,-1,1 };
int dc[5] = { 0,1,-1,0,0 };
int N, M, K;
int arr[20][20];

int main()
{
	int x, y;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &arr[i][j]);

	for (int k = 0; k < K; ++k)
	{
		int dir;
		scanf("%d", &dir);//1µ¿ 2¼­ 3ºÏ 4³²
		int r = x + dr[dir];
		int c = y + dc[dir];
		if (r >= 0 && r < N && c >= 0 && c < M)
		{
			switch (dir)
			{
			case 1:rotate(col, col + 3, col + 4); row[3] = col[0]; row[1] = col[2]; break;
			case 2:rotate(col, col + 1, col + 4); row[3] = col[0]; row[1] = col[2]; break;
			case 3:rotate(row, row + 1, row + 4); col[0] = row[3]; col[2] = row[1]; break;
			case 4:rotate(row, row + 3, row + 4); col[0] = row[3]; col[2] = row[1]; break;
			}
			if (arr[r][c]) {
				col[0] = row[3] = arr[r][c];
				arr[r][c] = 0;
			}
			else {
				arr[r][c] = row[3];
			}
			printf("%d\n", row[1]);
			x = r;
			y = c;
		}
	}
}