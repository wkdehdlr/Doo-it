#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

bool visited[8];
int arr[8];
int N, M;
//nCm
//5C2
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
			visited[i]=true;
			arr[c] = i;
			func(c + 1, i + 1);
			visited[i]=false;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	func(0, 0);
}
