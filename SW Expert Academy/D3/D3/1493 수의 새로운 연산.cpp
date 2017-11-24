#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

struct info {
	int x;
	int y;
};
int T;
int arr[300][300];
info arrP[100000];

int main()
{
	info in;
	int temp = 0;
	for (int i = 1; i <= 300; ++i)
	{
		int cnt = 0;
		int x = 1;
		int y = i;
		while (1)
		{		
			temp++;
			cnt++;
			in.x = x; in.y = y;
			arr[x][y] = temp;
			arrP[temp] = in;
			if (cnt == i)
				break;
			x++;
			y--;
		}
	}

	int num1=0, num2=0, res=0;
	int x=0, y=0;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &num1, &num2);
		x = arrP[num1].x + arrP[num2].x;
		y = arrP[num1].y + arrP[num2].y;

		res = arr[x][y];
		printf("#%d %d\n", tc + 1, res);
	}
}