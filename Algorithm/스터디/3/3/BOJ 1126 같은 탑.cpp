#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int in[52];
int dp[52][500005];
int cnt = 0;
void init() {

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 500002; j++) {
			dp[i][j] = -2;  //초기화
		}
	}
}


int process(int index, int leftTop, int rightTop) {
	
	int t = leftTop - rightTop + 250000;

 	if (index > n) return -1; //불가능한 경우..
	if (leftTop > 250000 || rightTop > 250000) return -1;
	if (dp[index][t] != -2) { //방문했던 곳인 경우
		return dp[index][t];
	}
	cnt++;
	dp[index][t] = -1;
	if (t == 250000 && leftTop != 0) {
		//printf("%d\n", leftTop);
		dp[index][t] = 0;
	}

	int f = process(index + 1, leftTop + in[index], rightTop);
	int s = process(index + 1, leftTop, rightTop + in[index]);
	int z = process(index + 1, leftTop, rightTop);

	if (f != -1) {
		dp[index][t] = max(dp[index][t], f + in[index]);
	}

	if (s != -1) {
		dp[index][t] = max(dp[index][t], s);
	}

	if (z != -1) {
		dp[index][t] = max(dp[index][t], z);
	}

	return dp[index][t]; // 높이차이가 t일때, (앞으로 같아질수있다면) 왼쪽에 쌓을 탑 높이, 왼쪽탑만 쭉 더해서 리턴.
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	init();
	printf("%d\n", process(0, 0, 0));;
	printf("%d\n", cnt);
}

/*

3
2 3 5

*/