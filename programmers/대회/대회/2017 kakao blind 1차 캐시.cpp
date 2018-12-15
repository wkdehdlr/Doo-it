#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int nowSize = 0;
map<string, int> ma;
vector<pair<string, int> > vec;
int solution(int cacheSize, vector<string> cities) {
	if (!cacheSize) {
		return cities.size() * 5;
	}
	int tm = 0;
	for (int i = 0; i < cities.size(); ++i) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		if (ma[cities[i]] == 0) {//cach miss
			if (nowSize == cacheSize) {//교체 O
				int size = vec.size();
				int mn = 999999999;
				int idx = 0;
				for (int j = 0; j < size; ++j) {
					if (vec[j].second < mn) {
						idx = j;
						mn = vec[j].second;
					}
				}
				ma[vec[idx].first] = 0;
				vec.erase(vec.begin() + idx);
			}
			else {//교체 X
				nowSize++;
			}
			vec.push_back({ cities[i],i + 1 });
			tm += 5;
			ma[cities[i]] = i + 1;
		}
		else {//cach hit
			tm++;
			int size = vec.size();
			for (int j = 0; j < size; ++j) {
				if (!(vec[j].first.compare(cities[i]))) {
					vec[j].second = i + 1;
				}
			}
			ma[cities[i]] = i + 1;
		}
	}
	return tm;
}