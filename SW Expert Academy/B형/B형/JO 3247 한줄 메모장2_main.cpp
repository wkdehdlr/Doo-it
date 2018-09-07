#pragma warning(disable : 4996)
#include  <cstdio>

#define MAXLENGTH 1024

extern void initUser();
extern void Insert(char str[]);
extern void Backspace(int count);
extern void Delete(int count);
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
	freopen("input.txt", "r", stdin);
	int TC, N;
	int TotalScore = 0;
	int score;

	scanf("%d", &TC);
	int cmd, stPos, len;
	int t, i, j;
	for (t = 1; t <= TC; t++) {
		initUser();
		score = 100;

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &cmd);
			switch (cmd)
			{
			case CMD_INPUT:
				scanf("%d %s", &len, str);
				Insert(str);
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
				for (j = 0; j < len; ++j) {
					if (str[j] != ansStr[j]) break;
				}
				if (j < len) {
					score = 0;
					break;
				}
			}
			if (score == 0) break;
		}
		if (score == 0) break;
		TotalScore += score;
	}
	printf("Total Score : %d \n", TotalScore / TC);
	return 0;
}