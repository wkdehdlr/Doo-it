#pragma warning(disable : 4996)
#include<cstdio>

struct cal {
	int id;
	cal *next;
	cal(int id, cal* next) {
		this->id = id;
		this->next = next;
	}
}*map[120][15][35];

struct info {
	int yy, mm, dd;
	info* next;
	info(int yy, int mm, int dd, info *next) {
		this->yy = yy;
		this->mm = mm;
		this->dd = dd;
		this->next = next;
	}
}*arr[10010];

int count[120][15][35];
int N, T;
int days(int y, int month) {
	int d[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y % 400 == 0 || (y % 4 == 0 && y % 100)) d[2] = 29; /// 윤년이라면
	return d[month];
}
void pop2(int id)
{
	info *p = arr[id];
	arr[id] = p->next;
	delete p;
}
void push2(int id, int yy, int mm, int dd)
{
	arr[id] = new info(yy, mm, dd, arr[id]);
}
void pop(int yy, int mm, int dd)
{
	cal *p = map[yy][mm][dd];
	map[yy][mm][dd] = p->next;
	delete p;
}
void push(int yy, int mm, int dd, int id)
{
	count[yy][mm][dd]++;
	map[yy][mm][dd] = new cal(id, map[yy][mm][dd]);
}
void update(int mode, int *y, int *m, int *d, int *date)
{
	if (mode >= 1 && mode <= 7) {
		*d += mode;
		if (*d > days(2000 + *y, *m)) {
			*d -= days(2000 + *y, *m);
			*m += 1;
			if (*m == 13) {
				*m = 1;
				*y += 1;
			}
		}
	}
	else if (mode == 8) {
		*m += 1;
		if (*m == 13) {
			*m = 1;
			*y += 1;
		}
	}
	else if (mode == 9) {
		*y += 1;
	}
	*date = (*y + 2000) * 10000 + (*m * 100) + *d;
}
void set()
{
	//9 6 94 21091202
	//ID, 예약일 지정방법, 반복횟수, 시작일
	//예약일 지정방법은 0은 그날 하루, 1~6은 반복하는 날짜의 주기, 7은 1주일, 8은 한달, 9는 1년 주기로 반복됨을 의미한다
	int id, mode, cnt, date1, date2, yy, mm, dd;
	scanf("%d %d %d %d", &id, &mode, &cnt, &date1);
	date2 = date1;
	yy = date1 / 10000; yy -= 2000; date1 %= 10000;
	mm = date1 / 100;
	dd = date1 % 100;
	date1 = date2;
	if (!mode)cnt = 1;
	for (int i = 0; i < cnt; ++i) {
		//push
		if (date1 < 20180101) {
			update(mode, &yy, &mm, &dd, &date1);
			continue;
		}
		if (date1 > 21171231)break;
		push(yy, mm, dd, id);
		push2(id, yy, mm, dd);
		update(mode, &yy, &mm, &dd, &date1);
	}
}
void delid(int id, int y, int m, int d)
{
	if (!arr[id])return;
	if (arr[id]->yy == y && arr[id]->mm == m && arr[id]->dd == d) {
		pop2(id);
	}
	else {
		info *p = arr[id];
		while (p->next) {
			if (p->next->yy == y && p->next->mm == m && p->next->dd == d) {
				info *tmp = p->next;
				p->next = tmp->next;
				delete tmp;
				break;
			}
			p = p->next;
		}
	}
}
void del_one(int y, int m, int d)
{
	while (map[y][m][d]) {
		delid(map[y][m][d]->id, y, m, d);
		pop(y, m, d);
		count[y][m][d]--;
	}
}
void deldate(int id, int y, int m, int d)
{
	if (!map[y][m][d])return;
	if (map[y][m][d]->id == id) {
		pop(y, m, d);
		count[y][m][d]--;
	}
	else {
		cal *p = map[y][m][d];
		while (p->next) {
			if (p->next->id == id) {
				cal *tmp = p->next;
				p->next = tmp->next;
				delete tmp;
				count[y][m][d]--;
				break;
			}
			p = p->next;
		}
	}
}
void del_all_id(int id)
{
	while (arr[id]) {
		deldate(id, arr[id]->yy, arr[id]->mm, arr[id]->dd);
		pop2(id);
	}
}
void del_all(int y, int m, int d)
{
	int id;
	while (map[y][m][d]) {
		id = map[y][m][d]->id;
		delid(id, y, m, d);
		pop(y, m, d);
		del_all_id(id);
		count[y][m][d]--;
	}
}

void del()
{
	int mode, id, date1, date2, yy, mm, dd;
	scanf("%d", &mode);
	if (mode == 0 || mode == 1) {
		scanf("%d", &date1);
		date2 = date1;
		yy = date1 / 10000; yy -= 2000; date1 %= 10000;
		mm = date1 / 100;
		dd = date1 % 100;
		date1 = date2;
		if (date1 < 20180101 || date1 > 21171231)return;
		if (mode == 0)del_one(yy, mm, dd);
		else if (mode == 1)del_all(yy, mm, dd);
	}
	else if (mode == 2) {
		scanf("%d", &id);
		del_all_id(id);
	}
}
void output()
{
	int date1, date2, date3;
	int y1, m1, d1;
	int ans = 0;

	scanf("%d %d", &date1, &date2);
	if (date1 < 20180101)date1 = 20180101;
	if (date2 > 21171231)date2 = 21171231;
	date3 = date1;
	y1 = date1 / 10000; y1 -= 2000; date1 %= 10000;
	m1 = date1 / 100;
	d1 = date1 % 100;
	date1 = date3;
	while (date1 <= date2) {
		ans += count[y1][m1][d1];
		update(1, &y1, &m1, &d1, &date1);
	}
	printf("%d\n", ans);
}
void init()
{
	for (int y = 0; y < 120; ++y) {
		for (int m = 0; m < 15; ++m) {
			for (int d = 0; d < 35; ++d) {
				while (map[y][m][d])pop(y, m, d);
				count[y][m][d] = 0;
			}
		}
	}
	for (int i = 0; i < 10010; ++i)while (arr[i])pop2(i);
}
int main()
{
	init();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1)set();
		else if (mode == 2)del();
		else if (mode == 3)output();
	}
}