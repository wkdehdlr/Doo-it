#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int arr[50];
int arr2[50];
int N, M;
int mo[100][50];
map<long long, int> ma;
int res = 0;
vector<int> vec;
int main()
{
	long long tmp = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
		switch (arr[i])
		{
		case 1:arr2[N - i - 1] = 3; break;
		case 2:arr2[N - i - 1] = 4; break;
		case 3:arr2[N - i - 1] = 1; break;
		case 4:arr2[N - i - 1] = 2; break;
		}
		tmp *= 10;
		tmp += arr[i];
	}
	ma[tmp] = 1;

	for (int i = 1; i < N; ++i)
	{
		long long tmp2 = 0;
		rotate(arr, arr + 1, arr + N);
		for (int j = 0; j < N; ++j) {
			tmp2 *= 10;
			tmp2 += arr[j];
		}
		ma[tmp2] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		long long tmp2 = 0;
		rotate(arr2, arr2 + 1, arr2 + N);
		for (int j = 0; j < N; ++j) {
			tmp2 *= 10;
			tmp2 += arr2[j];
		}
		ma[tmp2] = 1;
	}

	tmp = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		tmp = 0;
		for (int j = 0; j < N; ++j) {
			scanf("%d", &mo[i][j]);
			tmp *= 10;
			tmp += mo[i][j];
		}
		if (ma[tmp]) {
			res++;
			vec.push_back(i);
		}
	}

	printf("%d\n", res);
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", mo[vec[i]][j]);
		}
		printf("\n");
	}
}