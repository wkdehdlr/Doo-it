#pragma warning(disable : 4996)
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int t, d, w, k, ans, f[13][20], tf[13][20], s[13];

bool pass()
{
	for (int j = 0; j<w; j++)
	{
		bool f1 = false;
		for (int i = 0; i <= d - k; i++)
		{
			bool f2 = true;
			for (int p = i + 1; p<i + k; p++)
				if (tf[i][j] != tf[p][j])
					f2 = false;
			if (f2) { f1 = true; break; }
		}
		if (f1) continue;
		else return false;
	}
	return true;
}

void go(int n, int c) // 길이,약품투입횟수
{
	if (c > ans) return;
	if (n == d + 1)
	{
		for (int i = 0; i<d; i++) for (int j = 0; j<w; j++)
			tf[i][j] = f[i][j];
		for (int i = 0; i<d; i++) if (s[i] != -1)
			for (int j = 0; j<w; j++) tf[i][j] = s[i];
		if (pass()) ans = min(ans, c);
		return;
	}

	s[n] = -1, go(n + 1, c);
	//if (n == d) return;
	s[n] = 0, go(n + 1, c + 1);
	s[n] = 1, go(n + 1, c + 1);
}

int main()
{
	scanf("%d", &t);
	for (int T = 1; T <= t; T++)
	{
		scanf("%d %d %d", &d, &w, &k);
		for (int i = 0; i<d; i++) for (int j = 0; j<w; j++)
			scanf("%d", &f[i][j]);
		ans = 15;
		go(0, 0);
		printf("#%d %d\n", T, ans);
	}
	return 0;
}
