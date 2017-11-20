#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;


struct Edge {
	long long length;
	int num1;
	int num2;
};

bool operator<(Edge t, Edge u) {
	return t.length > u.length;
}

priority_queue<Edge> pq;
double sum;
long long arr[1001][2];
int edge_arr2[1001];
int T, N;
double E;

void set_Edge();
void make_Edge(long long, long long, long long, long long, int, int);
void kruskal();
int main()
{
	priority_queue<Edge> pq_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(edge_arr2, 0, sizeof(edge_arr2));
		pq = pq_temp;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%lld", &arr[i][0]);
		}
		for (int i = 1; i <= N; ++i)
		{
			scanf("%lld", &arr[i][1]);
			edge_arr2[i] = i;
		}

		scanf("%lf", &E);
		set_Edge();
		kruskal();
		printf("#%d %.0lf\n", tc + 1, sum);
	}
}
void set_Edge()
{
	for (int i = 1; i < N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			make_Edge(arr[i][0], arr[i][1], arr[j][0], arr[j][1], i, j);
		}
	}
}
void make_Edge(long long x1, long long y1, long long x2, long long y2,int i, int j)
{
	pq.push({ (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) ,i,j });
}
void kruskal()
{
	int cnt = 0;
	sum = 0;
	while (!pq.empty())
	{
		int num1 = pq.top().num1;
		int num2 = pq.top().num2;
		long long length = pq.top().length;
		pq.pop();

		if (edge_arr2[num1] != edge_arr2[num2])
		{
			cnt++;
			if (edge_arr2[num1] > edge_arr2[num2])
			{
				int comp = edge_arr2[num1];
				for (int i = 1; i <= N; ++i)
				{
					if (edge_arr2[i] == comp)
						edge_arr2[i] = edge_arr2[num2];
				}
			}
			else
			{
				int comp = edge_arr2[num2];
				for (int i = 1; i <= N; ++i)
				{
					if (edge_arr2[i] == comp)
						edge_arr2[i] = edge_arr2[num1];
				}
			}
			sum += length;
		}

		if (cnt == N - 1)
		{
			break;
		}
	}
	sum *= E;
}