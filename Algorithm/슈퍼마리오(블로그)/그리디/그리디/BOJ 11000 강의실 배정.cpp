#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
struct info {
	int start, end;
};
bool operator<(info f, info g) {
	if (f.start == g.start)
		return f.end < g.end;
	else
		return f.start < g.start;
}
priority_queue<int,vector<int>,greater<int> > pq;
int N;
info arr[200000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}
	sort(arr, arr + N);
	pq.push(arr[0].end);
	for (int i = 1; i < N; ++i)
	{
		if (pq.top() > arr[i].start)
			pq.push(arr[i].end);
		else
		{
			pq.pop();
			pq.push(arr[i].end);
		}
	}
	printf("%d\n", pq.size());
}