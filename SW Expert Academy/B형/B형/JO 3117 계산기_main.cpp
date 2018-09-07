#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MAX 50
#define LIMIT 100000
#define WORNG_ANSWER -1

static char problem[MAX * 20 + 5];
static char ret[LIMIT + MAX * 20];
static char str[MAX + 5];
char user[MAX + 5];


extern void Cal(char, char[]);

int main(void) {
	//    freopen("input.txt", "r", stdin);
	//    freopen("output.txt", "w", stdout);
	int TC, t;
	scanf("%d", &TC);
	//gets(str);
	gets_s(str, MAX + 5);
	for (t = 1; t <= TC; ++t) {
		//gets(problem);
		gets_s(problem, MAX * 20 + 5);
		memset(ret, 0, sizeof(ret));
		int pLen = strlen(problem), uLen = 0;
 		int retIdx = 0;

		Cal('C', user);
		user[MAX + 1] = 0;
		uLen = strlen(user);
		sprintf(ret + retIdx, "%s ", user);
		retIdx += uLen + 1;

		for (int i = 0; i < pLen; ) {
			sscanf(problem + i, "%s", str);
			int slen = strlen(str);
			i += slen + 1;
			if (str[0] >= '0' && str[0] <= '9') {
				for (int j = 0; j<slen; ++j) {
					Cal(str[j], user);
					user[MAX + 1] = 0;
					uLen = strlen(user);
					sprintf(ret + retIdx, "%s ", user);
					retIdx += uLen + 1;
				}
			}
			else {
				Cal(str[0], user);
				user[MAX + 1] = 0;
				uLen = strlen(user);
				sprintf(ret + retIdx, "%s ", user);
				retIdx += uLen + 1;
			}
		}
		puts(ret);
	}
	return 0;
}
