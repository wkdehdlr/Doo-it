#pragma warning(disable : 4996)
#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
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

int visited[10];
char input[110];
int len;

int main() {
	scanf("%s", input);
	len = strlen(input);

	for (int i = 0; i < len; ++i) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			visited[1] = 1;
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			visited[2] = 1;
		}
		else if (input[i] >= '0' && input[i] <= '9') {
			visited[3] = 1;
		}
		else {
			visited[4] = 1;
		}
	}
	if (len >= 10)visited[5] = 1;

	int cnt = 0;
	for (int i = 1; i <= 5; ++i) {
		if (visited[i])cnt++;
	}
	printf("LEVEL%d\n", cnt);
	return 0;
}