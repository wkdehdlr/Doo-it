#pragma warning(disable : 4996)
#include<cstdio>

char num1[10010];
char num2[10010];
char res[10010];

int strlength(char num[])
{
	int i = 0; for (; num[i] != '\0'; ++i); return i;
}
int main()
{
	scanf("%s %s", num1, num2);

	int len_num1 = strlength(num1);
	int len_num2 = strlength(num2);
	int carry = 0;

	if (len_num1 > len_num2)
	{
		while (len_num1 && len_num2)
		{
			--len_num1; --len_num2;
			int tmp = (num1[len_num1] - '0') + (num2[len_num2] - '0');
			if (carry)
				tmp += 1;

			int ans = 0;
			if (tmp >= 10)
			{
				ans = tmp - 10;
				carry = 1;
			}
			else
			{
				ans = tmp;
				carry = 0;
			}
			res[len_num1 + 1] = ans + '0';
		}
		while (len_num1)
		{
			--len_num1;
			int tmp = num1[len_num1] - '0';
			if (carry)
				tmp += 1;

			int ans = 0;
			if (tmp >= 10)
			{
				ans = tmp - 10;
				carry = 1;
			}
			else
			{
				ans = tmp;
				carry = 0;
			}
			res[len_num1 + 1] = ans + '0';
		}
		if (carry)
			res[len_num1] = '1';
	}
	else if (len_num1 == len_num2)
	{
		while (len_num1 && len_num2)
		{
			--len_num1; --len_num2;
			int tmp = (num1[len_num1] - '0') + (num2[len_num2] - '0');
			if (carry)
				tmp += 1;

			int ans = 0;
			if (tmp >= 10)
			{
				ans = tmp - 10;
				carry = 1;
			}
			else
			{
				ans = tmp;
				carry = 0;
			}
			res[len_num2 + 1] = ans + '0';
		}
		if(carry)
			res[len_num2] = '1';
	}
	else
	{
		while (len_num1 && len_num2)
		{
			--len_num1; --len_num2;
			int tmp = (num1[len_num1] - '0') + (num2[len_num2] - '0');
			if (carry)
				tmp += 1;

			int ans = 0;
			if (tmp >= 10)
			{
				ans = tmp - 10;
				carry = 1;
			}
			else
			{
				ans = tmp;
				carry = 0;
			}
			res[len_num2 + 1] = ans + '0';
		}
		while (len_num2)
		{
			--len_num2;
			int tmp = num2[len_num2] - '0';
			if (carry)
				tmp += 1;

			int ans = 0;
			if (tmp >= 10)
			{
				ans = tmp - 10;
				carry = 1;
			}
			else
			{
				ans = tmp;
				carry = 0;
			}
			res[len_num2 + 1] = ans + '0';
		}
		if (carry)
			res[len_num2] = '1';
	}

	for (int i = 0; i < 10010; ++i)
	{
		if (res[i] != '\0')
		{
			printf("%c", res[i++]);
			while (res[i] != '\0')
			{
				printf("%c", res[i++]);
			}
			printf("\n");
			return 0;
		}
	}
}