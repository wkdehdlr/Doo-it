#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp2[5001][5001];
int arr[5001];
int N;
bool func(int a, int b)
{
	if (a == b)return true;
	if (a + 1 == b) {
		if (arr[a] == arr[b])return true;
		else return false;
	}
	if (arr[a] == arr[b])
		return func(a + 1, b - 1);
	else return false;
}
int func2(int a, int b)
{
	//�������
	if (a == b)return 0;
	if (a + 1 == b) {
		if (arr[a] == arr[b])return 0;
		else return 1;
	}
	int& ret = dp2[a][b];
	if (ret != -1)return ret;

	if (func(a, b))//�Ӹ�����̸�
		return ret = 0;

	if (arr[a] == arr[b])//�Ӹ������ �ƴѵ� i==j �϶�
		return ret = func2(a + 1, b - 1);

	return ret = min(func2(a + 1, b), func2(a, b - 1)) + 1;
}
int main()
{
	memset(dp2, -1, sizeof(dp2));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
	printf("%d\n", func2(1, N));
}