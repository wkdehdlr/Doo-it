#include <iostream>
using namespace std;

int func(int st, int en, int a, int b)
{
	int n = (st + en) / 2;
	if (a <= n && b <= n) {
		return func(st, n, a, b);
	}
	else if (n < a && n < b) {
		return func(n + 1, en, a, b);
	}
	else {
		int i = 1, ans = 0;
		n = en - st + 1;
		while (i < n) { i *= 2; ans++; }
		return ans;
	}
}
int solution(int n, int a, int b)
{
	return func(1, n, a, b);
}