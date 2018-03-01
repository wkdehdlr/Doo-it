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
	int same;//다른 윗면 개수
};

bool operator<(info f, info g)
{
	if (f.same + f.count == g.same + g.count)
		return f.same > g.same;
	else
		return f.same + f.count > g.same + g.count;
	//return f.total > g.total;

}

int minN = 0x7fffffff;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
char str[3];
int ans = 0;//최종배열상태를 ans에 저장
priority_queue<info> pq;
unordered_map<int, int> ma;

int check_same(int dice)
{
	int same = 0;
	int res;
	int div = 100000000;
	int tmp_ans = ans;

	for (int i = 0; i < 9; ++i)
	{
		if (!(dice / div))
		{
			tmp_ans %= div;
			dice %= div;
			div /= 10;
			continue;
		}

		switch (dice / div)
		{
		case 1:res = 0; break;
		case 2:res = 0; break;
		case 3:res = 2; break;
		case 4:res = 2; break;
		case 5:res = 1; break;
		case 6:res = 1; break;
		}

		if ((tmp_ans / div) != res)
			same++;

		tmp_ans %= div;
		dice %= div;
		div /= 10;
	}
	return same;
}

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
	if (!ma[dice]) {
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
		int dice = pq.top().dice;
		int x = pq.top().r;
		int y = pq.top().c;
		int count = pq.top().count;
		int s_ame = pq.top().same;
		int now = unLock_dice(dice);
		//printf("%d\n", count);
		pq.pop();

		if (count == 31) {
			//printf("aaa\n");
			break;
		}
		//if (count >= 23 && count + s_ame >= 32)break;
		//		{printf("aaa\n");break;}
		if (now == ans) {
			minN = count;
			//printf("arser\n");
			//printf("%d\n", count);
			break;
			//if(count < minN)
			//minN = count;
			//break;
		}//!!!!!!!!!!!!//
		 //if (count == 30)continue;

		for (int k = 0; k < 4; ++k)
		{
			int r = x + dr[k];
			int c = y + dc[k];
			if (r >= 1 && r <= 3 && c >= 1 && c <= 3)
			{
				int new_dice = change(dice, x, y, k);
				if (visit(new_dice))
				{
					int same = check_same(new_dice);
					if (same + count + 1 <= 30)
					{
						pq.push({ new_dice,r,c,count + 1,same });
					}
					/*	else if(same + count + 1 > 23 && same+count+1<=30)
					{
					minN = same + count + 1;
					return;
					}*/
					//	pq.push({ new_dice,r,c,count + 1,same});
					//	else
					//	continue;
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
		//int same = check_same(dice);
		minN = 0x7fffffff;
		ma.clear();
		while (!pq.empty())pq.pop();
		int same = check_same(dice);
		pq.push({ dice,row,col,0,same });//
		visit(dice);
		BFS();
		if (minN == 0x7fffffff)
			printf("-1\n");
		else
			printf("%d\n", minN);
	}
}