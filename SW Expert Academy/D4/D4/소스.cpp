#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;

struct now {
	int x;
	int y;
	int total;
};

bool operator<(now t, now u) {
	return t.total > u.total;
}

int main()
{
	priority_queue<now > pq;
	pq.push({ 1,1,5 });
	pq.push({ 1,1,4 });
	pq.push({ 1,1,3 });
	pq.push({ 1,1,2 });
	pq.push({ 1,1,1 });
}
