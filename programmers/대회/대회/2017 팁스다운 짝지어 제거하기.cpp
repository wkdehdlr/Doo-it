#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> st;
int solution(string s)
{
	for (int i = 0; i < s.size(); ++i) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (st.top() == s[i])st.pop();
		}
	}
	if (st.empty())return 1;
	else return 0;
}