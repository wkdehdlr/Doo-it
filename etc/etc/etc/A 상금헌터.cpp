#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
using namespace std;
int arr[7] = { 0,5000000,3000000,2000000,500000,300000,100000 };
int arr2[6] = { 0,5120000,2560000,1280000,640000,320000};
vector<int> vec1, vec2;
int main()
{
	vec1.push_back(0);
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= i; ++j)
			vec1.push_back(arr[i]);
	}

	vec2.push_back(0);
	for (int i = 1; i <= 5; ++i) {
		int l = pow(2, i - 1);
		for (int j = 1; j <= l; ++j)
			vec2.push_back(arr2[i]);
	}
	int T, a, b;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int cnt = 0;
		scanf("%d %d", &a, &b);
		if (a >= 1 && a <= 21)cnt += vec1[a];
		if (b >= 1 && b <= 31)cnt += vec2[b];
		printf("%d\n", cnt);
	}
}