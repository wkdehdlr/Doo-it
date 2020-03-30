#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<stack>
#include<functional>
using namespace std;

vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
vector<stack<int>> st(32);
stack<int> my;
int N;
int res = 0;
int main() {

	int N = board.size();
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j]) {
				st[j].push(board[i][j]);
			}
		}
	}

	int len = moves.size();
	for (int i = 0; i < len; ++i) {
		int idx = moves[i] - 1;
		if (!st[idx].empty()) {
			int tmp = st[idx].top();
			st[idx].pop();
			
			if (my.empty())my.push(tmp);
			else {
				if (my.top() == tmp) {
					res += 2;
					my.pop();
				}
				else {
					my.push(tmp);
				}
			}

		}
	}
	return res;
}