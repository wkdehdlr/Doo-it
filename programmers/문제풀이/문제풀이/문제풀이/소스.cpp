#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

string p = "()))((()";
stack<char> st;

bool balancedBucket(string s) {
	while (!st.empty())st.pop();

	for (int i = 0; i < s.length(); ++i) {
		char ch = s[i];
		if (ch == '(') {
			st.push(ch);
		}
		else {// ch == ')'
			if (st.empty()) {
				return false;
			}
			else {
				if (st.top() == '(') {
					st.pop();
				}
				else {
					return false;
				}
			}
		}
	}
	return st.empty();
}
string reformat(string u) {
	string str = "";
	int len = u.length(); 
	for (int i = 0; i < len; ++i) {
		if (i == 0 || i == len - 1)continue;
		else {
			if (u[i] == '(')str += ")";
			else str += "(";
		}
	}
	return str;
}

string func(string s) {
	if (s.empty())return "";
	string u, v, str = "(";
	int left = 0, right = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ')')right++;
		else left++;
		if (left == right) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1, s.length() - (i + 1));
			break;
		}
	}

	if (balancedBucket(u)) {
		return u + func(v);
	}
	else {
		str += func(v);
		str += ")";
		str += reformat(u);
	}
	return str;
}
int main() {

	if (balancedBucket(p))printf("%s\n", p.c_str());
	else {
		printf("%s\n",func(p).c_str());
	}
}