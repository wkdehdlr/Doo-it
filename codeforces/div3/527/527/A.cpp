#include<cstdio>
#include<cstring>
//using namespace std;
int T;
int N, K;
char arr[110];
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &K);
		char j = 'a';
		int i = 1,cnt = 1;
		for (; i <= N; ++i) {
			if (cnt > K) {
				j = 'a';
				cnt = 1;
			}
			arr[i - 1] = j;
			++j;
			++cnt;
		}
		//arr[i] = '\0';
		printf("%s\n", arr);
	}
}