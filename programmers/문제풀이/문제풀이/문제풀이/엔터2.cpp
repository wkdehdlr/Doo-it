#pragma warning(disable : 4996)
#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;

struct info {
	string name;
	int win;
	int lose;
	int point;
};
bool operator<(info f, info g) {
	if (f.win != g.win) {
		return f.win < g.win;
	}
	else {
		if (f.point != g.point) {
			return f.point < g.point;
		}
		else {
			int r = f.name.compare(g.name);
			if (r)return 0;
			else return 1;
		}
	}
}
priority_queue<info> pq;
set<string> st;
unordered_map<string, int> w;
unordered_map<string, int> l;
unordered_map<string, int> p;

string str;
int N;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	cin >> N;
	getline(cin, str);
	for (int i = 1; i <= (N * (N - 1)); ++i) {
		getline(cin, str);
		vector<string> vec = split(str, ' ');
		if (stoi(vec[1]) > stoi(vec[3])) {
			w[vec[0]]++;
			l[vec[2]]++;
		}
		else {
			w[vec[2]]++;
			l[vec[0]]++;
		}
		p[vec[0]] += (stoi(vec[1]) - stoi(vec[3]));
		p[vec[2]] += (stoi(vec[3]) - stoi(vec[1]));
		st.insert(vec[0]);
		st.insert(vec[2]);
	}

	for (auto it = st.begin(); it != st.end(); ++it) {
		string n = *it;
		info i = { n, w[n], l[n], p[n] };
		pq.push(i);
	}
	while (!pq.empty()) {
		info i = pq.top();
		pq.pop();
		cout << i.name << " " << i.win << " " << i.point << endl;
	}
	return 0;
}