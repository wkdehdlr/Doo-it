#pragma warning(disable : 4996)
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


#define N 1000005
#define M 1005
typedef long long LL;


static int org[N], dat[N], ans[M], user_ans[M];
static int getCount, userN;
static int orgN, dataN, ansN;
extern int card_find(int user_ans[]);



int getNumber(int select, int num) {

	getCount++;

	if (select == 1) return org[num];

	else if (select == 2) return dat[num];

	else return 0;

}



static void init()

{

	int i;

	getCount = ansN = 0;

	for (i = 0; i < 1000; i++) {

		user_ans[i] = 0;

	}



	scanf("%d %d", &orgN, &dataN);

	ansN = orgN - dataN;

	for (i = 0; i < orgN; i++) scanf("%d", &org[i]);

	for (i = 0; i < dataN; i++) scanf("%d", &dat[i]);

	for (i = 0; i < ansN; i++) {

		scanf("%d", &ans[i]);

	}

}



inline void Swap(int&a, int&b) {

	int tmp = a; a = b; b = tmp;

}



static void init(int tc)

{

	int i;

	/// 초기화

	getCount = 0;

	for (i = 0; i < M; ++i) {

		ans[i] = user_ans[i] = 0;

	}

	for (i = 0; i < N; ++i) {

		org[i] = dat[i] = 0;

	}



	/// 데이터 생성

	orgN = 100000 + tc * 100000 + rand() % 10000;

	if (orgN > N) orgN = N;

	ansN = 100 + rand() % 901;

	dataN = orgN - ansN;

	for (i = 0; i < orgN; ++i) org[i] = i + 1;

	for (i = 0; i < orgN; ++i) {

		int idx = (LL)rand()*rand() % orgN;

		Swap(org[i], org[idx]);

	}

	for (i = 0; i < orgN; ++i) dat[i] = org[i];

	/// dat[]에서 ansN개 삭제

	for (i = 0; i < ansN; ++i) {

		int idx = (LL)rand()*rand() % orgN;

		while (dat[idx] == 0) {

			idx = (LL)rand()*rand() % orgN;

		}

		dat[idx] = 0;

	}

	int j = 0, k = 0;

	for (i = 0; i < orgN; ++i) {

		if (dat[i] == 0) ans[k++] = org[i];

		else dat[j++] = dat[i];

	}

	for (; j < orgN; ++j) dat[j] = 0;

	//sort(org, org + orgN);
	//sort(dat, dat + dataN);
	//sort(ans, ans + ansN);
}



static void check()
{
	if (ansN != userN) getCount = N;
	/*for (int i = 0; i < 548; i++) {
		if (ans[i] != user_ans[i])printf("%d %d %d\n", i, ans[i], user_ans[i]);
	}*/
	for (int i = 0; i < ansN; i++) {

		if (ans[i] != user_ans[i]) getCount = N;

	}
}



int main(void)
{
	//srand((unsigned)time(NULL));
	int T = 8; /// 0 ~ 9
			   //scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		// init();
		init(tc);
		userN = card_find(user_ans);
		check();
		printf("#%d %d %d\n", tc + 1, ansN,getCount);
	}
	return 0;
}