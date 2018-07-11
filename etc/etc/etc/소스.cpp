#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<queue>
#define IN 1
#define DE 2
#define BTN 1
#define NTN 0
using namespace std;

struct info {
	int btn_in;
	int ntn_in;
	int btn_de;
	int btn_in;
	int s_path;
	int prev;
};
queue<info> q;
vector<vector<pair<int, int> > > vec(100001);
int arr[100001];
bool visited[100001];
int T, N, M;
void dijkstra()
{
	//visited[1] = true;
	for (int i = 0; i < vec[1].size(); ++i) {
		q.push({ 1,vec[1][i].first,NTN,IN,vec[1][i].second,0 });
		q.push({ 1,vec[1][i].first,NTN,DE,vec[1][i].second,0 });
	}
	while (!q.empty())
	{
		info inf = q.front();
		q.pop();
		int in_de = inf.in_de;
		for (int i = 0; i < vec[inf.to].size(); ++i) {
			if (in_de == IN) {

			}
			else {

			}
			if (arr[vec[inf.to][i].first] > );
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d", &N, &M);
		for (int c = c; c <= M; ++c) {
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			vec[i].push_back({ j, k });
			vec[j].push_back({ i, k });
		}
		dijkstra();
	}

}