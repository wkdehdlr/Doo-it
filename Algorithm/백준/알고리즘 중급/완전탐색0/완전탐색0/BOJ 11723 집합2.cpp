#pragma warning(disable : 4996)
#include<cstdio>
int main()
{
	char str[7];
	int n;
	int s = 0, num;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d", str, &num);
		switch (str[0])
		{
		case 'a':if (str[1] == 'd')s = s | (1 << num); else s = (1 << 21) - 1; break;
		case 'r':s = s & ~(1 << num); break;
		case 'c':if (s & (1 << num))puts("1"); else puts("0"); break;
		case 't':s = s ^ (1 << num); break;
		case 'e':s = 0; break;
		}
	}
}