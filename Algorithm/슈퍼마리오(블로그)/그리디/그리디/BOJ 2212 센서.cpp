#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<int> pq;
int arr[10001];
int N, K;
int main()
{
	scanf("%d %d", &N, &K); 
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);

	for (int i = 0; i < N - 1; ++i)
		pq.push(arr[i + 1] - arr[i]);

	int start = arr[N - 1] - arr[0]; 
	K--;
	while (K--) { 
		if (!pq.empty())
		{
			start -= pq.top();
			pq.pop();
		}
	}
	printf("%d\n", start);
} 