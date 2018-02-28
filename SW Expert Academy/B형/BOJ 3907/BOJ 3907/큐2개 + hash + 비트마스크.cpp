#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<unordered_map>
const int maxn = 5000007;

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
bool ma_start[maxn], ma_end[maxn];

struct info
{
	int dice;
	int r, c, count;
};
int minN = 0x7fffffff;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int dice_up_down[7] = { 0,3,5,1,6,2,4 };
int dice_left_right[7] = { 0,6,4,5,2,3,1 };

char str[3];
char ans_str[10];
int row_end, col_end;
queue<info> pq_start, pq_end;
//unordered_map<int, int> ma_start, ma_end;

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
					int has = find(chang);
					if (!ma_start[has]) {
						ma_start[has] = 1;
						if (ma_end[has])return depth + j + 1;
						pq_start.push({ chang,r,c,count + 1 });
					}
				}
			}
		}//asd

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
					int has = find(chang);
					if (!ma_end[has]) {
						ma_end[has] = 1;
						if (ma_start[has])return depth + j + 2;
						pq_end.push({ chang,r,c,count + 1 });
					}
				}
			}
		}
		if (j < 9)++j;
	}
	return -1;
}

void setPQ(int depth, int res)
{/*
 case 'W': ans += 0; break;
 case 'B': ans += 1; break;
 case 'R': ans += 2; break;
 case 'E': ans += 3; break;*/
 //w w r r b b ºóÄ­ 
 //r b w b w r
 //1 2 3 4 5 6  0
	if (depth == 9) {
		pq_end.push({ res,row_end,col_end,0 });
		ma_end[find(res)] = 1;
	}
	else {
		int num1 = 0, num2 = 0;
		if (ans_str[depth] == 'E') {
			setPQ(depth + 1, res << 3);
			return;
		}
		if (ans_str[depth] == 'W')num1 = 1, num2 = 2;
		else if (ans_str[depth] == 'B')num1 = 5, num2 = 6;
		else if (ans_str[depth] == 'R')num1 = 3, num2 = 4;
		setPQ(depth + 1, (res << 3) | num1);
		setPQ(depth + 1, (res << 3) | num2);
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

		int cnt = 0;
		for (int i = 1; i <= 3; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				scanf("%s", str);
				ans_str[cnt++] = str[0];
				if (str[0] == 'E') {
					row_end = i;
					col_end = j;
				}
			}
		}

		init();
		memset(ma_start, 0, sizeof(ma_start));
		memset(ma_end, 0, sizeof(ma_end));
		while (!pq_start.empty())pq_start.pop();
		while (!pq_end.empty())pq_end.pop();

		setPQ(0, 0);

		if (ma_end[find(dice)]) {
			printf("0\n");
		}
		else {
			pq_start.push({ dice,row,col,0 });//
			ma_start[find(dice)] = 1;

			printf("%d\n", BFS());
		}
	}
}