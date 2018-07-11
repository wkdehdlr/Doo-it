#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, K;
int arr[200001];

bool comp(int a, int b) {
	return a > b;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; ++i)scanf("%d", &arr[i]);
		sort(arr + 1, arr + N + 1, comp);
		vector<vector<int> > vec;
		vec.push_back(vector<int>());
		vec.push_back(vector<int>());
		vec[1].push_back(arr[1]);
		int i = 2 , idx = 1;
		for (; i <= N; ++i) {
			if (arr[1] - arr[i] <= K) {
				vec.push_back(vector<int>());
				vec[i].push_back(arr[i]);
			}
			else break;
		}
		for (; i <= N; ++i) {
			bool ok = false;

			/*for (; idx < vec.size(); ++idx) {
				if (vec[idx].back() - arr[i] > K) {
					vec[idx].push_back(arr[i]);
					idx++;
					if (idx == vec.size())
						idx = 1;
					ok = true;
					break;
				}
			}*/
			if (ok)continue;
			vec.push_back(vector<int>());
			vec.back().push_back(arr[i]);
			idx = 1;
		}
		printf("Case #%d\n%d\n", tc + 1, vec.size() - 1);
	}
}