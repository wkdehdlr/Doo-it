#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
char a[500000][21];
char b[500000][21];

int main()
{	FILE *fp = fopen("output1.txt", "r");
	for (int i = 0; i < 500000; ++i)
	{
		fscanf(fp, "%s", a[i]);
	}
	fclose(fp);
	FILE *fp2 = fopen("output2.txt", "r");
	for (int i = 0; i < 500000; ++i)
	{
		fscanf(fp2, "%s", b[i]);
	}
	fclose(fp2);

	for (int i = 0; i < 500000; ++i)
	{
		if (strcmp(a[i], b[i]))
		{
			printf("%d//%s//%s\n", i, a[i], b[i]);
			break;
		}
	}
}