#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

char str[53];
bool visited[27][27];
bool visited2[27];
int res = 0;

int main()
{
	scanf("%s", str);
	for (int i = 0; i < 52; ++i) {
		if (visited2[str[i] - 'A'])continue;
		char s = str[i];
		visited2[s - 'A'] = true;

		for (int j = i + 1; j < 52; ++j) {
			if (str[j] == s)break;
			else {
				if (!visited[s - 'A'][str[j] - 'A'])  {
					visited[s - 'A'][str[j] - 'A'] = true;
					//visited[str[j] - 'A'][s - 'A'] = true;
					res++;
				}
				else {
					res--;
				}
			}
		}
	}
	printf("%d\n", res/ 2);
}