#pragma warning(disable : 4996)
#include<cstdio>

extern void initUser();
extern void addSurveyResult(int stdID, int cnt, char celebID[][11]);
extern void cancelSurveyResult(int stdID);
extern void blindCelebID(char celebID[]);
extern void recoverCelebID(char celebID[]);
extern int query(int mode, char celebID[][11]);

static int queryNum;
static char name[4][11];

enum MODE {
	MODE0 = 0,
	MODE1 = 1,
	MODE2 = 2,
	SAVE = 3,
	CANCEL  = 4,
	BLIND = 5,
	RECOVER = 6
};

static int process()
{
	initUser();
	scanf("%d", &queryNum);

	int order, ans, userans, id, num;

	for(int i=0;i<queryNum;++i){
		scanf("%d", &order);

		switch (order)
		{
		case MODE0:
			scanf("%s %d", name[0], &ans);
			if (query(0, name) != ans)return 0;
			break;
		case MODE1:
			scanf("%s %s %d", name[0],name[1], &ans);
			if (query(1, name) != ans)return 0;
			break;
		case MODE2:
			scanf("%s %s %d", name[0],name[1], &ans);
			if (query(2, name) != ans)return 0;
			break;
		case SAVE:
			scanf("%d %d", &id, &num);
			for (int j = 0; j < num; ++j)scanf("%s", name[j]);
			addSurveyResult(id, num, name);
			break;
		case CANCEL:
			scanf("%d", &id);
			cancelSurveyResult(id);
			break;
		case BLIND:
			scanf("%s", name[0]);
			blindCelebID(name[0]);
			break;
		case RECOVER:
			scanf("%s", name[0]);
			recoverCelebID(name[0]);
			break;
		}
	}
	return 100;
}
int main()
{
	int tc = 1, sc = 100;
	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i) {
		if (process() != 100) {
			sc = 0;
			break;
		}
	}
	printf("%d\n", sc);
	return 0;
}