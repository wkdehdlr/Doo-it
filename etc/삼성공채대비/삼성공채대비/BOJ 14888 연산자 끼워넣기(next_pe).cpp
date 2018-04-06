#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;
int num[12];
int op[11];
int N, idx = 1;
int mn = 0x7fffffff, mx = -210000000;

void func()
{
	do {
		int idxx = 1;
		int num1 = num[1];
		int num2 = num[2];
		switch (op[idxx])
		{
		case 1:num1 += num2; break;
		case 2:num1 -= num2; break;
		case 3:num1 *= num2; break;
		case 4:num1 /= num2; break;
		}

		for (idxx = 3; idxx <= N; ++idxx)
		{
			switch (op[idxx - 1])
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

	} while (next_permutation(op + 1, op + N));	
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
	func();
	printf("%d\n%d\n", mx, mn);
}