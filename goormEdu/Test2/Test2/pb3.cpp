#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;

struct info {
	int total;
	int num;
};

priority_queue<info> pq;
bool operator<(info p, info q) {
	if (p.total == q.total)
	{
		return p.num > q.num;
	}
	else
	{
		return p.total < q.total;
	}
}
int team[102];
int M, N;
int P, Q;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &P, &Q);
		if (P == Q)
			continue;
		if (!((P >= 1 && P <= N) && (Q >= 1 && Q <= N)))
			continue;
		team[P] += 5;
		team[Q] += 3;
	}

	for (int i = 1; i <= N; ++i)
	{
		pq.push({ team[i],i });
	}

	int rank = 1;
	int cnt = 1;
	int now = pq.top().total;
	printf("%d %d %d\n", rank, pq.top().num, pq.top().total);
	pq.pop();
	cnt++;
	while (!pq.empty())
	{
		if (now == pq.top().total)
			;
		else
			rank = cnt;

		now = pq.top().total;
		printf("%d %d %d\n", rank,pq.top().num, pq.top().total);
		pq.pop();
		cnt++;
	}
}