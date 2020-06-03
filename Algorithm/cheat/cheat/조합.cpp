#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

bool visited[8];
int arr[8];
int N, M;

void func(int c, int k) {
	if (c == M) {
		for (int i = 0; i < M; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = k; i < N; ++i) {
		if (!visited[i]) {
			arr[c] = i + 1;
			func(c + 1, i + 1);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	func(0, 0);
}