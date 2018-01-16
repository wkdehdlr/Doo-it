#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int cnt = 0;
vector<pair<int, int> > vec;
bool visited[16];
int N;
bool func2(int x, int y)
{
	for (int i = 0; i<vec.size(); ++i)
	{
		if (abs(vec[i].first - x) == abs(vec[i].second - y))
			return false;
	}
	return true;
}

void func(int n)
{
	if (n == N + 1)
	{
		cnt++;
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				if (func2(n, i))
				{
					visited[i] = true;
					vec.push_back({ n,i });
					func(n + 1);
					visited[i] = false;
					if (vec.size())
						vec.pop_back();
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	func(1);
	printf("%d\n", cnt);
}