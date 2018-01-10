#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		vec.push_back(i);

	do {
		for (int i = 0; i < N; ++i)
			printf("%d ", vec[i]);
		printf("\n");
	} while (next_permutation(vec.begin(), vec.end()));
}