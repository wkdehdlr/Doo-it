#pragma warning(disable : 4996)
#include<cstdio>
#include<unordered_map>
using namespace std;

unordered_map<int, int> ma;
int inorder[100001];
int postorder[100001];
void solve(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe)return;
	printf("%d ", postorder[pe]);

	int p = ma[postorder[pe]];
	int left = p - is;
	solve(is, p - 1, ps, ps + left - 1);
	solve(p + 1, ie, ps+left, pe - 1);
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int temp;
		scanf("%d", &temp);
		ma[temp] = i;
	}
	for (int i = 0; i < N; ++i)
		scanf("%d", &postorder[i]);

	solve(0, N - 1, 0, N - 1);
}