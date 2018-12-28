#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[200005][2];
int visited[200005];
vector<int> vec;
void go(int idx, int _idx)
{
	if (arr[idx][1] == arr[_idx][0] || arr[idx][1] == arr[_idx][1])return;
	else swap(arr[idx][0], arr[idx][1]);
}
void func(int i)
{
	if (arr[i][0] == 1)return;
	vec.push_back(arr[i][0]);
	vec.push_back(arr[i][1]);
	func(arr[i][1]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 1; i <= n; ++i) {
		go(i, arr[i][0]);
	}
	int idx = 1;
	vec.push_back(idx);
	visited[idx] = true;
	while (1) {
		if (visited[arr[idx][0]])break;	vec.push_back(arr[idx][0]); visited[arr[idx][0]] = true;
		if (visited[arr[idx][1]])break;	vec.push_back(arr[idx][1]); visited[arr[idx][1]] = true;
		idx = arr[idx][1];
	}
	for (int i = 0; i < vec.size(); ++i) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}