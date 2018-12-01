#include<cstdio>

struct data {
	int yy;
	int mm;
	int dd;
	data *next;
	data(int yy, int mm, int dd, data *next) {
		this->yy = yy;
		this->mm = mm;
		this->dd = dd;
		this->next = next;
	}
}*arr[10050];

struct info {
	int id;
	info *next;
	info(int id, info *next) {
		this->id = id;
		this->next = next;
	}
}*arr2[150][15][35];

void push(int id, int yy, int mm, int dd) {
	arr[id] = new data(yy, mm, dd, arr[id]);
}
void push2(int id, int yy, int mm, int dd) {
	arr2[yy][mm][dd] = new info(id, arr2[yy][mm][dd]);
}

int days(int y, int m) {
	int d[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y % 400 == 0 || (y % 4 == 0 && y % 100)) d[2] = 29; /// 윤년이라면
	return d[m];
}

//ID, 예약일 지정방법, 시행횟수, 시작일
void set(int id, int how, int cnt, int date)
{
	int yy = (date / 10000) - 2000;
	int mm = (date % 10000) / 100;
	int dd = (date % 10000) % 100;

	for (int i = 0; i < cnt; ++i) {
		push(id, yy, mm, dd);
		push2(id, yy, mm, dd);
	}
}
int main()
{

}

struct Trie {
	int ok;
	Trie *next[26];
	Trie() {
		for (int i = 0; i < 26; ++i)next[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)if (next[i])delete next[i];
	}
	void insert(char *p) {
		if (!p)ok = 1;
		int idx = *p - 'A';
		if (!next[idx])next[idx] = new Trie();
		next[idx]->insert(p + 1);
	}

	int search(char *p) {
		if (!p)return ok;
		int idx = *p - 'A';
		if (!next[idx])return false;
		else return next[idx]->search(p + 1);
	}
};