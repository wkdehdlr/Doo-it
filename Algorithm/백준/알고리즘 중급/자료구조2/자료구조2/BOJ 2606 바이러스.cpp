#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[101];
int N, M, cnt = 0;
int find(int a)
{
	if (arr[a] == a)return a;
	else return arr[a] = find(arr[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return;
	arr[b] = a;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)arr[i] = i;
	for (int i = 0; i < M; ++i)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		merge(num1, num2);
	}
	int res = find(arr[1]);
	for (int i = 2; i <= N; ++i)
	{
		if (find(arr[i]) == res)
			cnt++;
	}
	printf("%d\n",cnt);
}