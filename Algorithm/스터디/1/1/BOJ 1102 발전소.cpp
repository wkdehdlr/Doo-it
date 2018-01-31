#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

char status[18];
int arr[17][17];
int dp[17][65536];
int N, P, Y;


int func(int degree, int start)
{
	if (degree == P - Y)//ex> p=4 y=3;
	{
		/*int min = 0x7fffffff;
		for (int i = N - 1; i >= 0; --i)
		{
			if (start & (1 << i))//시작할 발전소를 찾는다.
			{
				for (int j = N - 1; j >= 0; --j)
				{
					if (i != j && !(start & (1 << j)))//시작할 발전소에서 시작해서 켤 발전소를 찾는다.
					{
						if (arr[N - i][N - j] < min)min = arr[N - i][N - j];
					}
				}
			}
		}*/
		return 0;
	}

	if (dp[degree][start] != -1)return dp[degree][start];

	int temp, min = 0x7fffffff;
	int one_temp = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		if (start & (1 << i))//시작할 발전소를 찾는다.
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (i != j && !(start & (1 << j)))//시작할 발전소에서 시작해서 켤 발전소를 찾는다.
				{
					one_temp = start;
					temp = arr[N - i][N - j] + func(degree + 1, one_temp |= (1 << j));
					if (temp < min)min = temp;
				}
			}
		}
	}
	return dp[degree][start] = min;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%s", status); 
	scanf("%d", &P);

	int start = 0;//초기 발전소 상태 저장 YYNNY->11001
	for (int i = 0; status[i] != '\0'; ++i)
	{
		if (status[i] == 'Y')
		{
			start |= (1 << (N - i - 1));
			Y++;
		}
	}

	if (!Y)//모두 off면 불가능
	{
		printf("-1\n");
		return 0;
	}
	else if (Y >= P)//이미 켜진 발전소가 더 많을경우
	{
		printf("0\n");
		return 0;
	}
	else//그 외
	{
		printf("%d\n", func(0, start));
	}
}
/*
int func(int degree, int start, int sNum)
{
	if (degree == P - Y)//ex> p=4 y=3;
	{
		int min = 0x7fffffff;
		for (int i = N - 1; i >= 0; --i)
		{
			if (!(start & (1 << i)))//11001
			{
				if (min > arr[sNum][N - i])
					min = arr[sNum][N - i];
			}
		}
		return min;
	}

	if (dp[degree][start] != -1)return dp[degree][start];

	int temp, min = 0x7fffffff;
	int one_temp = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		if (!sNum)//11001 -> 일단 시작할 발전소를 찾는다.
		{
			if (start & (1 << i))
			{
				func(degree + 1, start, N - i);
			}
		}
		else
		{
			if (!(start & (1 << i)))//시작할 발전소에서 시작해서 켤 발전소를 찾는다.
			{
				one_temp = start;
				temp = arr[sNum][N - i] + func(degree, one_temp |= (1 << i), 0);
				if (temp < min)min = temp;
			}
		}
	}
	return dp[degree][start] = min;
}*/