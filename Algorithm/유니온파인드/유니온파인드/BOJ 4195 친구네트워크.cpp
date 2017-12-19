#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_KEY 20
#define MAX_TABLE 200001


int arr[200001];
typedef struct
{
	char key[MAX_KEY + 1];
	int data;
}Hash;

Hash tb[MAX_TABLE];
Hash tb_init;
int cnt = 0;

/*
int strcmp(char *key1, const char *key2)
{
	for (int i = 0; key1[i] != '\0'; ++i)
	{
		if (key1[i] != key2[i])
			return 1;
	}
	return 0;
}
void strcpy(char *key1, const char *key2)
{
	int i = 0;
	for (; key2[i] != '\0'; ++i)
	{
		key1[i] = key2[i];
	}
	key1[i] = '\0';
}*/
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
int add(const char *key)
{
	unsigned long h = hash(key);
	int step = 1;
	int i = 0;

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return tb[h].data;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	tb[h].data = h;
	arr[tb[h].data] = -1;//새로운게 추가됬으니까 -1로 초기화
	return tb[h].data;
}
int find(int n)
{
	if (arr[n] < 0)return n;
	return arr[n] = find(arr[n]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
	{
		printf("%d\n", -arr[a]);
		return;
	}
	arr[a] += arr[b];
	arr[b] = a;
	printf("%d\n", -arr[a]);
}


int T, F;
char temp1[21];
char temp2[21];



int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		//cnt = 0;
		scanf("%d", &F);
		for (int i = 0; i < F; ++i)
		{
			scanf("%s %s", temp1,temp2);
			merge(add(temp1), add(temp2));
		}

		for (int i = 0; i < 200001; ++i)
		{
			arr[i] = 0;
			tb[i] = tb_init;
		}
	}
}