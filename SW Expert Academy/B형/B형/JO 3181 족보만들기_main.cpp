#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
	Add = 1,
	Del = 2,
	Mov = 3,
	Cnt = 4
};
extern void init_user();
extern void Add_child(char name[]);
extern int Delete(char name[]);
extern void Move(char name[]);
extern int Count(char name[]);

int main()
{
	int T, N, order;
	char name[15];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		init_user();
		while (N--) {
			scanf("%d", &order);
			switch (order) {
			case Add:
				scanf("%s", name);
				Add_child(name);
				break;
			case Del:
				scanf("%s", name);
				printf("%d\n", Delete(name));
				break;
			case Mov:
				scanf("%s", name);
				Move(name);
				break;
			case Cnt:
				scanf("%s", name);
				printf("%d\n", Count(name));
			}
		}
	}
	return 0;
}
void my_strcpy(char *str1, char *str2)
{
	int idx = 0;
	while (str2[idx]) {
		str1[idx] = str2[idx];
		idx++;
	}
	str1[idx] = '\0';
}
int my_strncmp(char *str1, char *str2, int len)
{
	for (int i = 0; i < len; ++i) {
		if (str1[i] != str2[i])return 0;
	}
	return 1;
}
int my_strcmp(char *str1, char *str2)
{
	for (int i = 0; str1[i] && str2[i]; ++i) {
		if (str1[i] < str2[i])return -1;
		else if (str1[i] > str2[i])return 1;
	}
	return 0;
}
int my_strlen(char *name)
{
	int idx = 0;
	while (name[idx])idx++;
	return idx;
}