#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<string, int> umap;
int N;
vector<string> pt = { "marina", "josipa", "nikola", "vinko", "filipa"};
vector<string> co;
int main() {
	int len = pt.size();
	for (int i = 0; i < len; ++i) {
		if (umap.find(pt[i]) == umap.end()) {
			umap[pt[i]] = 1;
		}
		else {
			umap[pt[i]]++;
		}
	}

	len = co.size();
	for (int i = 0; i < len; ++i) {
		if (umap.find(co[i]) == umap.end()) {
			ans = co[i];
			return ans;
		}
		else {
			if (umap[co[i]] == 1) {
				umap.erase(co[i]);
			}
			else {
				umap[co[i]]--;
			}
		}
	}
	for (auto it = umap.begin(); it != umap.end(); ++it) {
		ans = it->first;
		return ans;
	}
}