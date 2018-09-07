#pragma warning(disable : 4996)
#include<cstdio>

char astr[110];
char bstr[110];
int op_a, op_b;
int my_strlen(char *str)
{
	int idx = 0;
	while (str[idx])idx++;
	return idx;
}
void multi(char *str1, char *str2)
{
	int res[210] = { 0, };
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);

	for (int i = 0; i < len1; ++i) {
		for (int j = 0; j < len2; ++j) {
			res[i + j] += (str1[i] - '0')*(str2[j] - '0');
		}
	}

	for (int i = len1 + len2 - 2; i >= 1; --i) {
		res[i - 1] += (res[i] / 10);
		res[i] %= 10;
	}

	for (int i = 0; i <= len1 + len2 - 2; ++i)
		printf("%d", res[i]);
	printf("\n");
}
int main()
{
	while (1)
	{
		scanf("%s %s", astr, bstr);
		if (astr[0] == '0')return 0;
		if (bstr[0] == '0') {
			printf("0\n");
			continue;
		}
		op_a = (astr[0] == '-');
		op_b = (bstr[0] == '-');
		if (op_a + op_b == 1)printf("-");
		multi(astr + op_a, bstr + op_b);
	}
}