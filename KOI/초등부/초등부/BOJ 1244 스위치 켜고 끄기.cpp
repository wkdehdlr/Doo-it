#pragma warning(disable : 4996)
#include<cstdio>

int arr[101];
int N;
int stu;
void func(int m, int sch)
{
	if (m == 1) {//남자
		int idx = sch;
		while (idx <= N)
		{
			arr[idx] = 1 - arr[idx];
			idx += sch;
		}
	}
	else {//여자
		int idx = sch;
		int idxL = sch - 1;
		int idxR = sch + 1;
		arr[idx] = 1 - arr[idx];
		for (; idxL >= 1 && idxR <= N; --idxL, ++idxR)
		{
			if (arr[idxL] == arr[idxR]) {
				arr[idxL] = 1 - arr[idxL];
				arr[idxR] = 1 - arr[idxR];
			}
			else break;
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &stu);
	for (int i = 0; i < stu; ++i)
	{
		int m, sch;
		scanf("%d %d", &m, &sch);
		func(m, sch);
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d", arr[i]);
		if ((i / 20) != 0)printf("\n");
		else printf(" ");
	}
	printf("\n");
}