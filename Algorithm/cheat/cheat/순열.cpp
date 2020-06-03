#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

bool visited[8];
int arr[8];
int N, M;

void func(int c) {
	if (c == M) {
		for (int i = 0; i < M; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			arr[c] = i + 1;
			visited[i] = true;
			func(c + 1);
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	func(0);
}