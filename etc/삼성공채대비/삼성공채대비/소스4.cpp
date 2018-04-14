#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int arr[3] = { 1,1,2 };
int main()
{
	do {
		for (int i = 0; i < 3; ++i)
			printf("%d ", arr[i]);
		printf("\n");
	} while (next_permutation(arr, arr + 3));
}