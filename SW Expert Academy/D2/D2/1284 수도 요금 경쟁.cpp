#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

inline int min(int x, int y) { return x > y ? y : x; }
int main()
{
	int t;
	int P, Q, R, S, W;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		scanf("%d %d %d %d %d", &P, &Q, &R, &S, &W);
		P *= W;
		if (W <= R)
			Q;
		else
			Q += ((W - R)*S);
		printf("#%d %d\n", tc + 1, min(P, Q));
	}
}