#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
using namespace std;

struct sunbun {
	
	int garo_sero;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
};

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

vector<sunbun> vec2;
vector<sunbun> vec_garo;
vector<sunbun> vec_sero;
vector<vector<sunbun> > vec;
int N,cnt;
int arr[13][13];

void start(int);
void set_sunbun();
int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		vec.clear();
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
		printf("싯팔\n");
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

	}
	else
	{
		int size = vec[num].size();
		for (int i = 0; i < size; ++i)
		{
			if (vec[num][i].garo_sero == 1)//가로면
			{
				vec_garo.push_back(vec[num][i]);
				start(num + 1);
				if(!vec_garo.empty())
					vec_garo.pop_back();
			}
			else
			{
				vec_sero.push_back(vec[num][i]);
				start(num + 1);
				if (!vec_sero.empty())
					vec_sero.pop_back();
			}
		}
	}
}