#pragma warning(disable : 4996)
#include<cstdio>
struct info {
	int num1, num2;
};
int ans = 0;
int N, M;
bool visited[21];
info inf[50];

void func(int degree, int sum)
{
	if (degree == M)
	{
		if (sum > ans)
			ans = sum;
	}
	else
	{
		int num1 = inf[degree].num1;
		int num2 = inf[degree].num2;
		if (!visited[num1] && !visited[num2])//���� ¦�� �ɼ��ִ� ���� 
		{
			visited[num1] = true;
			visited[num2] = true;
			func(degree + 1, sum + 2);
			visited[num1] = false;
			visited[num2] = false;
		}
		func(degree + 1, sum);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &inf[i].num1, &inf[i].num2);
	}
	func(0, 0);
	if (N != ans)ans++;
	printf("%d\n", ans);
}