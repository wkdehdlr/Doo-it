#include<cstdio>
#include<vector>
using namespace std;
int arr[300001];
vector<int> vec[30001];
int T, N, M;
void DFS(int value, int v)
{
	arr[v] = value;
	for (auto to : vec[v]) {
		if (arr[to] == value)return;//중복체크
		if (!arr[to]) {
			if (value == 1)DFS(2, to);
			else if (value == 2) {
				DFS(1, to);
				DFS(3, to);
			}
			else if (value == 3) {
				DFS(2, to);
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		for (int i = 0; i < N; ++i)vec[i].clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; ++i) {
			int v1, v2;
			vec[v1].push_back(v2);
			vec[v2].push_back(v1);
		}
		for (int i = 1; i <= 3; ++i) {
			arr[1] = i;
			DFS(i, 1);
		}
	}
}