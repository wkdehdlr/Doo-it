#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace std;
#define MAX_KEY 20
#define MAX_TABLE 100000
typedef struct
{
	char *key = NULL;
	//char key[MAX_KEY + 1];
	int data;
}Hash;
Hash tb[MAX_TABLE];

char* heap[MAX_TABLE];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}
int heapPush(char* value)
{
	if (heapSize + 1 > MAX_TABLE)
	{
		printf("queue is full!");
		return 0;
	}
	heap[heapSize] = (char *)malloc(sizeof(char)*strlen(value) + 1);
	strcpy(heap[heapSize], value);
	

	int current = heapSize;
	while (current > 0 && strcmp(heap[current], heap[(current - 1) / 2]) == -1)
	{
		char temp[21];
		strcpy(temp, heap[(current - 1) / 2]);
		strcpy(heap[(current - 1) / 2], heap[current]);
		strcpy(heap[current], temp);
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}
int heapPop(char *value)
{
	if (heapSize <= 0)
	{
		return -1;
	}
	strcpy(value, heap[0]);
	heapSize = heapSize - 1;
	strcpy(heap[0], heap[heapSize]);
	free(heap[heapSize]);

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = strcmp(heap[current * 2 + 1], heap[current * 2 + 2]) == -1 ? current * 2 + 1 : current * 2 + 2;
		}

		if (strcmp(heap[current], heap[child]) == -1)
		{
			break;
		}

		char temp[21];
		strcpy(temp, heap[current]);
		strcpy(heap[current], heap[child]);
		strcpy(heap[child], temp);
		current = child;
	}
	return 1;
}
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

	while (tb[h].key != NULL)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return ++tb[h].data;
		}

		h = (h + 1) % MAX_TABLE;
	}
	tb[h].key = (char *)malloc(sizeof(char)*strlen(key) + 1);
	strcpy(tb[h].key, key);
	return ++tb[h].data;
}

int cnt = 0;
int N, M;
char name[21];
char tmp[21];

int main()
{
	scanf("%d %d", &N, &M);
	N += M;
	heapInit();
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", name);
		if (add(name) == 2)
		{
			heapPush(name);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
	{
		heapPop(tmp);
		printf("%s\n", tmp);
	}
	for (int i = 0; i < MAX_TABLE; ++i)
		if (tb[i].key != NULL)
			free(tb[i].key);
	return 0;
}