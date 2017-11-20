#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
#include<cmath>
using namespace std;


int main()
{
	char tmp[20];
	scanf("%s", tmp);

	double mul = 0;

	for (int i = 0; tmp[i] != '\0'; ++i)
	{
		if (tmp[i] != '.')
		{
			mul *= 10;
			mul += tmp[i] - '0';
		}
	}
	for (int i = 0; i < strlen(tmp) - 2; ++i)
	{
		mul *= 0.1;
	}

	printf("%d", mul);
}
