#pragma warning(disable : 4996)
#define MAX_KEY 8
#define MAX_TABLE 10000000
#include<cstdio>
using namespace std;

typedef struct
{
	char key[MAX_KEY];
	bool data;
}Hash;

Hash tb[6][MAX_TABLE];
int strcmp(char *f1, const char *f2)
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
	int i = 0;
	for (; src[i] != '\0'; ++i)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
}
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

bool find(const char *key, int depth)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;
	int step = 1;

	while (tb[depth][h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[depth][h].key, key) == 0)
		{
			return tb[depth][h].data;
			//strcpy(data, tb[h].data);
			//return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return tb[depth][h].data;
	//return 0;
}

int add(const char *key, int depth)
{
	unsigned long h = hash(key);
	int step = 1;
	int i = 0;

	while (tb[depth][h].key[0] != 0)
	{
		if (strcmp(tb[depth][h].key, key) == 0)
		{
			return 0;
		}
		h = (h + 1) % MAX_TABLE;
	}

	strcpy(tb[depth][h].key, key);
	tb[depth][h].data = true;
	//strcpy(tb[h].data, data);
	return 1;
}

int arr[4][4];
int T;

void DFS(int, int, int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				DFS(i, j, 0);
			}
		}
	}
}
void DFS(int i, int j,int depth)
{
	if (depth == 6)
	{

	}
	else
	{

	}
}