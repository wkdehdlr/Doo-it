#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info
{
	int idx, num;
};
bool comp1(info f, info g)
{
	return f.idx < g.idx;
}
bool comp2(info f, info g)
{
	return f.idx > g.idx;
}
vector<vector<info> > inf(5);
vector<int> res;
bool visited[27][27];
bool visited2[27];
int N;
int mx = 0;
int main()
{
	scanf("%d", &N);
	N /= 2;
	for (int i = 1; i <= N; ++i)
	{
		int byun, idx;
		scanf("%d %d", &byun, &idx);
		inf[byun].push_back({ idx,i });
		scanf("%d %d", &byun, &idx);
		inf[byun].push_back({ idx,i });
	}
	sort(inf[1].begin(), inf[1].end(), comp1);
	sort(inf[2].begin(), inf[2].end(), comp2);
	sort(inf[3].begin(), inf[3].end(), comp2);
	sort(inf[4].begin(), inf[4].end(), comp1);

	
	for (int j = 0; j < inf[1].size(); ++j)res.push_back(inf[1][j].num);
	for (int j = 0; j < inf[4].size(); ++j)res.push_back(inf[4][j].num);
	for (int j = 0; j < inf[2].size(); ++j)res.push_back(inf[2][j].num);
	for (int j = 0; j < inf[3].size(); ++j)res.push_back(inf[3][j].num);

	int mn = 0;
	for (int i = 0; i < res.size(); ++i) {
		int tot = 0;
		if (visited2[res[i]])continue;
		int s = res[i];
		visited2[s] = true;

		for (int j = i + 1; j < 52; ++j) {
			if (res[j] == s)break;
			else {
				if (!visited[s][res[j]]) {
					visited[s][res[j]] = true;
					tot++;
					mn++;
				}
				else {
					tot--;
					mn--;
				}
			}
		}
		if (tot > mx)
			mx = tot;
	}
	printf("%d\n%d\n", mn / 2, mx);
}