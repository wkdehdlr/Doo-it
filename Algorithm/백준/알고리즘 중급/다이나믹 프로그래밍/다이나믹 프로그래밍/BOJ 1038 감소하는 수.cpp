#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int arr[10] = { 0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
vector<long long> ch;
int N;
void func(int n, int i, long long k)
{
	if (n == 10)return;
	ch.push_back(k);
	for (int t = 9; t > i; --t) {
		func(n + 1, t, arr[n] * t + k);
	}
}
int main()
{
	//func(몇자리 수인지, 맨앞숫자, 현재숫자)
	for (int i = 0; i < 10; ++i)
		func(1, i, i);
	sort(ch.begin(), ch.end());
	ch.push_back(9876543210);
	scanf("%d", &N);
	if (N <= 1022)printf("%lld\n", ch[N]);
	else printf("-1\n");
	return 0;
}