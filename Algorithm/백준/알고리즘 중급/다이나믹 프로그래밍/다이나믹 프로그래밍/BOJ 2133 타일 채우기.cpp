#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

int dp[31];
int N;
int func(int n)
{
	if (n == N)return 1;
	if (n > N)return 0;
	int& ret = dp[n];
	if (ret != -1)return ret;

	ret = func(n + 2) * 3;
	for (int i = 4; i <= N; i += 2) {
		ret += (func(n + i) * 2);
	}
	return ret;	
}
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d\n", func(0));
}
/*
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30

0 1
1 0
2 3
3 0
4 11
5 0
6 41
7 0
8 153
9 0
10 571
11 0
12 2131
13 0
14 7953
15 0
16 29681
17 0
18 110771
19 0
20 413403
21 0
22 1542841
23 0
24 5757961
25 0
26 21489003
27 0
28 80198051
29 0
30 299303201
*/