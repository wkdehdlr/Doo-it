#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> u;
vector<string> b;
unordered_set<int> st;
bool visited[10];
int n, m;

bool check(int i, int j) {
	int len1 = u[i].length();
	int len2 = b[j].length();
	if (len1 != len2)return false;

	for (int k = 0; k < len1; ++k) {
		if (b[j][k] == '*')continue;
		else {
			if (b[j][k] != u[i][k])return false;
		}
	}
	return true;
}
void func(int depth, int res) {
	if (depth == m) {
		st.insert(res);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && check(i, depth)) {
			visited[i] = true;
			func(depth + 1, res | 1 << (i + 1));
			visited[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	n = user_id.size();
	m = banned_id.size();
	u = user_id;
	b = banned_id;
	func(0, 0);
	return st.size();
}

int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};
	int ret = solution(user_id, banned_id);
	return 0;
}