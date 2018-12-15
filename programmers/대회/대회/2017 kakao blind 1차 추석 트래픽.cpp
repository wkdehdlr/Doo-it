#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
vector<string> ed;
vector<pair<string, int> > st;
priority_queue<string, vector<string>, greater<string> > pq;
bool ok = false;
string func3(string lin)
{
	string str = "", res;
	if (ok) {
		str = "00:00:01.000";
		if (lin < str)return "ok";
		else {
			ok = false; str = "";
		}
	}

	int hh = 0, mm = 0;
	double ss1 = 0, ss2 = 1;
	hh = stoi(lin.substr(0, 2), 0);
	mm = stoi(lin.substr(3, 2), 0);
	ss1 = stod(lin.substr(6, 6), 0);
	if (ss1 < ss2) {
		ss1 += 60;
		ss1 -= ss2;
		mm--;
		if (mm < 0) {
			mm = 59;
			hh--;
		}
	}
	else ss1 -= ss2;
	str += (hh / 10) + '0';
	str += (hh % 10) + '0';
	str += ':';
	str += (mm / 10) + '0';
	str += (mm % 10) + '0';
	str += ':';
	res = to_string(ss1 + 0.001);

	int j = 5;
	if (ss1 < 10) {
		str += '0'; j = 4;
	}
	for (int i = 0; i <= j; ++i)str += res[i];
	return str;
}
string func2(string lin)
{
	string str = "", res;
	int hh = 0, mm = 0;
	double ss1 = 0, ss2 = 0;
	hh = stoi(lin.substr(11, 2), 0);
	mm = stoi(lin.substr(14, 2), 0);
	ss1 = stod(lin.substr(17, 6), 0);
	ss2 = stod(lin.substr(24, lin.size() - 24), 0);
	if (ss1 < ss2) {
		ss1 += 60;
		ss1 -= ss2;
		mm--;
		if (mm < 0) {
			mm = 59;
			hh--;
		}
	}
	else ss1 -= ss2;
	str += (hh / 10) + '0';
	str += (hh % 10) + '0';
	str += ':';
	str += (mm / 10) + '0';
	str += (mm % 10) + '0';
	str += ':';
	res = to_string(ss1 + 0.001);

	int j = 5;
	if (ss1 < 10) {
		str += '0'; j = 4;
	}
	for (int i = 0; i <= j; ++i)str += res[i];
	return str;
}
int func()
{
	ok = true;
	int mx = 0;
	int ans = 0;
	string frt, bck;
	for (int i = 0; i < st.size(); ++i) {
		ans++;
		frt = st[i].first;
		pq.push(ed[st[i].second]);
		bck = func3(frt);
		if (!ok) {
			while (!pq.empty() && pq.top() < bck) {
				pq.pop();
				ans--;
			}
		}
		mx = max(mx, ans);
	}
	return mx;
	//cout << mx << endl;
}
int solution(vector<string> lines) {
	for (int k = 0; k < lines.size(); ++k) {
		ed.push_back(lines[k].substr(11, 12));
		st.push_back({ func2(lines[k]) , k });
	}
	sort(st.begin(), st.end());
	return func();
}