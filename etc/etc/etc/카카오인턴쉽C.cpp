#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<unordered_set>
#include<functional>
using namespace std;

vector<string> vec;
string s = "{{123}}";
unordered_set<int> st;
vector<int> ans;

bool compare(string s, string b) {
	if (s.size() != b.size()) {
		return s.size() < b.size();
	}
	else {
		return s.size() > b.size();
	}
}
int main() {
	
	s = s.substr(1, s.size() - 2);
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] == '{') {
			int j = 0;
			for (j = i + 1; s[j] != '}'; ++j);
			vec.push_back(s.substr(i + 1, j - i - 1));
			i = j;
		}
	}
	sort(vec.begin(), vec.end(), compare);
	len = vec.size();
	for (int i = 0; i < len; ++i) {
		int slen = vec[i].size();
		for (int j = 0; j < slen; ++j) {
			int k = 0;
			for (k = j + 1; k < slen && vec[i][k] != ','; ++k);
			int res = stoi(vec[i].substr(j, k));
			if (st.find(res) == st.end()) {
				st.insert(res);
				ans.push_back(res);
			}
			j = k;
		}
	}
	return 0;
}