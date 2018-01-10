#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

int arr[10001];
int cnt = 0;

void swap(int x, int y)
{
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
bool next_permutation(int n) {
	int i = n - 1;
	while (i > 0 && arr[i - 1] <= arr[i]) i -= 1; // arr�߿� arr[i-1]�� arr[i]���� �۾����ų� ���� index�� ã�� (i)
	if (i <= 0) return false; // ������ ����
	int j = n - 1;
	while (arr[j] >= arr[i - 1]) j -= 1; // arr[i-1]���� ū index�� ã�� (j)
	swap(i - 1, j);
	j = n - 1;
	while (i < j) {
		swap(i, j);
		i += 1; j -= 1;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	if (next_permutation(n))
		for (int i = 0; i < n; ++i)
			printf("%d ", arr[i]);
	else
		printf("-1\n");
}