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


int N;
stack<char> st;
stack<long long> ans;
string expression = "100-200*300-500+20";
vector<string> vec;
vector<int> pq;
set<char> s;
long long mx = 0;
/*
+ - *
0 1 2
*/

bool check(char c1, char c2) {
	int i1, i2;
	if (c1 == '+') i1 = 0;
	else if (c1 == '-')i1 = 1;
	else i1 = 2;

	if (c2 == '+') i2 = 0;
	else if (c2 == '-')i2 = 1;
	else i2 = 2;

	int t1, t2;
	for (int i = 0; i < pq.size(); ++i) {
		if (pq[i] == i1)t1 = i;
	}

	for (int i = 0; i < pq.size(); ++i) {
		if (pq[i] == i2)t2 = i;
	}

	return t1 <= t2;
}

int main() {
	for (int i = 0; i < expression.length(); ++i) {
		if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
			s.insert(expression[i]);
		}
	}
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (*it == '+') {
			pq.push_back(0);
		}
		else if (*it == '-') {
			pq.push_back(1);
		}
		else {
			pq.push_back(2);
		}
	}



	do {
		vec.clear();
		while (!st.empty())st.pop();
		while (!ans.empty())ans.pop();
		int now = 0;

		for (int i = 0; i < expression.length(); ++i) {
			if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
				vec.push_back(expression.substr(now, i - now));
				now = i + 1;

				if (st.empty())st.push(expression[i]);
				else {
					while (1) {
						if (!st.empty()) {
							char tp = st.top();
							char op = expression[i];
							if (check(tp, op)) {//tp 우선순위가 높다
								vec.push_back(string(1, tp));
								st.pop();
							}
							else break;
						}
						else break;
					}
					st.push(expression[i]);
				}
			}
		}
		while (!st.empty()) {
			vec.push_back(string(1, st.top()));
			st.pop();
		}

		
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i][0] == '+' || vec[i][0] == '-' || vec[i][0] == '*') {
				long long a1 = ans.top(); ans.pop();
				long long a2 = ans.top(); ans.pop();
				if (vec[i][0] == '+') {
					ans.push(a2 + a1);
				}
				else if (vec[i][0] == '-') {
					ans.push(a2 - a1);
				}
				else {
					ans.push(a2 * a1);
				}
			}
			else {
				ans.push(stoll(vec[i]));
			}
		}
		mx = max(mx, ans.top());
		ans.pop();

	} while (next_permutation(pq.begin(), pq.end()));
	return mx;
}