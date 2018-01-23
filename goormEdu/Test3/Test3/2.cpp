#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int N;
char num[5];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int res = 0;
		scanf("%s", num);
		for (int i = 0; num[i] != '\0'; ++i)
		{
			res += (num[i] - '0');
		}
		if (res % 9)
			printf("%d\n", 9 - (res % 9));
		else
			printf("9\n");
	}
}