#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(string dartResult) {
	string str = dartResult;
	int from = 0, to = 0, i = 0, idx = 0;
	string arr[3];
	int len = str.length();
	while (i < len) {
		if (str[i] == 'S' || str[i] == 'D' || str[i] == 'T') {
			if (i == len - 1) {
				to = i; i++;
			}
			else if (str[i + 1] == '*' || str[i + 1] == '#') {
				to = i + 1; i += 2;
			}
			else {
				to = i; i++;
			}
			arr[idx++] = str.substr(from, to - from + 1);
			from = to + 1;
		}
		else i++;
	}

	int ret[3] = { 0,0,0 };
	for (int i = 0; i < 3; ++i) {
		int len = arr[i].length();
		int res = 0;
		for (int j = 0; j < len; ++j) {
			if (arr[i][j] == 'S' || arr[i][j] == 'D' || arr[i][j] == 'T') {
				if (arr[i][j] == 'D')res = pow(res, 2);
				else if (arr[i][j] == 'T')res = pow(res, 3);
			}
			else if (arr[i][j] == '*' || arr[i][j] == '#') {
				if (arr[i][j] == '*') {
					if (i != 0)ret[i - 1] *= 2;
					res *= 2;
				}
				else if (arr[i][j] == '#')res *= -1;
			}
			else {
				res *= 10;
				res += arr[i][j] - '0';
			}
		}
		ret[i] = res;
	}
	return ret[0] + ret[1] + ret[2];
}