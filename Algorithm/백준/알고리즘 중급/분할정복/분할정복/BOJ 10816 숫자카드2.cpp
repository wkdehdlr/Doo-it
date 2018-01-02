#pragma warning(disable : 4996)
#include<cstdio>
#include<cmath>
using namespace std;

int arr_plus[10000001];
int arr_minus[10000001];
int N, M;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if (temp >= 0)
			arr_plus[temp]++;
		else
			arr_minus[abs(temp)]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if (temp >= 0)
			arr_plus[temp] == 0 ? printf("0 ") : printf("%d ", arr_plus[temp]);
		else
			arr_minus[abs(temp)] == 0 ? printf("0 ") : printf("%d ", arr_minus[abs(temp)]);
	}
}