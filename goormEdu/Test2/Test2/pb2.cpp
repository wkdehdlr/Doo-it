#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int x1, y1, x2, y2;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);


	//점
	if (x1 == x2 && y1 == y2)
	{
		printf("DOT\n");
		return 0;
	}
	//선분
	if ((x1 == x2 && y1 != y2) || (y1 == y2 && x1 != x2))
	{
		printf("SEGMENT\n");
		return 0;
	}
	//정사각형
	if (abs(x1 - x2) == abs(y1 - y2))
	{
		printf("SQUARE\n");
	}
	else
	{
		printf("RECTANGLE\n");
	}
	return 0;
}