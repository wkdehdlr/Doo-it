#include <iostream>
#include<algorithm>
using namespace std;
struct info {
	int start, end;
};
bool operator<(info f, info g)
{
	if (f.end == g.end)
		return f.start < g.start;
	else
		return f.end < g.end;
}
int N;
info arr[100001];

int main() {

	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}
	sort(arr, arr + N);
	int cnt = 1;
	int start = arr[0].end;
	for (int i = 1; i<N; ++i)
	{
		if (arr[i].start >= start)
		{
			cnt++;
			start = arr[i].end;
		}
	}
	printf("%d\n", cnt);
	return 0;
}