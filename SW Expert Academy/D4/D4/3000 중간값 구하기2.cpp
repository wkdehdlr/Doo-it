#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;

priority_queue<int> pq_max;
priority_queue<int,vector<int>,greater<int> > pq_min;
priority_queue<int> pq_max_temp;
priority_queue<int, vector<int>, greater<int> > pq_min_temp;

int T, N, num1, num2, mid, cnt;
long long total = 0;

void init_mid();
void func_mid();
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		init_mid();
		for (int i = 1; i < N; ++i)
		{
			func_mid();
			cnt++;
		}
		printf("#%d %lld\n", tc + 1, total);
	}	
}
void init_mid()
{
	pq_min = pq_min_temp;
	pq_max = pq_max_temp;
	total = 0;


	scanf("%d %d", &N, &num1);
	pq_min.push(num1);
	scanf("%d %d", &num1, &num2);
	
	if (num1 < pq_min.top())
		pq_max.push(num1);
	else
		pq_min.push(num1);

	if (num2 < pq_min.top())
		pq_max.push(num2);
	else
		pq_min.push(num2);

	while (pq_max.size() < 2)
	{
		pq_max.push(pq_min.top());
		pq_min.pop();
	}
	cnt = 2;
	mid = pq_max.top();
	total += mid;
}
void func_mid()
{
	scanf("%d %d", &num1, &num2);
	if (mid < num1)
		pq_min.push(num1);
	else
		pq_max.push(num1);

	if (mid < num2)
		pq_min.push(num2);
	else
		pq_max.push(num2);


	if (pq_min.size() > cnt)
	{
		while (pq_min.size() != cnt)
		{
			pq_max.push(pq_min.top());
			pq_min.pop();
		}
	}

	if (pq_min.size() < cnt)
	{
		while (pq_min.size() != cnt)
		{
			pq_min.push(pq_max.top());
			pq_max.pop();
		}
	}
	mid = pq_max.top();
	total += (mid % 20171109);
	total %= 20171109;
}