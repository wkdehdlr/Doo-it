#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>

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
vector<vector<string>> snapshots;
vector<vector<string>> transactions;

map<string, string> ma;
unordered_map<string, int> um;
int slen, tlen;

int my_stoi(string str) {
	int len = str.size();
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		ret *= 10;
		ret += (str[i] - '0');
	}
	return ret;
}
int main() {
	vector<vector<string>> ans;
	slen = snapshots.size();
	tlen = transactions.size();

	for (int i = 0; i < slen; ++i) {
		ma[snapshots[i][0]] = snapshots[i][1];
	}

	for (int i = 0; i < tlen; ++i) {
		if (um.find(transactions[i][0]) == um.end()) {
			um[transactions[i][0]] = 1;

			if (ma.find(transactions[i][2]) == ma.end()) {
				ma[transactions[i][2]] = "0";
			}

			if (transactions[i][1] == "SAVE") {
				ma[transactions[i][2]] = to_string(my_stoi(ma[transactions[i][2]]) + my_stoi(transactions[i][3]));
			}
			else {//WITHDRAW
				ma[transactions[i][2]] = to_string(my_stoi(ma[transactions[i][2]]) - my_stoi(transactions[i][3]));
			}
		}
	}
	for (auto it = ma.begin(); it != ma.end(); ++it) {
		vector<string> vec;
		vec.push_back(it->first);
		vec.push_back(it->second);
		ans.push_back(vec);
	}
	return ans;
}