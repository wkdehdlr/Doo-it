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
struct info
{
	string name;
	int res;
};
bool operator<(info f, info g) {
	if (f.res != g.res) {
		return f.res < g.res;
	}
	else {
		return f.name.compare(g.name);
	}
}

priority_queue<info> pq;
unordered_map<string, unordered_map<string, int>> um;
vector<vector<string>> dataSource, vector<string> tags;
int main() {
	vector<string> ans;
	int len = dataSource.size();
	for (int i = 0; i < len; ++i) {
		int len2 = dataSource[i].size();
		for (int j = 1; j < len2; ++j) {
			um[dataSource[i][0]].insert({ dataSource[i][j],1 });
		}
	}

	len = tags.size();
	for (auto it = um.begin(); it != um.end(); ++it) {
		int cnt = 0;
		for (int i = 0; i < len; ++i) {
			if (it->second.find(tags[i]) != it->second.end())cnt++;
		}
		pq.push({ it->first,cnt });
	}
	int res = 0;
	while (!pq.empty()) {
		ans.push_back(pq.top().name);
		pq.pop();
		res++;
		if (res == 10)break;
	}
	return ans;
}