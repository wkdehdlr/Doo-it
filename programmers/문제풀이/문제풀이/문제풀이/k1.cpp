#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include <utility>
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

priority_queue< int, vector<int>, less<int> > pq;//ÃÖ´ëÈü
priority_queue< int, vector<int>, greater<int> > mpq;//ÃÖ¼ÒÈü

map<char, pair<int, int>> ma;
int N;
vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
string hand = "left";

int main() {

	char left = '*', right = '#';
	ma.insert({ '1', make_pair(0, 0) });
	ma.insert({ '2', make_pair(0, 1) });
	ma.insert({ '3', make_pair(0, 2) });
	ma.insert({ '4', make_pair(1, 0) });
	ma.insert({ '5', make_pair(1, 1) });
	ma.insert({ '6', make_pair(1, 2) });
	ma.insert({ '7', make_pair(2, 0) });
	ma.insert({ '8', make_pair(2, 1) });
	ma.insert({ '9', make_pair(2, 2) });
	ma.insert({ '0', make_pair(3, 1) });
	ma.insert({ '*', make_pair(3, 0) });
	ma.insert({ '#', make_pair(3, 2) });
	string res = "";

	int len = numbers.size();
	for (int i = 0; i < len; ++i) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			res += 'L';
			left = numbers[i] + '0';
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			res += 'R';
			right = numbers[i] + '0';
		}
		else {
			int l1 = ma.find(left)->second.first;
			int l2 = ma.find(left)->second.second;

			int r1 = ma.find(right)->second.first;
			int r2 = ma.find(right)->second.second;

			int n1 = ma.find(numbers[i] + '0')->second.first;
			int n2 = ma.find(numbers[i] + '0')->second.second;

			int nl = abs(l1 - n1) + abs(l2 - n2);
			int nr = abs(r1 - n1) + abs(r2 - n2);

			if (nl < nr) {
				res += 'L';
				left = numbers[i] + '0';
			}
			else if (nl > nr) {
				res += 'R';
				right = numbers[i] + '0';
			}
			else {
				if (hand == "right") {
					res += 'R';
					right = numbers[i] + '0';
				}
				else {
					res += 'L';
					left = numbers[i] + '0';
				}
			}
		}
	}
	return 0;
}