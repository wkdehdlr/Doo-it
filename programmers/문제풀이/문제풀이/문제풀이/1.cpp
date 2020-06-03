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

stack<char> st;
string inputString = "if (Count of eggs is 4.) {Buy milk.}";
int main() {
	int ans = 0;
	int len = inputString.size();
	for (int i = 0; i < len; ++i) {
		if (inputString[i] == '(' || inputString[i] == '{' || inputString[i] == '[' || inputString[i] == '<') {
			st.push(inputString[i]);
		}
		else if (inputString[i] == ')' || inputString[i] == '}' || inputString[i] == ']' || inputString[i] == '>') {
			if (st.empty()) {
				return -1;
			}
			else {
				char t = st.top();
				if (t == '(' || t == '{' || t == '[' || t == '<') {
					st.pop();
					ans++;
				}
			}
		}
	}
	return ans;
}
