#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;


int L, P, V;
int cnt;
int num = 1;
int main()
{
	while (1)
	{
		cnt = 0;
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V)
			break;
		while (P <= V)
		{
			V -= P;
			cnt += L;
		}
		cnt += (L < V ? L : V);
		printf("Case %d: %d\n", num++, cnt);
	}
}