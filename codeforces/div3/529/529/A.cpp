#include<cstdio>
using namespace std;

int n;
char str[60];
char ans[11];
int main()
{	
	int idx = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0, j = 0; i < n; i += j) {
		ans[idx++] = str[i];
		++j;
	}
	ans[idx] = '\0';
	printf("%s\n", ans);
}