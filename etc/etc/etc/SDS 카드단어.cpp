#include<iostream>
#include<string>
using namespace std;
int N, T;
string str;
string ans;
int main() {
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N;
		getline(cin, str);
		getline(cin, str);
		ans = str[0];
		for (int i = 2; i < str.size(); i += 2) {
			if (ans[0] <= str[i])ans = str[i] + ans;
			else ans += str[i];
		}
		cout << "#" << tc + 1 << " " << ans << endl;
	}
}
