#include<cstdio>
#include<algorithm>
using namespace std;
struct info {
	char str[2];
	int num;
};
bool compare(info f, info g)
{
	return f.num < g.num;
}
info inf[6];
int func1()
{
	for (int i = 1; i<5; ++i)
	{
		if (inf[i].str[0] != inf[i + 1].str[0])
			return 0;
	}
	for (int i = 1; i<5; ++i)
	{
		if (inf[i].num + 1 != inf[i + 1].num)
			return 0;
	}
	return 900 + inf[5].num;
}

int func2()
{
	if (inf[1].num == inf[2].num &&
		inf[2].num == inf[3].num &&
		inf[3].num == inf[4].num)
		return 800 + inf[1].num;

	if (inf[2].num == inf[3].num &&
		inf[3].num == inf[4].num &&
		inf[4].num == inf[5].num)
		return 800 + inf[5].num;

	return 0;
}
int func3()
{
	//	printf("3");
	if (inf[1].num == inf[2].num &&
		inf[2].num == inf[3].num &&
		inf[4].num == inf[5].num)
		return inf[1].num * 10 + inf[5].num + 700;

	if (inf[1].num == inf[2].num &&
		inf[3].num == inf[4].num &&
		inf[4].num == inf[5].num)
		return inf[5].num * 10 + inf[1].num + 700;

	return 0;
}
int func4()
{
	//	printf("4");
	if (inf[1].str[0] == inf[2].str[0] &&
		inf[2].str[0] == inf[3].str[0] &&
		inf[3].str[0] == inf[4].str[0] &&
		inf[4].str[0] == inf[5].str[0])
		return inf[5].num + 600;

	return 0;
}
int func5()
{
	//	printf("5");
	if (inf[1].num == inf[2].num - 1 &&
		inf[1].num == inf[3].num - 2 &&
		inf[1].num == inf[4].num - 3 &&
		inf[1].num == inf[5].num - 4)
		return inf[5].num + 500;

	return 0;
}
int func6()
{
	//	printf("6");
	if (inf[1].num == inf[2].num &&
		inf[2].num == inf[3].num)
		return inf[1].num + 400;

	if (inf[2].num == inf[3].num &&
		inf[3].num == inf[4].num)
		return inf[2].num + 400;

	if (inf[3].num == inf[4].num &&
		inf[4].num == inf[5].num)
		return inf[3].num + 400;
	return 0;
}
int func7()
{
	//	printf("7");
	if (inf[1].num == inf[2].num &&
		(inf[3].num == inf[4].num ||
			inf[4].num == inf[5].num))
		return inf[1].num + inf[4].num * 10 + 300;

	if (inf[2].num == inf[3].num &&
		inf[4].num == inf[5].num)
		return inf[2].num + inf[4].num * 10 + 300;
	return 0;
}
int func8()
{
	//	printf("8");
	if (inf[1].num == inf[2].num)
		return inf[1].num + 200;

	if (inf[2].num == inf[3].num)
		return inf[2].num + 200;

	if (inf[3].num == inf[4].num)
		return inf[3].num + 200;

	if (inf[4].num == inf[5].num)
		return inf[4].num + 200;

	return 0;
}
int func9()
{
	return inf[5].num + 100;
}
int main()
{
	int res = 0;
	for (int i = 1; i <= 5; ++i)
	{
		scanf("%s %d", inf[i].str, &inf[i].num);
	}
	sort(inf + 1, inf + 6, compare);
	res = func1(); if (res) { printf("%d\n", res); return 0; }
	res = func2(); if (res) { printf("%d\n", res); return 0; }
	res = func3(); if (res) { printf("%d\n", res); return 0; }
	res = func4(); if (res) { printf("%d\n", res); return 0; }
	res = func5(); if (res) { printf("%d\n", res); return 0; }
	res = func6(); if (res) { printf("%d\n", res); return 0; }
	res = func7(); if (res) { printf("%d\n", res); return 0; }
	res = func8(); if (res) { printf("%d\n", res); return 0; }
	res = func9(); if (res) { printf("%d\n", res); return 0; }
}
