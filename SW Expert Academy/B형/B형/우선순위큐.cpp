#pragma warning(disable : 4996)
#include <cstdio>

#define MAX_SIZE 100
struct info {
	int x, y;
};
info heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(int x, int y)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize].x = x;
	heap[heapSize].y = y;

	int current = heapSize;
	while (current > 0 && heap[current].x < heap[(current - 1) / 2].x)
	{
		int temp_x = heap[(current - 1) / 2].x;
		int temp_y = heap[(current - 1) / 2].y;
		heap[(current - 1) / 2].x = heap[current].x;
		heap[(current - 1) / 2].y = heap[current].y;
		heap[current].x = temp_x;
		heap[current].y = temp_y;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(info *value)
{
	if (heapSize <= 0)
	{
		return -1;
	}

	value->x = heap[0].x;
	value->y = heap[0].y;
	heapSize = heapSize - 1;

	heap[0] = heap[heapSize];

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
			child = heap[current * 2 + 1].x < heap[current * 2 + 2].x ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current].x < heap[child].x)
		{
			break;
		}

		int temp_x = heap[current].x;
		int temp_y = heap[current].y;
		heap[current].x = heap[child].x;
		heap[current].y = heap[child].y;
		heap[child].x = temp_x;
		heap[child].y = temp_y;

		current = child;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		heapInit();

		for (int i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			heapPush(x, y);
		}

		printf("#%d ", test_case);

		for (int i = 0; i < N; i++)
		{
			info value;
			heapPop(&value);
			printf("%d %d\n", value.x, value.y);
		}
		printf("\n");
	}
	return 0;
}