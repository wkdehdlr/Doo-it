#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
struct info
{
	double num;
	int group;
};
bool operator<(info f, info g)
{
	return f.num > g.num;
}
priority_queue<info> pq;
int N, x1, y;
int blue = 0, red = 0;

int main()
{
	scanf("%d %d %d", &N, &x1, &y);
	for (int i = 0; i < N; ++i)
	{
		int x2, y2, group;
		scanf("%d %d %d", &x2, &y2, &group);
		pq.push({ sqrt(pow(x1 - x2, 2) + pow(y - y2, 2)),group });
	}
	for (int i = 0; i < 3; ++i)
	{
		if (pq.top().group)
			red++;
		else
			blue++;
		pq.pop();
	}
	red > blue ? printf("RED %d\n", red) : printf("BLUE %d\n", blue);
	for (int i = 0; i < 2; ++i)
	{
		if (pq.top().group)
			red++;
		else
			blue++;
		pq.pop();
	}
	red > blue ? printf("RED %d\n", red) : printf("BLUE %d\n", blue);
}
