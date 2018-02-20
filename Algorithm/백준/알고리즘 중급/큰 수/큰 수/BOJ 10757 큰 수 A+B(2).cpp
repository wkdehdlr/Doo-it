#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
char num1[10001];
char num2[10001];
char res[10001];

int main()
{
	scanf("%s %s", num1, num2);
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len3 = 0;
	int carry = 0;

	for (--len1, --len2; len1 >= 0 || len2 >= 0; --len1, --len2)
	{
		int tmp = 0;
		if (len1 >= 0)
			tmp += (num1[len1] - '0');
		if (len2 >= 0)
			tmp += (num2[len2] - '0');
		if (carry)
			tmp += 1;

		if (tmp >= 10)
			carry = 1;
		else
			carry = 0;

		res[len3++] = (tmp % 10) + '0';
	}

	if (carry)
		printf("1");
	for (int i = len3 - 1; i >= 0; --i)
	{
			printf("%c", res[i]);
	}
	printf("\n");
}