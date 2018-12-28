#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> pq;
int N, K;
int two[35];
int sum = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < 31; ++i) {
		if ((1 << i)&N) {
			two[i] = 1;
			sum++;
			pq.push(1 << i);
		}
	}
	//9 4
	if (sum <= K && K <= N) {
		while (sum != K) {
			int num = pq.top();
			pq.pop();
			if (num == 1)pq.push(1);
			else {
				pq.push(num / 2);
				pq.push(num / 2);
				sum++;
			}
		}
		printf("YES\n");
		while (!pq.empty()) {
			printf("%d ", pq.top());
			pq.pop();
		}
	}
	else printf("NO\n");
}