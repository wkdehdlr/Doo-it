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

struct info {
	int tail;
	int head;
	int len;
};
bool operator<(info f, info g) {
	if (f.len == g.len) {
		return f.tail > g.tail;
	}
	return f.len > g.len;
}
priority_queue<info> pq;

int n;
vector<string> gems = { "AA", "AB", "AC", "AA", "AC" };
unordered_map<string, int> um;
int main() {
	vector<int> ans;
	for (int i = 0; i < gems.size(); ++i)um.insert({ gems[i],0 });
	n = um.size();

	int tail = 0;
	int head = 0;
	int cnt = 0;

	while (1) {

		while (1) {
			if (!um[gems[head]]) {
				cnt++;
			}
			um[gems[head]]++;
			head++;
			if (cnt == n)break;
			if (head == gems.size())break;
		}

		while (1) {
			if (um[gems[tail]] > 1) {
				um[gems[tail]]--;
			}
			else if(um[gems[tail]] == 1){
				um[gems[tail]] = 0;
				cnt--;
				if (cnt == n - 1)pq.push({ tail + 1,head,head - 1 - tail });
				tail++;
				break;
			}
			tail++;
			if (tail == gems.size())break;
		}
		if (head == gems.size())break;
		if (tail == gems.size())break;
	}

	info f = pq.top();
	ans.push_back(f.tail);
	ans.push_back(f.head);
	return 0;
}