#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int main()
{
	int T;
	int mask;
	int temp;
	int k = 1;
	int N;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);
		mask = (1 << 10) - 1;
		k = 1;
		temp = N;
		while (mask)
		{
			temp = N*k;
			while (temp)
			{
				mask &= ~(1 << (temp % 10));
				temp /= 10;
			}
			k++;
		}
		printf("#%d %d\n", tc + 1, N*(k - 1));
	}
}