#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

//typedef long long loo;
long long ori = 0, tmp_end = 0, tmp_st = 0;
int arr[50];
int arr2[50];
int mo[100][50];
int N, M;
vector<int> vec;
map<long long, int> ma;
int res = 0;
int main()
{
	 ori = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
		ori <<= 3;
		ori |= arr[i];
	}
	ma[ori] = 1;
	tmp_end = 0, tmp_st = 0;;
	for (int i = 1; i < N; ++i) {
		tmp_end = 0;
		tmp_end = tmp_st = ((ori >> (N - 1) * 3) & 1) | (((ori >> (N - 1) * 3 + 1) & 1) << 1) | (((ori >> (N - 1) * 3 + 2) & 1) << 2);
		tmp_end <<= ((N - 1) * 3);
		ori ^= tmp_end;
		ori <<= 3;
		ori |= tmp_st;
		ma[ori] = 1;
	}

	ori = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		switch (arr[N - i - 1])
		{
		case 1:num = 3; break;
		case 2:num = 4; break;
		case 3:num = 1; break;
		case 4:num = 2; break;
		}
		arr2[i] = num;
		ori <<= 3;
		ori |= arr2[i];
	}
	ma[ori] = 1;
	for (int i = 1; i < N; ++i) {
		tmp_end = 0;
		tmp_end = tmp_st = ((ori >> (N - 1) * 3) & 1) | (((ori >> (N - 1) * 3 + 1) & 1) << 1) | (((ori >> (N - 1) * 3 + 2) & 1) << 2);
		tmp_end <<= ((N - 1) * 3);
		ori ^= tmp_end;
		ori <<= 3;
		ori |= tmp_st;
		ma[ori] = 1;
	}


	long long tmp = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		tmp = 0;
		for (int j = 0; j < N; ++j) {
			scanf("%d", &mo[i][j]);
			tmp <<= 3;
			tmp |= mo[i][j];
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