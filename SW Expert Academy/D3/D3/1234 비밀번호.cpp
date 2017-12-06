#pragma warning(disable : 4996)
#include<cstdio>
#define MAX_N 101
using namespace std;


int N;
int top;
char stack[MAX_N], temp;

void stackInit(void)
{
	top = 0;
}

int stackIsEmpty(void)
{
	return (top == 0);
}

int stackIsFull(void)
{
	return (top == MAX_N);
}

int stackPush(char value)
{
	if (stackIsFull())
	{
		printf("stack overflow!");
		return 0;
	}
	stack[top] = value;
	top++;

	return 1;
}

char stackPop()
{
	top--;
	return stack[top];
}

char stackTop()
{
	return stack[top - 1];
}
int stackSize()
{
	return top;
}
char stackPrint()
{
	top++;
	return stack[top - 1];
}

int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &N);
		scanf("%*c");
		stackInit();
		for (int i = 0; i < N; ++i)
		{
			scanf("%c", &temp);
			if (!stackIsEmpty())//안비어있음
			{
				if (stackTop() == temp)//같으면
					stackPop();
				else
					stackPush(temp);
			}
			else//비어있음
			{
				stackPush(temp);
			}
		}
		scanf("%*c");
		printf("#%d ", tc + 1);
		int size = stackSize();
		stackInit();
		for (int i = 0; i < size; ++i)
		{
			printf("%c", stackPrint());
		}
		printf("\n");
	}
}
