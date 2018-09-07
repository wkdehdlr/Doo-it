#pragma warning(disable : 4996)
#include<cstdio>

int adigt[210];
int bdigt[210];
int cdigt[210];
char astr[210];
char bstr[210];
int alen, blen;
int minus(int *adigt, int idx, int *bdigt, int len2)
{
	for (int i = idx; i < idx + len2; ++i) {
		if (adigt[i] < bdigt[i - idx])return 0;
		else if (adigt[i] > bdigt[i - idx]) break;
	}

	for (int i = idx + len2 - 1; i >= idx; --i) {
		adigt[i] -= bdigt[i - idx];
		if (adigt[i] < 0) {
			adigt[i] += 10;
			adigt[i - 1]--;
		}
	}
	return 1;
}
void encode(char *str, int len, int *digt)
{
	for (int i = 0; i < len; ++i)
		digt[i] = str[i] - '0';
}
void divide(char *str1, int len1, char *str2, int len2)// 500/20
{
	encode(str1, len1, adigt);
	encode(str2, len2, bdigt);
	for (int i = 0; i <= len1 - len2; ++i) {
		while (minus(adigt, i, bdigt, len2))cdigt[i]++;
		adigt[i + 1] += adigt[i] * 10;
	}

	if (cdigt[0]) {
		printf("%d", cdigt[0]);
		cdigt[0] = 0;
	}
	for (int i = 1; i <= len1 - len2; ++i) {
		printf("%d", cdigt[i]);
		cdigt[i] = 0;
	}
	printf("\n");
}
int my_strcmp(char *str1, char *str2)
{
	for (int i = 0; i < alen; ++i) {
		if (str1[i] > str2[i])return 1;
		else if (str1[i] < str2[i])return -1;
	}
	return 0;
}
int my_strlen(char *str)
{
	int idx = 0;
	while (str[idx] != '\0')idx++;
	return idx;
}
int main()
{
	while (1)
	{
		scanf("%s %s", astr, bstr);
		if (astr[0] == '0' || bstr[0] == '0')return 0;
		alen = my_strlen(astr);
		blen = my_strlen(bstr);
		if (alen > blen)divide(astr, alen, bstr, blen);
		else if (alen < blen)divide(bstr, blen, astr, alen);
		else {
			int res = my_strcmp(astr, bstr);
			if (res >= 0)divide(astr, alen, bstr, blen);
			else divide(bstr, blen, astr, alen);
		}
	}
}