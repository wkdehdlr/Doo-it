#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct sunbun {
	
	int garo_sero;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int length;
};

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

vector<sunbun> vec2;
vector<sunbun> vec_garo;
vector<sunbun> vec_sero;
vector<vector<sunbun> > vec;
int N,cnt;
int arr[13][13];
int core_max = 0;
int dir_min = 0x7fffffff;

void start(int);
void set_sunbun();
int check_garo(sunbun);
int check_sero(sunbun);
int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		core_max = 0;
		dir_min = 0x7fffffff;
		vec.clear();
		vec2.clear();
		vec_garo.clear();
		vec_sero.clear();
		cnt = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
				{
					if (!(i == 1 || i == N || j == 1 || j == N))
					{
						vector<sunbun> temp;
						vec.push_back(temp);
						cnt++;
					}
				}
			}
		}
		set_sunbun();
		vec2.resize(cnt);
		start(0);
		printf("#%d %d\n", tc + 1, dir_min);
	}
}

void set_sunbun()
{
	int temp = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] == 1)
			{
				if (!(i == 1 || i == N || j == 1 || j == N))
				{
					for (int k = 0; k < 4; ++k)
					{
						int r = i + dr[k];
						int c = j + dc[k];
						while (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c] == 0)
						{
							r += dr[k];
							c += dc[k];
						}
						r -= dr[k];
						c -= dc[k];
						if (r == 1 || r == N || c == 1 || c == N)
						{
							sunbun s;
							s.start_x = i; s.start_y = j;
							s.end_x = r; s.end_y = c;
							if (i == r)
								s.length = abs(j - c);
							else
								s.length = abs(i - r);

							if (k == 0 || k == 2)
								s.garo_sero = 1;//1이 가로
							else
								s.garo_sero = 0;//0이 세로
							vec[temp].push_back(s);
						}
					}
					temp++;
				}
			}
		}
	}
}
void start(int num)
{
	if (cnt == num)
	{
		int sum1 = 0;
		int size1 = 0;
		if (!vec_garo.empty())
		{
			size1 = vec_garo.size();
			for (int i = 0; i < size1; ++i)
			{
				sum1 += vec_garo[i].length;
			}
		}


		int sum2 = 0;
		int size2 = 0;
		if (!vec_sero.empty())
		{
			size2 = vec_sero.size();
			for (int i = 0; i < size2; ++i)
			{
				sum2 += vec_sero[i].length;
			}
		}

		if (core_max < size1 + size2)
		{
			core_max = size1 + size2;
			dir_min = sum1 + sum2;
		}
		else if (core_max == size1 + size2)
		{
			if (dir_min > sum1 + sum2)
				dir_min = sum1 + sum2;
		}
	}
	else
	{
		int res;
		int size = vec[num].size();

		if (size == 0)
		{
			start(num + 1);
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				if (vec[num][i].garo_sero == 1)//가로면
				{
					res = check_garo(vec[num][i]);
					if (res == 0)
						continue;
					vec_garo.push_back(vec[num][i]);
					start(num + 1);
					if (!vec_garo.empty())
						vec_garo.pop_back();
				}
				else//세로면
				{
					res = check_sero(vec[num][i]);
					if (res == 0)
						continue;
					vec_sero.push_back(vec[num][i]);
					start(num + 1);
					if (!vec_sero.empty())
						vec_sero.pop_back();
				}
			}
		}
	}
}
int check_garo(sunbun s)//가로선분이니까 세로벡터집합에서 찾아야함
{
	if (!vec_sero.empty())
	{
		int size = vec_sero.size();
		for (int i = 0; i < size; ++i)
		{
			if (max(s.start_y, s.end_y) >= vec_sero[i].start_y && min(s.start_y, s.end_y) <= vec_sero[i].start_y &&
				max(vec_sero[i].start_x, vec_sero[i].end_x) >= s.start_x && min(vec_sero[i].start_x, vec_sero[i].end_x) <= s.start_x)
			{
				return 0;
			}
		}
		return 1;
	}
	return 1;
}
int check_sero(sunbun s)//세로선분이니까 가로벡터집합에서 찾아야함
{
	if (!vec_garo.empty())
	{
		int size = vec_garo.size();
		for (int i = 0; i < size; ++i)
		{
			if (max(s.start_x, s.end_x) >= vec_garo[i].start_x && min(s.start_x, s.end_x) <= vec_garo[i].start_x &&
				max(vec_garo[i].start_y, vec_garo[i].end_y) >= s.start_y && min(vec_garo[i].start_y, vec_garo[i].end_y) <= s.start_y)
			{
				return 0;
			}
		}
		return 1;
	}
	return 1;
}