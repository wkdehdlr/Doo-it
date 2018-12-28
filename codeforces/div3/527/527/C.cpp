#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
string str[200];//입력
vector<string> cdd;//1짜리 2개, N-1짜리 2개
unordered_set<string> st1, st2, st3;
unordered_set<string> prex, sufx;
unordered_multimap<string, int> ans;
unordered_multimap<string, int>::iterator itor;
int comp(string f, string g)
{
	return f.size() < g.size(); 
}
void func(string strg)
{
	for (int i = 1; i < N; ++i) {
		auto it = ans.equal_range(strg.substr(0, i));
		for (itor = it.first; itor != it.second; ++itor) {
			if (itor->second == 0) {
				itor->second = 1;
				break;
			}
		}
		it = ans.equal_range(strg.substr(i, N - i));
		for (itor = it.first; itor != it.second; ++itor) {
			if (itor->second == 0) {
				itor->second = 2;
				break;
			}
		}
	}
	for (int i = 0; i < 2 * N - 2; ++i) {
		auto it = ans.find(str[i]);
		if (it->second == 1)cout << 'P';
		else cout << 'S';
		ans.erase(it);
	}
	cout << endl;
}
bool go(string strg) {
	st3.clear();
	for (int i = 1; i < N; ++i) {
		st3.insert(strg.substr(0, i));
		st3.insert(strg.substr(i, N - i));
	}
	for (int i = 0; i < 2 * N - 2; ++i) {
		if (st3.find(str[i]) == st3.end())return false;
	}
	return true;
}
void comb()
{
	string cd;
	if (N == 2) {
		cd = cdd[0] + cdd[1];
		if (st1.find(cd) == st1.end()) {
			st1.insert(cd);
			if (go(cd)) {
				func(cd);
				return;
			}
		}
		cd = cdd[1] + cdd[0];
		if (st1.find(cd) == st1.end()) {
			st1.insert(cd);
			if (go(cd)) {
				func(cd);
				return;
			}
		}
	}
	else {
		for (int i = 0; i < 2; ++i) {
			for (int j = 2; j < 4; ++j) {
				cd = cdd[i] + cdd[j];
				if (st1.find(cd) == st1.end()) {
					st1.insert(cd);
					if (go(cd)) {
						func(cd);
						return;
					}
				}
				cd = cdd[j] + cdd[i];
				if (st1.find(cd) == st1.end()) {
					st1.insert(cd);
					if (go(cd)) {
						func(cd);
						return;
					}
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < 2 * N - 2; ++i) { 
		cin >> str[i];
		st2.insert(str[i]);
		ans.insert({ str[i], 0 });
		if (str[i].size() == 1 || str[i].size() == N - 1) {
			cdd.push_back(str[i]);
		}
	}
	sort(cdd.begin(), cdd.end(), comp);
	comb();
}