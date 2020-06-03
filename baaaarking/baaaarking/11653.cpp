#pragma warning(disable: 4996)
#include<cstdio>
using namespace std;

int N, M = 2;
int main() {
	scanf("%d", &N);
	if (N == 1) {
		return 0;
	}
	while (1) {
		if (N%M) {
			M++;
		}
		else {
			printf("%d\n", M);
			N /= M;
			if (N == 1)break;
		}
	}
}