#pragma warning(disable:4996)
#include<cstdio>
using namespace std;

int N, M, r, c;
bool arr[2001][2001];
bool visited[2001][2001];

void DFS(int r, int depth) {
	for (int i = 0; i < N; ++i) {
		
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &r, &c);
		arr[r][c] = true;
		arr[c][r] = true;
	}

	for (int i = 0; i < N; ++i) {
		DFS(i, 0);
	}
}