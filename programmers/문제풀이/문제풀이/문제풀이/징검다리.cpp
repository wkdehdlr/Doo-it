#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int N = 2;
vector<int> rocks = { 2, 14, 11, 21, 17 };
int len, mid;

bool func() {
	int cnt = 0, now = 0;
	for (int i = 0; i < len; ++i) {
		if (rocks[i] - now <= mid) {
			cnt++;
		}
		else {
			now = rocks[i];
		}
	}
	if (cnt <= N)return true;
	else return false;
}

int main() {
	len = rocks.size();
	sort(rocks.begin(), rocks.end());
	int left = 0;
	int right = 25;
	while (left < right) {
		mid = (left + right) / 2;
		if (func()) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	printf("%d", mid);
}