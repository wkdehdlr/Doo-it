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
string expression = "50*6-3*2";
set<char> s;
vector<int> pq;
vector<string> vec;
vector<string> tmp;
long long mx = 0;
int main() {

	int now = 0;
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
	sort(pq.begin(), pq.end());



	do {
		vec.clear();
		tmp.clear();
		now = 0;
		for (int i = 0; i < expression.length(); ++i) {
			if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
				vec.push_back(expression.substr(now, i - now));
				now = i + 1;
				vec.push_back(string(1, expression[i]));
			}
		}
		vec.push_back(expression.substr(now, expression.length() - now));



		int len = pq.size();
		char c;
		for (int i = 0; i < len; ++i) {
			if (pq[i] == 0) {
				c = '+';
			}
			else if (pq[i] == 1) {
				c = '-';
			}
			else {
				c = '*';
			}

			if (i == len - 1)break;
			for (int j = 0; j < vec.size(); ++j) {
				if (vec[j][0] == c) {
					long long a1 = stoll(tmp.back());
					tmp.pop_back();
					long long a2 = stoll(vec[j + 1]);
					++j;
					if (c == '+') {
						tmp.push_back(to_string(a1 + a2));
					}
					else if (c == '-') {
						tmp.push_back(to_string(a1 - a2));
					}
					else {
						tmp.push_back(to_string(a1 * a2));
					}
				}
				else {
					tmp.push_back(vec[j]);
				}
			}
			vec = tmp;
			tmp.clear();
		}

		
		long long ans = stoll(vec[0]);
		for (int i = 1; i < vec.size(); ++i) {
			if (vec[i][0] != c) {
				if (c == '+') {
					ans += stoll(vec[i]);
				}
				else if (c == '-') {
					ans -= stoll(vec[i]);
				}
				else {
					ans *= stoll(vec[i]);
				}
			}
		}

		mx = max(mx, abs(ans));

	} while (next_permutation(pq.begin(), pq.end()));
	return 0;
}