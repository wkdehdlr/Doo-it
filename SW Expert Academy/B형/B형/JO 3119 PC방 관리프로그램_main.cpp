#pragma warning(disable : 4996)
#include  <stdio.h >

extern void initUser(int baseTick);
extern int joinGuest(char* identity, char  * password);
extern int logoutGuest(char*identity);
extern int contactGuest(char*identity, char*password);
extern int reduceTick();
extern int remainGuest();

static int queryCount;               /// 전체 요청 수
static int baseTick;                 /// 기본 제공 시간
static char ID[12], PW[12];

enum { JOIN, LOGOUT, CONTACT, REDUCE, REMAIN };

static int process()
{
	int i, order, answer = 0, userAns = 0;
	for (i = 0; i <queryCount; ++i)
	{
		scanf("%d", &order);
		switch (order)
		{
		case JOIN:
			scanf("%s %s %d", ID, PW, &answer);
			userAns = joinGuest(ID, PW);
			break;
		case LOGOUT:
			scanf("%s %d", ID, &answer);
			userAns = logoutGuest(ID);
			break;
		case CONTACT:
			scanf("%s %s %d", ID, PW, &answer);
			userAns = contactGuest(ID, PW);
			break;
		case REDUCE:
			scanf("%d", &answer);
			userAns = reduceTick();
			break;
		case REMAIN:
			scanf("%d", &answer);
			userAns = remainGuest();
			break;
		}
		if (answer != userAns)
			return 0;
	}
	return 100;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int testcase, tc, score = 0;
	scanf("%d", &testcase);
	for (tc = 1; tc <= testcase; ++tc)
	{
		scanf("%d %d", &baseTick, &queryCount);
		initUser(baseTick);
		score = process();
		if (!score) break;
	}
	printf("%d\n", score);
	return true;
}