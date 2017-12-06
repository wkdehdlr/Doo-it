#pragma warning(disable : 4996)
#include<cstdio>
//#include <memory.h>

#define MAX_KEY 10
#define MAX_DATA 128
#define MAX_TABLE 10
using namespace std;

typedef struct
{
	char key[MAX_KEY + 1];
	int data;
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

bool strcmp(const char *f1, const char *f2)
{
	for (int i = 0; f1[i] != '\0'; ++i)
	{
		if (f1[i] != f2[i])
			return 1;
	}
	return 0;
}
void strcpy(char *des, const char *src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
}

int find(const char *key, int *data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;
	int step = 1;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			*data = tb[h].data;
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int add(const char *key, int data)
{
	unsigned long h = hash(key);
	int step = 1;
	int i = 0;

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	tb[h].data = data;
	return 1;
}

int T, N, M, cnt, X, Y;
char arr[52][101];
char arr_temp[101];
char str;
char num[10][8] = { {"0001101"},{"0011001"},{"0010011"},
					{"0111101"},{"0100011"},{"0110001"},
					{"0101111"},{"0111011"},{"0110111"}, 
                    {"0001011"} };

void func();
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		add(num[i], i);
	}

	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &N, &M);
		scanf("%c", &str);
		for (int i = 0; i < N; ++i)
		{
			cnt = -1;
			for (int j = 0; j < M; ++j)
			{
				scanf("%c", &arr[i][j]);
				if (arr[i][j]=='1' && cnt == -1)
				{
					X = i; Y = j;
					cnt = 1;
				}
				if (cnt != -1)
				{
					cnt++;
					if (cnt == 57)
					{
						int k = j;
						while (arr[i][k]=='0')
						{
							k--;
						}
						Y -= (j - k);
						fgets(arr_temp, M - cnt+1, stdin);
						break;
					}
				}
			}
			scanf("%c",&str);

			if (cnt != -1)
			{
				int k;
				for (k = i + 1; k < N; ++k)
				{
					fgets(arr_temp, M + 2, stdin);
				}
				i = k;
			}
		}
		printf("#%d ", tc + 1);
		func();
	}
}
void func()
{
	int total = 0;
	int odd = 0, even = 0;
	int res = 0;
	char str_temp[8];
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			str_temp[j] = arr[X][Y + j];
		}
		str_temp[7] = '\0';
		find(str_temp, &res);
		Y += 7;

		total += res;
		if (i % 2)
			odd += res;
		else
			even += res;
	}
	even += (odd * 3);
	if (even % 10)//나누어떨어지지않는다
		printf("0\n");
	else//
		printf("%d\n", total);
}