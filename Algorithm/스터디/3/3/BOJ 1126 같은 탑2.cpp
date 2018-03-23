#pragma warning(disable : 4996)
#include <cstdio>
#include<cmath>
//#include <algorithm>
//using namespace std;
int n;
int in[52];
int dp[52][250005];
int mx = 0;
int cnt = 0;
void init() {

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 500002; j++) {
			dp[i][j] = -2;
			//dp2[i][j] = -2; //초기화
		}
	}
}

void process(int index, int leftTop, int rightTop) {	
	int t = leftTop - rightTop + 250000 + leftTop;


	if (index > n) return; //불가능한 경우..
	if (leftTop > 250000 || rightTop > 250000) return;
	if (t == 250000 + leftTop && leftTop != 0) {//여기서 판단하는게 아님!!!!!!!!!!!!
		if (mx < leftTop)
			mx = leftTop;
		//dp[index][t] = 0;
	}


	if (dp[index][t] != -2) { //방문했던 곳인 경우
		return;
	}

	//cnt++;
	dp[index][t] = -1;
	//dp2[index * t] = -1;
	process(index + 1, leftTop + in[index], rightTop);
	process(index + 1, leftTop, rightTop + in[index]);
	process(index + 1, leftTop, rightTop);
} 



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	init();
	process(0, 0, 0);
	if (!mx)mx = -1;
	printf("%d\n", mx);
	//printf("%d\n", cnt);
}

/*


4
7
6
12
13

10
19
1
6
19
11
19
14
5
20
7

*/