#pragma warning(disable : 4996)
#include<cstdio>

#define MAXLENGTH 1024

extern void initUser();
extern void Insert(int len, char str[]);
extern void Backspace(int len);
extern void Delete(int len);
extern void moveForward(int moveCnt);
extern void moveBackward(int moveCnt);
extern void Undo();
extern void getString(int stPos, int len, char str[]);

enum CMD {
	CMD_INPUT = 1,
	CMD_BACKSPACE = 2,
	CMD_DELETE = 3,
	CMD_FORWARD = 4,
	CMD_BACKWARD = 5,
	CMD_UNDO = 6,
	CMD_GETSTRING = 7
};

static char str[MAXLENGTH + 5], ansStr[MAXLENGTH + 5];

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	int score;
	int cmd, stPos, len;
	int i, j;

	initUser();
	score = 100;

	scanf("%d", &N);

	for (i = 0; i < N; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INPUT:
			scanf("%d %s", &len, str);
			Insert(len, str);
			break;
		case CMD_BACKSPACE:
			scanf("%d", &len);
			Backspace(len);
			break;
		case CMD_DELETE:
			scanf("%d", &len);
			Delete(len);
			break;
		case CMD_FORWARD:
			scanf("%d", &len);
			moveForward(len);
			break;
		case CMD_BACKWARD:
			scanf("%d", &len);
			moveBackward(len);
			break;
		case CMD_UNDO:
			Undo();
			break;
		case CMD_GETSTRING:
			for (j = 0; j <= MAXLENGTH; ++j) {
				str[j] = 0;
			}
			scanf("%d %d", &stPos, &len);
			getString(stPos, len, str);
			scanf("%s", ansStr);
			for (j = 0; j <len && ansStr[j]; ++j) {
				if (str[j] != ansStr[j]) break;
			}
			if (ansStr[j] != str[j]) {
				score = 0;
				break;
			}
		}
		if (score == 0) break;
	}
	printf("Score : %d \n", score);
	return 0;
}
