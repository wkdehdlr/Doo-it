#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char str[7];
	int n;
	int s = 0, num;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d", str, &num);
		if (!strcmp("add", str))
		{
			s = s | (1 << num); continue;
		}
		else if (!strcmp("remove", str))
		{
			s = s & ~(1 << num); continue;
		}
		else if (!strcmp("check", str))
		{
			if (s & (1 << num))
				puts("1");
			else
				puts("0");
			continue;
		}
		else if (!strcmp("toggle", str))
		{
			s = s ^ (1 << num); continue;
		}
		else if (!strcmp("all", str))
		{
			s = (1 << 21) - 1; continue;
		}
		else if (!strcmp("empty", str))
		{
			s = 0; continue;
		}
	}
}