#include<cstdio>
using namespace std;

int T, L, R;
int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d", &L, &R);
		printf("%d %d\n", L, L * 2);
	}
}