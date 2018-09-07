#pragma warning(disable : 4996)
#include<cstdio>

char astr[210];
char bstr[210];
int alen;
int blen;
void output(int *ary)
{
	bool ok = true;
	int idx = 0;
	while (idx <= 200 && ary[idx]==0)idx++;
	for (; idx <= 200; ++idx) {
		printf("%d", ary[idx]);
		ok = false;
	}
	if (!ary[200] && ok)printf("0");
	printf("\n");
}
void sub(int *a, int *b, int *res)
{
	for (int i = 200; i >= 0; --i)
	{
		res[i] += (a[i] - b[i]);
		if (!i)return;
		if (res[i] < 0) {
			res[i] += 10;
			res[i - 1]--;
		}
	}
}
void sum(int *a, int *b, int *res)
{
	for (int i = 200; i >= 0; --i)
	{
		res[i] += (a[i] + b[i]);
		if (!i)return;
		res[i - 1] = res[i] / 10;
		res[i] %= 10;
	}
}
void encode(char *str, int *ary, int len)
{
	int i = 200;
	int j = len - 1;
	for (; j >= 0; --i, --j)
		ary[i] = str[j] - '0';
}
void func(char *str1, int len1, char *str2, int len2)
{
	int A[210] = { 0, }, B[210] = { 0, }, sm[210] = { 0, }, sb[210] = { 0, };
//	for (int i = 0; i <= 200; ++i)
	//	printf("%d", A[i]);
	//printf("\n%s\n", str1);
	encode(str1, A, len1);
	encode(str2, B, len2);

	//printf("||||||||||||\n");
	//for (int i = 0; i <= 200; ++i)
		//printf("%d", A[i]);
	//printf("\n");
	sum(A, B, sm);
	sub(A, B, sb);
	output(sm);
	output(sb);
}
int my_strlen(char *str)
{
	int idx = 0;
	while (str[idx])idx++;
	return idx;
}
int my_strcmp(char *str1, char *str2)
{
	alen = my_strlen(str1);
	blen = my_strlen(str2);
	if (alen > blen)return 1;
	else if (alen < blen)return 0;

	for (int i = 0; i < alen; ++i) {
		if (str1[i] < str2[i])return 0;
		else return 1;
	}
	return 1;
}

int main()
{
	while (1)
	{
		scanf("%s %s", astr, bstr);
		if (astr[0] == '0' && bstr[0] == '0')return 0;
		if (my_strcmp(astr, bstr))func(astr,alen, bstr,blen);
		else func(bstr,blen, astr,alen);
	}
}