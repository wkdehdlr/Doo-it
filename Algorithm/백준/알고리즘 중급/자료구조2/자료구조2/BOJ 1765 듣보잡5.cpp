#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX_TABLE 1000000
typedef struct
{
	char key[21];
	int data;
}Hash;
Hash tb[MAX_TABLE];
char c[500000][21];
unsigned long hashh(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}
int add(const char *key)
{
	unsigned long h = hashh(key);
	int step = 1;
	int i = 0;

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return ++tb[h].data;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	return ++tb[h].data;
}
int cmp(const void *v1, const void *v2) {
	return strcmp((const char *)v1, (const char *)v2);
}
int cnt = 0;
int N, M;
char name[21];
char tmp[21];

int main()
{
	scanf("%d %d", &N, &M);
	N += M;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", name);
		if (add(name) == 2)
		{
			strcpy(c[cnt++], name);
		}
	}
	printf("%d\n", cnt);
	qsort(c, cnt, sizeof(c[0]), cmp);
	for (int i = 0; i < cnt; ++i)
	{
		printf("%s\n", c[i]);
	}
	return 0;
}