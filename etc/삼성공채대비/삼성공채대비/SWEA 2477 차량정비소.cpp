#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
using namespace std;

struct person {
	int num1, num2;
};
struct info {
	int tot, res, num;
};
bool ok = true;
person ps[1001];
int T;
int N, M, K;
info a[10], b[10];
int t[1001];
bool visita[10], visitb[10];
int A, B;
int tm = 0;
queue<int> q, p;
int res = 0;
bool check()
{
	if (!p.empty())return false;
	if (!q.empty())return false;
	for (int i = 1; i <= N; ++i)
		if (visita[i])return false;
	for (int i = 1; i <= M; ++i)
		if (visitb[i])return false;

	return true;
}
void func4()
{
	while (!q.empty())
	{
		bool done = true;
		int num = q.front();//사람번호
		for (int i = 1; i <= M; ++i)
		{
			if (!visitb[i]) {//빈창구면 새로 배정하고 그때부터 시간감소
				q.pop();
				ps[num].num2 = i;
				if (ps[num].num1 == A && ps[num].num2 == B)
					res += num;

				visitb[i] = true;
				b[i].num = num;
				b[i].res--;
				done = false;
				break;
			}
		}
		if (done)break;//풀방
	}
}
void func3()
{
	for (int i = 1; i <= M; ++i)
	{
		if (visitb[i]) {//진행중인 창고면 시간감소
			if (!b[i].res) {//시간이 0이 되면 정비대기큐로 들어감
				visitb[i] = false;
				b[i].res = b[i].tot;
				b[i].num = 0;
			}
			else {
				b[i].res--;
			}
		}

	}
}
void func2()
{
	while (!p.empty())
	{
		bool done = true;
		int num = p.front();//사람번호
		for (int i = 1; i <= N; ++i)
		{
			if (!visita[i]) {//빈창구면 새로 배정하고 그때부터 시간감소
				p.pop();
				ps[num].num1 = i;
				visita[i] = true;
				a[i].num = num;
				a[i].res--;
				done = false;
				break;
			}
		}
		if (done)break;//풀방
	}
}
void func1()
{
	for (int i = 1; i <= N; ++i)
	{
		if (visita[i]) {//진행중인 창고면 시간감소

			if (!a[i].res) {//시간이 0이 되면 정비대기큐로 들어감
				visita[i] = false;
				a[i].res = a[i].tot;
				q.push(a[i].num);
				a[i].num = 0;
			}
			else {
				a[i].res--;
			}
		}
	}
}
void func0(int time)
{
	if (t[K] < time) {
		ok = true;
		return;
	}
	else {
		ok = false;
	}
	for (int i = 1; i <= K; ++i)
	{
		if (t[i] == time) {
			p.push(i);
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		ok = true;
		res = 0;
		tm = 0;
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &a[i].tot);
			a[i].res = a[i].tot;
		}
		for (int i = 1; i <= M; ++i) {
			scanf("%d", &b[i].tot);
			b[i].res = b[i].tot;
		}
		for (int i = 1; i <= K; ++i)
			scanf("%d", &t[i]);

		
		while (1)
		{
			func0(tm);//대기큐에 진입
			func1();//접수창구배정
			func2();//정비 대기큐에 진입
			func3();//정비창구배정
			func4();
			if (check() && ok)break;
			tm++;
		}
		printf("#%d %d\n", tc + 1, res == 0 ? -1 : res);
	}
}