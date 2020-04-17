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
#include <list>
#include<sstream>
using namespace std;
typedef long long ll;


map<string, int> ma;

vector<string> directory = {
"/"
};
vector<string> command = {
"mkdir /a",
"mkdir /a/b",
"mkdir /a/b/c",
"cp /a/b /",
"rm /a/b/c"
};

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
	vector<string> ans;
	int len = directory.size();
	for (int i = 0; i < len; ++i)ma[directory[i]] = 1;

	len = command.size();
	for (int i = 0; i < len; ++i) {
		vector<string> sp = split(command[i], ' ');
		if (sp[0] == "mkdir") {
			ma[sp[1]] = 1;
		}
		else if (sp[0] == "cp") {
			int rlen = sp[1].size();
			for (auto it = ma.begin(); it != ma.end(); ++it) {
				if (it->first.substr(0, rlen) == sp[1]) {
					for (int k = it->first.size() - 1; k >= 0; --k) {
						if (it->first[k] == '/') {
							ma[sp[2] + it->first.substr(k + 1, it->first.size() - k)] = 1;
						}
					}
				}
			}

		}
		else {//rm
			int rlen = sp[1].size();
			vector<string> res;
			for (auto it = ma.begin(); it != ma.end(); ++it) {
				if (it->first.substr(0, rlen) == sp[1]) {
					res.push_back(it->first);
				}
			}
			rlen = res.size();
			for (int j = 0; j < rlen; ++j) {
				ma.erase(res[j]);
			}
		}
	}
	for (auto it = ma.begin(); it != ma.end(); ++it) {
		ans.push_back(it->first);
	}
	return 0;
}