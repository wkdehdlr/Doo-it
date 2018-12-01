#define NULL 0
#define CHECK 1
#define BLIND 2
#define RECOVER 3

struct Trie {
	bool end;
	bool blind;
	Trie *next[26];
	Trie() {
		this->blind = false;
		this->end = false;
		for (int i = 0; i < 26; ++i)next[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)if (next[i])delete next[i];
	}
	int check(char *p, int n) {
		if (*p == 0) {
			if (n == CHECK) {
				if (blind)return 1;
				else return 0;
			}
			else if (n == BLIND)blind = true;
			else blind = false;
			return 1;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL) {
			next[idx] = new Trie();
		}
		return next[idx]->check(p + 1, n);
	}
	void insert(char *p) {
		if (*p == 0) {
			end = true;
			return;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL) {
			next[idx] = new Trie();
		}
		next[idx]->insert(p + 1);
	}
	int search(char *p) {
		if (*p == 0) {
			if (end)return 1;
			else return 0;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)return 0;
		else return next[idx]->search(p + 1);
	}
}*celeb;

struct stud {
	int blind;
	int num;
	Trie *root;
	stud *next;
	stud() {
		this->blind = 0;
		this->root = new Trie;
		this->next = NULL;
	}
	stud(int blind, int num, stud *next) {
		this->blind = blind;
		this->num = num;
		this->root = new Trie;
		this->next = next;
	}
}*list;

void initUser()
{
	while (list) {
		stud *tmp = list;
		list = tmp->next;
		delete tmp;
	}
	if (celeb)delete celeb;
	celeb = new Trie;
	list = NULL;
}
void addSurveyResult(int stdID, int cnt, char celebID[][11])
{
	list = new stud(0, stdID, list);
	for (int i = 0; i < cnt; ++i) {
		if (celeb->check(celebID[i], CHECK))list->blind++;
		list->root->insert(celebID[i]);
	}

}
void cancelSurveyResult(int stdID)
{
	if (!list)return;
	if (list->num == stdID) {
		stud *tmp = list;
		list = tmp->next;
		delete tmp;
	}
	else {
		stud *p = list;
		while (p->next) {
			if (p->next->num == stdID) {
				stud *tmp = p->next;
				p->next = tmp->next;
				delete tmp;
				return;
			}
			p = p->next;
		}
	}
}
void blindCelebID(char celebID[])
{
	celeb->check(celebID, BLIND);
	if (!list)return;
	if (list->root->search(celebID)){
		list->blind++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID)){
			p->next->blind++;
		}
		p = p->next;
	}	
}
void recoverCelebID(char celebID[])
{
	celeb->check(celebID, RECOVER);
	if (!list)return;
	if (list->root->search(celebID)) {
		list->blind--;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID)) {
			p->next->blind--;
		}
		p = p->next;
	}
}
int count_single(char celebID[][11])
{
	if (!list)return 0;
	int cnt = 0;
	if (list->blind == 0 && list->root->search(celebID[0])) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->blind == 0 && p->next->root->search(celebID[0])) {
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}
int count_all(char celebID[][11])
{
	if (!list)return 0;
	int cnt = 0;
	if (list->blind == 0 && list->root->search(celebID[0]) && list->root->search(celebID[1])) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->blind == 0 && p->next->root->search(celebID[0]) && p->next->root->search(celebID[1])) {
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}
int count_or(char celebID[][11])
{
	if (!list)return 0;
	int cnt = 0;
	if (list->blind == 0 && (list->root->search(celebID[0]) || list->root->search(celebID[1]))) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->blind == 0 && (p->next->root->search(celebID[0]) || p->next->root->search(celebID[1]))) {
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}
int query(int mode, char celebID[][11])
{
	if (mode == 0)return count_single(celebID);
	else if (mode == 1)return count_all(celebID);
	else if (mode == 2)return count_or(celebID);
}