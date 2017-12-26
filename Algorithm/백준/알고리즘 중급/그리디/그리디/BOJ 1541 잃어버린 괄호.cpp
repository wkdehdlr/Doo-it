#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

char str[100];
int main()
{
	scanf("%s", str);
	int mul = 0, pluss = 0;
	bool check = false;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '+')
		{
			pluss += mul;
			mul = 0;
		}
		else if (str[i] == '-')
		{
			pluss += mul;
			mul = 0;
			check = true;
		}
		else
		{
			if (check)
			{
				mul *= 10;
				mul -= str[i] - '0';
			}
			else
			{
				mul *= 10;
				mul += str[i] - '0';
			}
		}
	}
	pluss += mul;
	printf("%d\n", pluss);
}