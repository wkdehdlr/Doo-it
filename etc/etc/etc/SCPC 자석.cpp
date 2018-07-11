#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

bool visited[16];
int arr[16][3];
int T, N, mn;
void func(int n)
{
	if (n == N + 1) {
		int ret = 0;
		bool off_ary[16];
		vector<int> on;
		//vector<int> off;
		for (int i = 1; i <= N; ++i) {
			if (visited[i]) {
				on.push_back(i);//현재 자석만 따로 모음
				ret += arr[i][2];
			}
			else off_ary[i] = true;
			//else off.push_back(i);//자석이 아닌 막대기만 따로 모음
		}

		for (int i = 1; i <= N; ++i) {
			if (off_ary[i]) {//막대기면
				for (int j = 0; j < on.size(); ++j) {
					if (!(arr[on[j]][1] < arr[i][0] || arr[i][1] < arr[on[j]][0])) {//겹치면 자석에 붙임
						off_ary[i] = false;
						break;
					}
				}
			}
		}
		bool ok = true;
		for (int i = 1; i <= N; ++i) {
			if (off_ary[i])ok = false;
		}
		if (ok) {
			mn = min(mn, ret);
		}
		/*
		for (int i = 0; i < off.size(); ++i) {
		for (int j = 0; j < on.size(); ++j) {
		if (!(arr[on[j]][1] <= arr[off[i]][0] || arr[off[i]][1] <= arr[on[i]][0])) {//겹치면 자석에 붙임
		off.erase(off.begin() + i);//막대기에서 빼줌
		--i;
		break;
		}
		}
		}
		if (off.empty()) {
		mn = min(mn, ret);
		}*/
	}
	else {
		visited[n] = true;
		func(n + 1);
		visited[n] = false;
		func(n + 1);
	}
}
int main()
{
	//setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		mn = 987654321;
		scanf("%d", &N);
		if (N > 15) {
			printf("Case #%d\n%d\n", tc + 1, 1);
			continue;
		}
		for (int i = 1; i <= N; ++i) {
			scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		}
		func(1);
		printf("Case #%d\n%d\n", tc + 1, mn);
		for (int i = 1; i < 16; ++i)visited[i] = false;
	}
}