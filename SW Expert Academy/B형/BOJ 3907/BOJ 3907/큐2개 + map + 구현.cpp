//#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;
struct info
{
	int dice;
	int r, c, count;
};
int minN = 0x7fffffff;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
char str[3];
int ans = 0;//최종배열상태를 ans에 저장
int row_end, col_end;
queue<info> pq_start, pq_end;
unordered_map<int, int> ma_start;
unordered_map<int, int> ma_end;

int change(int dice, int x, int y, int k)
{
	//x,y는 현재 비어있는 곳이고
	//r,c는 이제 빌 곳으로 x,y랑 스왑이다
	int dice_arry[4][4];
	int div = 100000000;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dice_arry[i][j] = dice / div;
			dice %= div;
			div /= 10;
		}
	}
	//w w r r b b 빈칸 
	//r b w b w r
	//1 2 3 4 5 6  0
	switch (dice_arry[x + dr[k]][y + dc[k]])
	{
	case 1:if (k == 0 || k == 2)dice_arry[x][y] = 6; else dice_arry[x][y] = 3; break;
	case 2:if (k == 0 || k == 2)dice_arry[x][y] = 4; else dice_arry[x][y] = 5; break;
	case 3:if (k == 0 || k == 2)dice_arry[x][y] = 5; else dice_arry[x][y] = 1; break;
	case 4:if (k == 0 || k == 2)dice_arry[x][y] = 2; else dice_arry[x][y] = 6; break;
	case 5:if (k == 0 || k == 2)dice_arry[x][y] = 3; else dice_arry[x][y] = 2; break;
	case 6:if (k == 0 || k == 2)dice_arry[x][y] = 1; else dice_arry[x][y] = 4; break;
	}

	dice_arry[x + dr[k]][y + dc[k]] = 0;

	int start = 0;//바뀐 주사위 상태를 start에 저장
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			start *= 10;
			start += dice_arry[i][j];
		}
	}
	return start;
}

int BFS()
{
	int j = 0;
	for (int depth = 0; depth <= 20; ++depth) {

		while (!pq_start.empty() && pq_start.front().count == depth)
		{
			int dice = pq_start.front().dice;
			int x = pq_start.front().r;
			int y = pq_start.front().c;
			int count = pq_start.front().count;
			pq_start.pop();
			for (int k = 0; k < 4; ++k)
			{
				int r = x + dr[k];
				int c = y + dc[k];
				if (r >= 1 && r <= 3 && c >= 1 && c <= 3)
				{
					int chang = change(dice, x, y, k);
					if (!ma_start[chang]) {
						ma_start[chang] = 1;
						if (ma_end[chang])return depth + j + 1;
						pq_start.push({ chang,r,c,count + 1 });
					}
				}
			}
		}

		while (!pq_end.empty() && pq_end.front().count == j && j < 9)
		{
			int dice = pq_end.front().dice;
			int x = pq_end.front().r;
			int y = pq_end.front().c;
			int count = pq_end.front().count;
			pq_end.pop();
			for (int k = 0; k < 4; ++k)
			{
				int r = x + dr[k];
				int c = y + dc[k];
				if (r >= 1 && r <= 3 && c >= 1 && c <= 3)
				{
					int chang = change(dice, x, y, k);
					if (!ma_end[chang]) {
						ma_end[chang] = 1;
						if (ma_start[chang])return depth + j + 2;
						pq_end.push({ chang,r,c,count + 1 });
					}
				}
			}
		}
		if (j < 9)++j;
	}
	return -1;
}

void setPQ(int depth, int state, int div, int res)
{/*
 case 'W': ans += 0; break;
 case 'B': ans += 1; break;
 case 'R': ans += 2; break;
 case 'E': ans += 3; break;*/
 //w w r r b b 빈칸 
 //r b w b w r
 //1 2 3 4 5 6  0
	if (depth == 9) {
		pq_end.push({ res,row_end,col_end,0 });
		ma_end[res] = 1;
	}
	else {
		res *= 10;
		switch (state / div)
		{
		case 0:setPQ(depth + 1, state%div, div / 10, res + 1); setPQ(depth + 1, state%div, div / 10, res + 2); break;
		case 1:setPQ(depth + 1, state%div, div / 10, res + 5); setPQ(depth + 1, state%div, div / 10, res + 6); break;
		case 2:setPQ(depth + 1, state%div, div / 10, res + 3); setPQ(depth + 1, state%div, div / 10, res + 4); break;
		case 3:setPQ(depth + 1, state%div, div / 10, res); break;
		}
	}
}
int main()
{//w w r r b b 빈칸 
 //r b w b w r
 //1 2 3 4 5 6  0
	int row, col;
	while (1)
	{
		scanf("%d %d", &col, &row);
		if (!row && !col)
			break;
		int dice = 0;
		for (int i = 1; i <= 3; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				dice *= 10;
				if (i == row && j == col)dice += 0;
				else dice += 1;
			}
		}

		ans = 0;
		for (int i = 1; i <= 3; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				scanf("%s", str);
				ans *= 10;
				switch (str[0])
				{
				case 'W': ans += 0; break;
				case 'B': ans += 1; break;
				case 'R': ans += 2; break;
				case 'E': row_end = i, col_end = j, ans += 3; break;
				}
			}
		}
		ma_start.clear();
		ma_end.clear();
		while (!pq_start.empty())pq_start.pop();
		while (!pq_end.empty())pq_end.pop();

		int state = ans;
		setPQ(0, state, 100000000, 0);

		if (ma_end[dice]) {
			printf("0\n");
		}
		else {
			pq_start.push({ dice,row,col,0 });//
			ma_start[dice] = 1;

			printf("%d\n", BFS());
		}
	}
}