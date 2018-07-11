#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;

deque<int> deq;
int N, K;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		deq.push_back(tmp);
	}
	int ret = 0;
	while (!deq.empty())
	{
		bool ok = true;
		if (deq.front() <= K) {
			deq.pop_front();
			ret++;
			ok = false;
		}

		if (!deq.empty() && deq.back() <= K) {
			deq.pop_back();
			ret++;
			ok = false;
		}
		if (ok)break;
	}
	printf("%d\n", ret);
}