#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
using namespace std;

int cnt = 0, r, c;
bool solve(int x, int y, int n)
{
	if (n == 1)
	{
		if (x == r && y == c)
		{
			printf("%d", cnt);
			return true;
		}
		else
		{
			cnt++;
			return false;
		}
	}
	else
	{
		int m = n / 2;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if (r >= x + m*i && r < x + m*i + m && c >= y + m*j && c < y + m*j + m)
				{
					if (solve(x + m*i, y + m*j, m))
						return true;
				}
				else
					cnt += ((m*m));
			}
		}
		return false;
	}
}
int main()
{
	int n;
	scanf("%d %d %d", &n, &r, &c);
	solve(0, 0, pow(2, n));
}