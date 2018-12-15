#include <string>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int hh, mm;
};
bool operator<(node f, node g) {
	if (f.hh == g.hh)return f.mm > g.mm;
	return f.hh > g.hh;
}
priority_queue<node> pq;
int n1, t1, m1, hhh, mmm, origin_m, len;
string answer = "";
void decode(string str)
{
	int hh = 0, mm = 0;
	for (int i = 0; i < 2; ++i) {
		hh *= 10;
		hh += (str[i] - '0');
	}
	for (int i = 3; i < 5; ++i) {
		mm *= 10;
		mm += (str[i] - '0');
	}
	pq.push({ hh,mm });
}
bool check(node nd)
{
	while (!((nd.hh < hhh) || (nd.hh == hhh && nd.mm <= mmm))) {
		if (n1 == 1)return false;
		//cout<<1<<endl;
		n1--;
		mmm += t1;
		m1 = origin_m;
		if (mmm >= 60) {
			hhh++;
			mmm -= 60;
		}
	}
	m1--;
	if (!m1) {
		if (n1 == 1)return false;
		//cout<<2<<endl;
		n1--;
		mmm += t1;
		m1 = origin_m;
		if (mmm >= 60) {
			hhh++;
			mmm -= 60;
		}
	}
	return true;
}
void func()
{
	node nd;
	while (!pq.empty()) {
		nd = pq.top();
		//cout<< nd.hh << ':'<< nd.mm<<endl;
		pq.pop();
		if (!check(nd)) {
			break;
		}
	}
	if (!m1) {//크루기준
		mmm = nd.mm;
		hhh = nd.hh;
		if (!mmm) {
			hhh--;
			mmm = 59;
		}
		else mmm--;
	}
	answer += ((hhh / 10) + '0');
	answer += ((hhh % 10) + '0');
	answer += ':';
	answer += ((mmm / 10) + '0');
	answer += ((mmm % 10) + '0');
}
string solution(int n, int t, int m, vector<string> timetable) {
	n1 = n; t1 = t; m1 = m; hhh = 9; mmm = 0; origin_m = m1;
	len = timetable.size();
	for (int i = 0; i < len; ++i) {
		decode(timetable[i]);
	}
	func();
	return answer;
}