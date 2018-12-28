#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N;
char str[1050];
int main()
{	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%s", str);
		N = strlen(str);
		sort(str, str + N);
		if (str[0] == str[N - 1])printf("-1\n");
		else {
			str[N] = '\0';
			printf("%s\n", str);
		}
	}
}