#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

struct op
{
	char digit[1005];
	int sign;
	int len;
};

op num1, num2;
char res[1005];
int mul[2050];
int big;
void print_mul(int idx3)
{
	for (int i = idx3 - 1; i >= 0; --i)
	{
		printf("%d", mul[i]);
	}
	printf("\n");
}
void print(int idx3)
{
	int i = idx3 - 1;
	if (res[i] == '-')
	{
		printf("-");
		--i;
	}
	while (res[i] == '0')
		--i;
	
	for (; i >= 0; --i)
	{
		printf("%c", res[i]);
	}
	printf("\n");
}
int abs()
{
	int len1 = num1.sign ? num1.len : num1.len - 1;
	int len2 = num2.sign ? num2.len : num2.len - 1;

	if (len1 > len2)
		return 1;
	else if (len1 < len2)
		return -1;
	else
	{
		int idx1 = num1.sign ? 0 : 1;
		int idx2 = num2.sign ? 0 : 1;
		int limit1 = num1.len - 1;
		int limit2 = num2.len - 1;
		for (; idx1 <= limit1 && idx2 <= limit2; ++idx1, ++idx2)
		{
			if (num1.digit[idx1] > num2.digit[idx2])
				return 1;
			else if (num1.digit[idx1] < num2.digit[idx2])
				return -1;
		}
		return 0;
	}
}
void muti(op *nu1, op *nu2)
{
	int idx2 = nu2->len - 1;
	int idx3 = 0;
	int limit1 = nu1->sign ? 0 : 1;
	int limit2 = nu2->sign ? 0 : 1;
	int carry = 0;
	for (int i = 0; idx2 >= limit2; --idx2, ++i)
	{
		idx3 = i;
		carry = 0;
		for (int idx1 = nu1->len - 1; idx1 >= limit1; --idx1)
		{
			int tmp = (nu1->digit[idx1] - '0') * (nu2->digit[idx2] - '0');

			if (carry)
				tmp += carry;
			else
				carry = 0;

			int ans = tmp % 10;
			carry = tmp / 10;

			mul[idx3] += ans;
			if (mul[idx3] >= 10)
			{
				mul[idx3] %= 10;
				carry++;
			}				
			idx3++;
		}
		if (carry)
			mul[idx3++] = carry;
	}
	if (nu1->sign != nu2->sign && nu1->digit[0] != '0' && nu2->digit[0] != '0')
		printf("-");
	print_mul(idx3);
}
void plus_minus(op *nu1, op * nu2)
{
	int idx1 = nu1->len - 1;
	int idx2 = nu2->len - 1;
	int idx3 = 0;
	int limit1 = nu1->sign ? 0 : 1;
	int limit2 = nu2->sign ? 0 : 1;
	int carry = 0;


	for (; idx1 >= limit1 || idx2 >= limit2; --idx1, --idx2)
	{
		int tmp = 0;
		if (idx1 >= limit1)
		{
			tmp += (nu1->digit[idx1] - '0');
		}

		if (idx2 >= limit2)
		{
			tmp -= (nu2->digit[idx2] - '0');
		}

		if (carry)
			tmp -= 1;

		if (tmp < 0)
		{
			tmp += 10;
			carry = 1;
		}
		else
			carry = 0;

		res[idx3++] = tmp + '0';
	}

	if (!nu1->sign)
		res[idx3++] = '-';
	/*if (big == 1)//num1이 더 큼
	{
		if (!num1.sign)
			res[idx3++] = '-';
	}
	else if (big == -1)//num2가 더 큼
	{
		if (num2.sign)
			res[idx3++] = '-';
	}*/
	print(idx3);
}
void plus_plus()
{
	int idx1 = num1.len - 1;
	int idx2 = num2.len - 1;
	int idx3 = 0;
	int limit1 = num1.sign ? 0 : 1;
	int limit2 = num2.sign ? 0 : 1;
	int carry = 0;


	for (; idx1 >= limit1 || idx2 >= limit2; --idx1, --idx2)
	{
		int tmp = 0;
		if (idx1 >= limit1)
		{
			tmp += (num1.digit[idx1] - '0');
		}

		if (idx2 >= limit2)
		{
			tmp += (num2.digit[idx2] - '0');
		}

		if (carry)
			tmp += 1;

		if (tmp >= 10)
		{
			tmp %= 10;
			carry = 1;
		}
		else
			carry = 0;

		res[idx3++] = tmp + '0';
	}
	if(carry)
		res[idx3++] = '1';
	if(!num1.sign)
		res[idx3++] = '-';

	print(idx3);
}
void plus()
{
	if (num1.sign == num2.sign)//부호가 같으면
	{
		plus_plus();
	}
	else//부호가 다르면
	{
		if (big == 1)//num1이 더 큼
		{
			plus_minus(&num1, &num2);
		}
		else if (big == 0)//절대값이 같음
		{
			printf("0\n");
		}
		else//num2가 더 큼
		{
			plus_minus(&num2, &num1);
		}
	}
}
void minus()
{
	if (num1.sign == num2.sign)//부호가 같으면
	{
		if (big == 1)//num1이 더 큼
		{
			plus_minus(&num1, &num2);
		}
		else if (big == 0)//절대값이 같음
		{
			printf("0\n");
		}
		else//num2가 더 큼
		{
			plus_minus(&num2, &num1);
		}
	}
	else//부호가 다르면
	{
		plus_plus();
	}
}
void multiply()
{
	if (big == 1)//num1이 더 크다
	{
		muti(&num1, &num2);
	}
	else//그외
	{
		muti(&num2, &num1);
	}
}
void set()
{
	scanf("%s %s", num1.digit, num2.digit);
	num1.len = strlen(num1.digit);
	num2.len = strlen(num2.digit);

	if (num1.digit[0] == '-')num1.sign = 0;//음수(0), 양수(1)체크
	else num1.sign = 1;

	if (num2.digit[0] == '-')num2.sign = 0;//음수(0), 양수(1)체크
	else num2.sign = 1;

	big = abs();
}
void initialize()
{
	for (int i = 0; i < 1005; ++i)res[i] = '\0';
}
int main()
{
	set();
	plus();
	initialize();
	minus();
	initialize();
	multiply();
}