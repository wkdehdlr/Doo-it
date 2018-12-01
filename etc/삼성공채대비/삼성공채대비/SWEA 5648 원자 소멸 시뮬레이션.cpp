#pragma warning(disable : 4996)
#define MAX_N 1005
#include<cstdio>
using namespace std;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
struct node {
	int x, y, dir, power;
};
int arr[4001][4001];
int T, N, ret;
int front, front2;
int rear, rear2;
node queue[MAX_N];
node queue2[MAX_N];

void queueInit(void)
{
	front = 0;
	rear = 0;
}
void queueInit2(void)
{
	front2 = 0;
	rear2 = 0;
}
int qisempty()
{
	return front == rear;
}
int qisempty2()
{
	return front2 == rear2;
}
void qpush(node n)
{
	queue[rear].x = n.x;
	queue[rear].y = n.y;
	queue[rear].dir = n.dir;
	queue[rear].power = n.power;
	rear++;
}
void qpush2(node n)
{
	queue2[rear2].x = n.x;
	queue2[rear2].y = n.y;
	queue2[rear2].dir = n.dir;
	queue2[rear2].power = n.power;
	rear2++;
}
void qpop(node *n)
{
	n->x = queue[front].x;
	n->y = queue[front].y;
	n->dir = queue[front].dir;
	n->power = queue[front].power;
	front++;
}
void qpop2(node *n)
{
	n->x = queue2[front2].x;
	n->y = queue2[front2].y;
	n->dir = queue2[front2].dir;
	n->power = queue2[front2].power;
	front2++;
}
void func()
{
	for (int i = 0; i < 4002; ++i) {
		while (!qisempty())
		{
			node n;
			qpop(&n);
			int x = n.x + dr[n.dir];
			int y = n.y + dc[n.dir];
			if (x >= 0 && x <= 4000 && y >= 0 && y <= 4000) {
				if (!arr[x][y]) {
					qpush2({ x,y,n.dir, n.power });
				}
				arr[x][y] += n.power;
			}
		}
		queueInit();
		while (!qisempty2())
		{
			node n;
			qpop2(&n);
			int x = n.x;
			int y = n.y;
			if (arr[x][y] == n.power) {
				qpush(n);
			}
			else {
				ret += arr[x][y];
			}
			arr[x][y] = 0;
		}
		queueInit2();
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int x, y, dir, power;
			scanf("%d %d %d %d", &x, &y, &dir, &power);
			qpush({ 2 * y + 2000,2 * x + 2000,dir,power });
		}
		ret = 0;
		func();
		printf("#%d %d\n", tc + 1, ret);
	}
}