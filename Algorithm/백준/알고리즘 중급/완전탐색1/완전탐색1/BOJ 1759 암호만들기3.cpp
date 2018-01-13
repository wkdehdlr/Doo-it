#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int L, C;
char new_arr[16],arr[15], tmp;

void func(int n, int idx)
{
	if (idx == L)
	{
		int moumm = 0;
		int zaumm = 0;
		for (int i = 0; i < L; ++i)
		{
			if (new_arr[i] == 'a' || new_arr[i] == 'e' || new_arr[i] == 'i' || new_arr[i] == 'u' || new_arr[i] == 'o')
				moumm++;
			else
				zaumm++;
		}
		if (moumm >= 1 && zaumm >= 2)
			new_arr[L] = '\0',printf("%s\n", new_arr);
	}
	else if (n == C)
		return;
	else
		for (int i = 1; i >= 0; --i)
			i ? new_arr[idx] = arr[n], func(n + 1, idx + 1) : func(n + 1, idx);
}

int main()
{
	scanf("%d %d%c", &L, &C, &tmp);
	for (int i = 0; i < C; ++i)
		scanf("%c%c", &arr[i], &tmp);
	sort(arr, arr + C);
	func(0, 0);
	return 0;
}