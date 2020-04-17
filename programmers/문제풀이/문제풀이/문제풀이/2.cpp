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

priority_queue< int, vector<int>, less<int> > pq;//√÷¥Î»¸
priority_queue< int, vector<int>, greater<int> > mpq;//√÷º“»¸
string answer_sheet = "4132315142";
vector<string> sheets = { "3241523133","4121314445","3243523133","4433325251","2412313253" };
int tmx = 0;
int s[2];
int len, len2;
bool visited[201];

int func(int idx1, int idx2) {
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < len2; ++i) {
		if (answer_sheet[i] != sheets[idx1][i] && sheets[idx1][i] == sheets[idx2][i]) {
			int nlen = 1;
			cnt++;
			int j = i + 1;
			for (; j < len2; ++j) {
				if (answer_sheet[j] != sheets[idx1][j] && sheets[idx1][j] == sheets[idx2][i]) {
					cnt++;
					nlen++;
				}
				else {
					break;
				}
			}
			mx = max(mx, nlen);
			i = j;
		}
	}
	return cnt + (mx * mx);
}
void DFS(int idx, int depth) {
	if (depth == 2) {
		tmx = max(tmx, func(s[0], s[1]));
		return;
	}
	for (int i = idx; i < len; ++i) {
		if (visited[i])continue;
		visited[i] = true;
		s[depth] = i;
		DFS(i, depth + 1);
		visited[i] = false;
	}
}
int main() {
	len2 = answer_sheet.size();
	len = sheets.size();
	DFS(0, 0);
	return tmx;
}