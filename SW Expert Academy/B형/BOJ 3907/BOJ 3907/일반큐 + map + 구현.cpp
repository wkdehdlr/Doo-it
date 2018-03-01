#pragma warning(disable : 4996)
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
bool visited[4][334];
char str[3];
int ans = 0;//최종배열상태를 ans에 저장
queue<info> pq;
unordered_map<int, int> ma;

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
bool visit(int dice)
{
	if (ma.find(dice) == ma.end()) {
		ma[dice] = 1;
		return true;
	}
	else {
		return false;
	}
}
int unLock_dice(int dice)
{
	//w w r r b b 빈칸 
	//r b w b w r
	//1 2 3 4 5 6  0
	int res = 0;
	int div = 100000000;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			res *= 10;
			switch (dice / div)
			{
			case 0:res += 3; break;
			case 1:res += 0; break;
			case 2:res += 0; break;
			case 3:res += 2; break;
			case 4:res += 2; break;
			case 5:res += 1; break;
			case 6:res += 1; break;
			}
			dice %= div;
			div /= 10;
		}
	}
	return res;
}
void BFS()
{
	while (!pq.empty())
	{
		int dice = pq.front().dice;
		int x = pq.front().r;
		int y = pq.front().c;
		int count = pq.front().count;
		int now = unLock_dice(dice);
		//printf("%d\n", count);
		pq.pop();

		if (now == ans) {
			minN = count;
			break;
		}//!!!!!!!!!!!!//
		if (count == 31)break;

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= 3 && c >= 1 && c <= 3)
			{
				int chang = change(dice, x, y, k);
				if (visit(chang)) {
					pq.push({ chang,r,c,count + 1 });
				}
			}
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
				case 'E': ans += 3; break;
				}
			}
		}
		minN = 0x7fffffff;
		memset(visited, false, sizeof(visited));
		ma.clear();
		while (!pq.empty())pq.pop();

		pq.push({ dice,row,col,0 });//
		visit(dice);
		BFS();
		if (minN == 0x7fffffff)
			printf("-1\n");
		else
			printf("%d\n", minN);
	}
}