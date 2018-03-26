#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;
struct info{
	int x, y;
};
bool operator<(info f, info g)
{
	if (f.x == g.x)
	{
		return f.y > g.y;
	}
	else
	{
		return f.x > g.x;
	}
}
priority_queue<info> q;

int arr[11][11];
int tmp[11][11];

bool func1(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && j <= 10) {
		arr[i][j] = 2;
		++j;
		++cnt;
	}
	q.push({ i,j-1 });
	x += cnt;
	info inf;
	for (i += 1; i < x; ++i)
	{
		cnt--;
		for (j = y; j < y + cnt; ++j)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func2(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && j <= 10) {
		arr[i][j] = 2;
		++j;
		++cnt;
	}
	q.push({ i,j - 1 });
	x += cnt;
	//y = j;
	info inf;
	int tmp = 0;
	for (i += 1; i < x; ++i)
	{
		tmp++;
		for (j = y + tmp; j < y + cnt; ++j)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func3(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && i <= 10) 
	{
		arr[i][j] = 2;
		++i;
		++cnt;
	}
	q.push({ i - 1,j });
	y += cnt;
	int tmp = 0;
	info inf;
	for (j += 1; j < y; ++j)
	{
		tmp++;
		for (i = x + tmp; i < x + cnt; ++i)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func4(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && i <= 10)
	{
		arr[i][j] = 2;
		++i;
		++cnt;
	}
	q.push({ i - 1,j });
	//y += cnt;
	info inf;
	int tmp = 0;
	for (j -= 1; j > 0; --j)
	{	
		tmp++;
		for (i = x + tmp; i < x + cnt; ++i)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func5(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && j <= 10) {
		arr[i][j] = 2;
		++j;
		++cnt;
	}
	q.push({ i,j - 1 });
	if (cnt % 2 == 0)return false;
	x += (cnt / 2) + 1;
	int tmp = 0;
	info inf;
	for (i += 1; i < x; ++i)
	{
		tmp++;
		cnt -= 2;
		for (j = y + tmp; j < y + tmp + cnt; ++j)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func6(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && i <= 10) {
		arr[i][j] = 2;
		++i;
		++cnt;
	}
	q.push({ i - 1,j });
	if (cnt % 2 == 0)return false;
	y += (cnt / 2) + 1;
	int tmp = 0;
	info inf;
	for (j += 1; j < y; ++j)
	{
		tmp++;
		cnt -= 2;
		for (i = x + tmp; i < x + tmp + cnt; ++i)
		{
			if (arr[i][j] != 1)
				return false;
			else
				arr[i][j] = 2;

			inf.x = i; inf.y = j;
		}
	}
	q.push(inf);
	return true;
}
bool func7(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && i <= 10) {
		arr[i][j] = 2;
		++i;
		++cnt;
	}
	q.push({ i - 1,j });
	if (cnt % 2 == 0)return false;
	y += (cnt / 2) + 1;
	int tmp = 0;
	info inf;
	for (j -= 1; j > 0; --j)
	{
		tmp++;
		cnt -= 2;
		for (i = x + tmp; i < x + tmp + cnt; ++i)
		{
			if (arr[i][j] != 1)
				return false;
			else {
				arr[i][j] = 2;
				inf.x = i; inf.y = j;
			}

		}
	}
	q.push(inf);
	return true;
}
bool func8(int i, int j)
{
	int x = i;
	int y = j;
	int cnt = 0;
	q.push({ i,j });
	while (arr[i][j] == 1 && i <= 10) {
		//arr[i][j] = 2;
		++i;
		++cnt;
	}
	arr[x][y] = 2;
	i = x;
	x += cnt;
	cnt = 1;
	int tmp = 0;
	for (i += 1; i < x; ++i)
	{
		tmp++;
		cnt += 2;
		if (y - tmp >= 1)
		{
			for (j = y - tmp; j < y - tmp + cnt; ++j)
			{
				if (arr[i][j] != 1)
					return false;
				else
					arr[i][j] = 2;

				if (i == x - 1 && (j == y - tmp || j == y - tmp + cnt - 1))
				{
					q.push({ i,j });
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool check()
{
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if (arr[i][j] == 1)
				return false;
		}
	}
	return true;
}
void my_cpy()
{
	while (!q.empty())q.pop();

	for (int i = 0; i <= 10; ++i)
	{
		for (int j = 0; j <= 10; ++j)
		{
			arr[i][j] = tmp[i][j];
		}
	}
}
int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			scanf("%1d", &arr[i][j]);
			tmp[i][j] = arr[i][j];
		}
	}
	//my_cpy();
	bool flag = false;
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if (arr[i][j] == 1)
			{
				if (func1(i, j)) {
					if (check()) {
						//찾음
						//printf("1찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
					}
				}
				my_cpy();
				if (func2(i, j)) {
					if (check()) {
						//printf("2찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func3(i, j)) {
					if (check()) {
						//printf("3찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func4(i, j)) {
					if (check()) {
						//printf("4찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func5(i, j)) {
					if (check()) {
						//printf("5찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func6(i, j)) {
					if (check()) {
						//printf("6찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func7(i, j)) {
					if (check()) {
						//printf("7찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				my_cpy();
				if (func8(i, j)) {
					if (check()) {
						//printf("8찾음\n");
						while (!q.empty()) {
							printf("%d %d\n", q.top().x, q.top().y);
							q.pop();
						}
						return 0;
						//찾음
					}
				}
				printf("0\n");
				return 0;
			}
		}
	}
}

/*
0000000000
0011111000
0001111000
0000111000
0000011000
0000001000
0000000000
0000000000
0000000000
0000000000


0000000000
0010000000
0011000000
0011100000
0011110000
0011111000
0000000000
0000000000
0000000000
0000000000

0000000000
0000001000
0000011000
0000111000
0001111000
0011111000
0000000000
0000000000
0000000000
0000000000

0000000000
0011111000
0001110000
0000100000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000

0000000000
0010000000
0011000000
0011100000
0011000000
0010000000
0000000000
0000000000
0000000000
0000000000

0000000000
0000001000
0000011000
0000111000
0000011000
0000001000
0000000000
0000000000
0000000000
0000000000

0000000000
0000000000
0000000000
0000000000
0000010000
0000111000
0001111100
0011111110
0000000000
0000000000
*/