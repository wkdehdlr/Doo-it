#pragma warning(disable : 4996)
#include <stdio.h>
//#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 5
typedef struct
{
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
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

int find(const char *key, char *data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;
	int step = 1;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			strcpy(data, tb[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int add(const char *key, char *data)
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
	strcpy(tb[h].data, data);
	return 1;
}


int main(int argc, char* argv[])
{
	int T, N, Q;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for (int i = 0; i < N; i++)
		{
			scanf("%s %s", &k, &d);
			add(k, d);
		}

		printf("#%d\n", test_case);

		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s", &k);

			if (find(k, d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}