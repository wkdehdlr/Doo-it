#include<cstdio>
#include<algorithm>
using namespace std;

int arr1[5] = { 1,2,3,4,5 };
int arr2[5] = { 1,2,3,4,5 };

int main()
{
	rotate(arr1, arr1 + 1, arr1 + 5);
	rotate(arr2, arr2 + 4, arr2 + 5);
	for (int i = 0; i < 5; ++i)
		printf("%d", arr1[i]);

	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("%d", arr2[i]);
}
