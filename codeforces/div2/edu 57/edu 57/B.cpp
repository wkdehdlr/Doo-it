#include<iostream>
#include<string>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif

	int n;
	string s;
	cin >> n >> s;
	int cntl = 0, cntr = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == s[0]) {
			++cntl;
		}
		else {
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == s[n - 1]) {
			++cntr;
		}
		else {
			break;
		}
	}
	if (s[0] == s[n - 1]) {
		cout << ((cntl + 1) * 1ll * (cntr + 1)) % 998244353 << endl;
	}
	else {
		cout << (cntl + cntr + 1) % 998244353;
	}

	return 0;
}