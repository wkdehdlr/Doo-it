#pragma warning(disable : 4996)
#include<cstdio>

bool visit[11];
int num[12];
int res[11];
int op[11];
int N, idx = 1;
int mn = 0x7fffffff, mx = -210000000;
void func(int dep)
{
	if (dep == N)
	{
		int idxx = 1;
		int num1 = num[1];
		int num2 = num[2];
		switch (res[idxx])
		{
		case 1:num1 += num2; break;
		case 2:num1 -= num2; break;
		case 3:num1 *= num2; break;
		case 4:num1 /= num2; break;
		}
		
		for (idxx = 3; idxx <= N; ++idxx)
		{
			switch (res[idxx- 1])
			{
			case 1:num1 += num[idxx]; break;
			case 2:num1 -= num[idxx]; break;
			case 3:num1 *= num[idxx]; break;
			case 4:
				if (num1 < 0) {
					num1 *= -1;
					num1 /= num[idxx];
					num1 *= -1;
					break;
				}
				else {
					num1 /= num[idxx]; break;
				}
			}
		}
		if (num1 > mx)
			mx = num1;
		if (num1 < mn)
			mn = num1;
	}
	else
	{
		for (int i = 1; i <= N - 1; ++i)
		{
			if (!visit[i]) {
				visit[i] = true;
				res[dep] = op[i];
				func(dep + 1);
				visit[i] = false;
				res[dep] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &num[i]);//연산숫자들 입력받음
	for (int i = 1; i <= 4; ++i)//연산자 세팅
	{
		int temp;
		scanf("%d", &temp);
		while (temp--) {
			op[idx++] = i;
		}
	}
	for (int i = 1; i <= N - 1; ++i)
	{
		if (!visit[i]) {
			visit[i] = true;
			res[1] = op[i];
			func(2);
			visit[i] = false;
			res[1] = 0;
		}
	}
	printf("%d\n%d\n", mx, mn);
}