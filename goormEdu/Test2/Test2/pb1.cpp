#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int flag = false;
int num[5];
int a1, a2, a3, a4, a5, total = 0;
int main()
{	
	scanf("%d", &a1); num[0] = a1;
	scanf("%d", &a2); num[1] = a2;
	scanf("%d", &a3); num[2] = a3;
	scanf("%d", &a4); num[3] = a4;
	scanf("%d", &num[4]);

	while (1)
	{
		if (num[0])
			num[0]--;
		if (num[1])
			num[1]--;
		if (num[2])
			num[2]--;
		if (num[3])
			num[3]--;

		total++;

		if (!num[0] && !num[1] && !num[2] && !num[3] && flag)
			break;

		if (!num[0] && !flag)
		{
			num[0] = num[4];
			flag = true;
		}
		if (!num[1] && !flag)
		{
			num[1] = num[4];
			flag = true;
		}
		if (!num[2] && !flag)
		{
			num[2] = num[4];
			flag = true;
		}
		if (!num[3] && !flag)
		{
			num[3] = num[4];
			flag = true;
		}
	}
	printf("%d\n", total);
}