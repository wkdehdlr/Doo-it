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
	if ((from + 1) % 3 == to) {//��ĭ�� ������ ���
		if (now == from) {
			return func(from, (from + 2) % 3);
		}
		else if (now == (from + 1) % 3) {
			return func((from + 2) % 3, (from + 1) % 3);
		}
		else return;
	}
	else if ((from + 2) % 3 == to) {//��ĭ ������ ���
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
//1. 1~5�� A���� B�� �ű���� 1~4�� A���� C�� �Űܾ��Ѵ�.
//2. 1~4�� A���� C�� �ű���� A���� B�� �ű�� B���� C�� �Űܾ��Ѵ�.
//3. 1~4�� A���� B�� �ű���� 1~3�� A���� C�� �Űܾ��Ѵ�.
