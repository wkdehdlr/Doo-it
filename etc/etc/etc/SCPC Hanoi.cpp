#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

char str[1000010];
int T, N;
void func(int from, int to)
{
	if (N < 0)return;
	int now = str[N - 1] - 'A';
	N--;
	if ((from + 1) % 3 == to) {//한칸만 움직일 경우
		if (now == from) {
			return func(from, (from + 2) % 3);
		}
		else if (now == (from + 1) % 3) {
			return func((from + 2) % 3, (from + 1) % 3);
		}
		else return;
	}
	else if ((from + 2) % 3 == to) {//두칸 움직일 경우
		if (now == from) {
			return func(from, (from + 2) % 3);
		}
		else if (now == (from + 1) % 3) {
			return func((from + 2) % 3, from);
		}
		else {
			return func(from, (from + 2) % 3);
		}
	}
	else return;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d", &N);
		scanf("%s", str);
		func(0, 1);
		printf("Case #%d\n", tc + 1);
		if (0 <= N) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}
//A B C
//1. 1~5를 A에서 B로 옮기려면 1~4를 A에서 C로 옮겨야한다.
//2. 1~4를 A에서 C로 옮기려면 A에서 B로 옮기고 B에서 C로 옮겨야한다.
//3. 1~4를 A에서 B로 옮기려면 1~3을 A에서 C로 옮겨야한다.
