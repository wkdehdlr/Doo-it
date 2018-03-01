#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
const int maxn = 10000007;
//#include<unordered_map>
using namespace std;
struct E {
	int next, w;
}e[maxn];
int head[maxn], tot;
void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}
void add(int s, int w) {
	e[tot].w = w;
	e[tot].next = head[s];
	head[s] = tot++;
}
int find(int n) {
	int u = n % maxn;
	int i;
	for (i = head[u]; ~i; i = e[i].next) {
		int w = e[i].w;
		if (w == n) return i;
	}
	add(u, n);
	return tot - 1;
}
//
bool ma[maxn];
struct info
{

	int dice;
	int r, c, count;
	int same;//´Ù¸¥ À­¸é °³¼ö
};

bool operator<(info f, info g)
{
	if (f.same + f.count == g.same + g.count)
		return f.same > g.same;
	else
		return f.same + f.count > g.same + g.count;
}
int dice_up_down[7] = { 0,3,5,1,6,2,4 };
int dice_left_right[7] = { 0,6,4,5,2,3,1 };
int minN = 0x7fffffff;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
char str[3];
char ans_str[10];
int ans = 0;//ÃÖÁ¾¹è¿­»óÅÂ¸¦ ans¿¡ ÀúÀå
priority_queue<info> pq;

int check_same(int dice)
{
	//w w r r b b ºóÄ­ 
	//r b w b w r
	//1 2 3 4 5 6  0
	int same = 0;
	char tmp_str;
	int tmp_dice = dice;

	for (int i = 8; i >= 0; --i)
	{
		int res = ((tmp_dice >> 3 * i) & 1) | ((tmp_dice >> 3 * i + 1) & 1) | ((tmp_dice >> 3 * i + 2) & 1);
		switch (res)
		{
		case 0:tmp_str = 'E'; break;
		case 1:tmp_str = 'W'; break;
		case 2:tmp_str = 'W'; break;
		case 3:tmp_str = 'R'; break;
		case 4:tmp_str = 'R'; break;
		case 5:tmp_str = 'B'; break;
		case 6:tmp_str = 'B'; break;
		}

		if (ans_str[8 - i] != tmp_str)
			same++;
	}
	return same;
}

int change(int dice, int x, int y, int k)
{
	//int dice_up_down[7] = { 0,3,5,1,6,2,4 };
	//int dice_left_right[7] = { 0,6,4,5,2,3,1 };
	//w w r r b b ºóÄ­ 
	//r b w b w r
	//1 2 3 4 5 6  0
	//x,y´Â ÇöÀç ºñ¾îÀÖ´Â °÷ÀÌ°í
	//r,c´Â ÀÌÁ¦ ºô °÷À¸·Î x,y¶û ½º¿ÒÀÌ´Ù
	int r = 0, c = 0;
	int now_pos = 8 - ((x - 1) * 3 + y - 1);
	int new_pos = 0;
	int tmp_dice = dice;
	if (k == 0) {//¿ÞÂÊ
		new_pos = now_pos + 1;
		tmp_dice = (((tmp_dice >> new_pos * 3 + 2) & 1) << 2) | (((tmp_dice >> new_pos * 3 + 1) & 1) << 1) | ((tmp_dice >> new_pos * 3) & 1);
		dice = (dice ^ (tmp_dice << new_pos * 3)) | (dice_left_right[tmp_dice] << now_pos * 3);
	}
	else if (k == 1) {//¾Æ·¡
		new_pos = now_pos - 3;
		tmp_dice = (((tmp_dice >> new_pos * 3 + 2) & 1) << 2) | (((tmp_dice >> new_pos * 3 + 1) & 1) << 1) | ((tmp_dice >> new_pos * 3) & 1);
		dice = (dice ^ (tmp_dice << new_pos * 3)) | (dice_up_down[tmp_dice] << now_pos * 3);
	}
	else if (k == 2) {//¿À¸¥ÂÊ
		new_pos = now_pos - 1;
		tmp_dice = (((tmp_dice >> new_pos * 3 + 2) & 1) << 2) | (((tmp_dice >> new_pos * 3 + 1) & 1) << 1) | ((tmp_dice >> new_pos * 3) & 1);
		dice = (dice ^ (tmp_dice << new_pos * 3)) | (dice_left_right[tmp_dice] << now_pos * 3);
	}
	else if (k == 3) {//À§
		new_pos = now_pos + 3;
		tmp_dice = (((tmp_dice >> new_pos * 3 + 2) & 1) << 2) | (((tmp_dice >> new_pos * 3 + 1) & 1) << 1) | ((tmp_dice >> new_pos * 3) & 1);
		dice = (dice ^ (tmp_dice << new_pos * 3)) | (dice_up_down[tmp_dice] << now_pos * 3);
	}
	return dice;
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
	//w w r r b b ºóÄ­ 
	//r b w b w r
	//1 2 3 4 5 6  0
	int ret = 0;
	char tmp_str;
	int tmp_dice = dice;

	for (int i = 8; i >= 0; --i)
	{
		ret *= 10;
		int res = ((tmp_dice >> 3 * i) & 1) | ((tmp_dice >> 3 * i + 1) & 1) | ((tmp_dice >> 3 * i + 2) & 1);
		switch (res)
		{
		case 1:ret += 1; break;
		case 2:ret += 1; break;
		case 3:ret += 2; break;
		case 4:ret += 2; break;
		case 5:ret += 3; break;
		case 6:ret += 3; break;
		}
	}
	return ret;
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
				int has = find(new_dice);
				if (!ma[has])
				{
					ma[has] = 1;
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
{//w w r r b b ºóÄ­ 
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
				if (i == row && j == col);
				else dice |= (1 << (8 - ((i - 1) * 3 + j - 1)) * 3);
			}
		}
		ans = 0;
		int cnt = 0;
		for (int i = 1; i <= 3; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				ans *= 10;
				scanf("%s", str);
				ans_str[cnt++] = str[0];
				if (str[0] == 'W')ans += 1;
				else if (str[0] == 'R')ans += 2;
				else if (str[0] == 'B')ans += 3;
			}
		}
		//int same = check_same(dice);
		minN = 0x7fffffff;
		init();
		memset(ma, 0, sizeof(ma));
		//ma.clear();
		while (!pq.empty())pq.pop();
		int same = check_same(dice);
		pq.push({ dice,row,col,0,same });//
		ma[find(dice)] = 1;
		//visit(dice);
		BFS();
		if (minN == 0x7fffffff)
			printf("-1\n");
		else
			printf("%d\n", minN);
	}
}