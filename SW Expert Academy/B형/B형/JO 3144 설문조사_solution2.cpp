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
	int num;
	int blind;
	Trie *root;
	stud *next;
	stud() {
		this->blind = 0;
		this->root = new Trie;
		this->next = NULL;
	}
	stud(int num, int blind, stud *next) {
		this->num = num;
		this->blind = blind;
		this->root = new Trie;
		this->next = next;
	}
}*list, *excep;
int join[50001];
void initUser()
{
	while (list) {
		stud *tmp = list;
		list = tmp->next;
		delete tmp;
	}
	while (excep) {
		stud *tmp = excep;
		excep = tmp->next;
		delete tmp;
	}
	if (celeb)delete celeb;
	celeb = new Trie;
	list = NULL;
	excep = NULL;
	for (int i = 1; i <= 50000; ++i)join[i] = 0;
}
void addSurveyResult(int stdID, int cnt, char celebID[][11])
{
	int ok = 0;
	for (int i = 0; i < cnt; ++i) {
		if (celeb->check(celebID[i], CHECK))ok++;
	}

	if (ok) {//제외목록에 추가
		join[stdID] = 1;
		excep = new stud(stdID, ok, excep);
		for (int i = 0; i < cnt; ++i) {
			excep->root->insert(celebID[i]);
		}
	}
	else {//리스트에 추가
		join[stdID] = 2;
		list = new stud(stdID, 0, list);
		for (int i = 0; i < cnt; ++i) {
			list->root->insert(celebID[i]);
		}
	}
}
void cancelSurveyResult(int stdID)
{
	if (join[stdID] == 2) {
		if (!list)return;
		if (list->num == stdID) {
			stud *tmp = list;
			list = tmp->next;
			delete tmp;
			join[stdID] = 0;
		}
		else {
			stud *p = list;
			while (p->next) {
				if (p->next->num == stdID) {
					stud *tmp = p->next;
					p->next = tmp->next;
					delete tmp;
					join[stdID] = 0;
					return;
				}
				p = p->next;
			}
		}
	}

	else if (join[stdID] == 1) {
		if (!excep)return;
		if (excep->num == stdID) {
			stud *tmp = excep;
			excep = tmp->next;
			delete tmp;
			join[stdID] = 0;
		}
		else {
			stud *p = excep;
			while (p->next) {
				if (p->next->num == stdID) {
					stud *tmp = p->next;
					p->next = tmp->next;
					delete tmp;
					join[stdID] = 0;
					return;
				}
				p = p->next;
			}
		}
	}
}
void excep_blind_check(char celebID[])
{
	if (!excep)return;
	if (excep->root->search(celebID)) {
		excep->blind++;
	}
	stud *p = excep;
	while (p->next) {
		if (p->next->root->search(celebID)) {
			p->next->blind++;
		}
		p = p->next;
	}
}
void blindCelebID(char celebID[])
{
	celeb->check(celebID, BLIND);
	excep_blind_check(celebID);
	if (!list)return;
	while (list && list->root->search(celebID)) {
		list->blind++;
		stud *tmp = list;
		join[tmp->num] = 1;
		list = tmp->next;
		tmp->next = excep;
		excep = tmp;
	}
	if (!list)return;
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID)) {
			p->next->blind++;
			stud *tmp = p->next;
			join[tmp->num] = 1;
			p->next = tmp->next;
			tmp->next = excep;
			excep = tmp;
		}
		else p = p->next;
	}
}
void recoverCelebID(char celebID[])
{
	celeb->check(celebID, RECOVER);
	if (!excep)return;
	while (excep && excep->root->search(celebID)) {
		excep->blind--;
		if (excep->blind == 0) {
			stud *tmp = excep;
			join[tmp->num] = 2;
			excep = tmp->next;
			tmp->next = list;
			list = tmp;
		}
		else break;
	}
	if (!excep)return;
	stud *p = excep;
	while (p->next) {
		if (p->next->root->search(celebID)) {
			p->next->blind--;
			if (p->next->blind == 0) {
				stud *tmp = p->next;
				join[tmp->num] = 2;
				p->next = tmp->next;
				tmp->next = list;
				list = tmp;
			}
			else p = p->next;
		}
		else p = p->next;
	}
}
int count_single(char celebID[][11])
{
	if (!list)return 0;
	int cnt = 0;
	if (list->root->search(celebID[0])) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID[0])) {
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
	if (list->root->search(celebID[0]) && list->root->search(celebID[1])) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID[0]) && p->next->root->search(celebID[1])) {
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
	if (list->root->search(celebID[0]) || list->root->search(celebID[1])) {
		cnt++;
	}
	stud *p = list;
	while (p->next) {
		if (p->next->root->search(celebID[0]) || p->next->root->search(celebID[1])) {
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