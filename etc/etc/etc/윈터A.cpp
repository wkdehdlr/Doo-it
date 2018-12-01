#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int arr[30];
string skill = "BDC";
vector<string> skill_trees = { "XDYZB"};

int find_first(int i)
{
	int k = 0;
	while (arr[skill_trees[i][k] - 'A'] == -1)k++;
	if (arr[skill_trees[i][k] - 'A'] != 0)return 1;
	return 0;
}
int solution()
{
	memset(arr, -1, sizeof(arr));
	int len = skill.size();
	for (int i = 0; i < len; ++i) {
		arr[skill[i] - 'A'] = i;
	}
	int cnt = 0;
	int s = skill_trees.size();
	for (int i = 0; i < s; ++i) {
		bool ok = true;
		int before = 0, now;
		int len = skill_trees[i].size();

		if (find_first(i))continue;
		for (int j = 0; j < len; ++j) {
			if (arr[skill_trees[i][j] - 'A'] == -1)continue;
			now = arr[skill_trees[i][j] - 'A'];
			if (now < before) {
				ok = false;
				break;
			}
			else before = now;
		}
		if (ok)cnt++;
	}
	return cnt;
}
int main()
{
	printf("%d\n", solution());
}