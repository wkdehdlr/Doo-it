#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> vec;
int T, num1, num2, N,temp;

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		long long sum = 0;
		scanf("%d %d", &N, &temp);
		vec.push_back(temp);

		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &num1, &num2);
			vec.push_back(num1);
			vec.push_back(num2);
			sort(vec.begin(), vec.end());
			int size = vec.size();
			sum += (vec[size / 2] % 20171109);
			sum %= 20171109;
		}
		printf("#%d %lld\n", tc + 1, sum);
	}
}