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
const int INF = 1000000000;
int cnt = 1;
int dist[1000][1000];
vector<vector<string>> input;
unordered_map<string, int> st;
int N, M, len;
string str;
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
	cin >> N >> M;
	getline(cin, str);
	for (int i = 0; i < M; ++i) {
		getline(cin, str);
		vector<string> vec = split(str, ' ');
		input.push_back(vec);
		if (st[vec[0]] == 0) {
			st[vec[0]] = cnt; cnt++;
		}
		if (st[vec[1]] == 0) {
			st[vec[1]] = cnt; cnt++;
		}
	}
	for (int i = 1; i < cnt; ++i) {
		for (int j = 1; j < cnt;++j) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}

	for (int i = 0; i < M; ++i) {
		vector<string> vec = input[i];
		int v1 = st[vec[0]];
		int v2 = st[vec[1]];
		dist[v1][v2] = min(dist[v1][v2], stoi(vec[2]));
	}

	for (int k = 1; k < cnt; ++k) {
		for (int i = 1; i < cnt; ++i) {
			for (int j = 1; j < cnt; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	getline(cin, str);
	M = stoi(str);

	for (int i = 0; i < M; ++i) {
		getline(cin, str);
		vector<string> vec = split(str, ' ');
		if (st.find(vec[0]) == st.end() || st.find(vec[1]) == st.end()) {
			int v1 = st[vec[0]];
			int v2 = st[vec[1]];
			if (v1 == v2)cout << "0" << endl;
			else cout << "-1" << endl;
		}
		else {
			int v1 = st[vec[0]];
			int v2 = st[vec[1]];
			if (dist[v1][v2] == INF)cout << "-1" << endl;
			else cout << dist[v1][v2] << endl;
		}
	}

	return 0;
}