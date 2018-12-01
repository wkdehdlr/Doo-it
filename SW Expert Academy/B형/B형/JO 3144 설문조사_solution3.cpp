#define NULL 0

struct node {
	int id;
	node *next;
	node(int id, node *next) {
		this->id = id;
		this->next = next;
	}
};

struct info {
	int blind = 0;
	char celebID[4][12];
}stud[50001];

int count_all(node *listA, node *listB)
{
	int cnt = 0;
	while (listA && listB) {
		if (listA->id == listB->id) {
			if (stud[listA->id].blind == 0)cnt++;
			listA = listA->next;
			listB = listB->next;
		}
		else if (listA->id < listB->id) {
			listA = listA->next;
		}
		else {
			listB = listB->next;
		}
	}
	return cnt;
}
struct Trie {
	bool blind;
	node *list;
	Trie *next[26];
	Trie() {
		this->list = NULL;
		this->blind = false;
		for (int i = 0; i < 26; ++i)next[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)if (next[i])delete next[i];
		while (list) {
			node *p = list;
			list = p->next;
			delete p;
		}
	}
	node* func(char *p) {
		if (*p == 0)return this->list;
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		return next[idx]->func(p + 1);
	}
	int count(char *p) {
		if (*p == 0) {
			int cnt = 0;
			if (!list)return 0;
			if (stud[list->id].blind == 0)cnt++;
			node *p = list;
			while (p->next) {
				if (stud[p->next->id].blind == 0)cnt++;
				p = p->next;
			}
			return cnt;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		return next[idx]->count(p + 1);
	}
	void cancel(char *p, int id) {
		if (*p == 0) {
			if (!list)return;
			if (list->id == id) {
				node *p = list;
				list = p->next;
				delete p;
				return;
			}
			node *p = list;
			while (p->next) {
				if (p->next->id == id) {
					node *tmp = p->next;
					p->next = tmp->next;
					delete tmp;
					return;
				}
				p = p->next;
			}
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		next[idx]->cancel(p + 1, id);
	}
	bool add(char *p, int id) {
		if (*p == 0) {
			if (!list)list = new node(id, list);
			else {
				if (list->id > id) {
					list = new node(id, list);
					return blind;
				}
				node *p = list;
				while (p->next && p->next->id < id)p = p->next;
				p->next = new node(id, p->next);
			}
			return blind;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		return next[idx]->add(p + 1, id);
	}
	void on_blind(char *p) {
		if (*p == 0) {
			blind = true;
			if (!list)return;
			stud[list->id].blind++;
			node *p = list;
			while (p->next) {
				stud[p->next->id].blind++;
				p = p->next;
			}
			return;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		next[idx]->on_blind(p + 1);
	}

	void off_blind(char *p) {
		if (*p == 0) {
			blind = false;
			if (!list)return;
			stud[list->id].blind--;
			node *p = list;
			while (p->next) {
				stud[p->next->id].blind--;
				p = p->next;
			}
			return;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL)next[idx] = new Trie();
		next[idx]->off_blind(p + 1);
	}
}*celeb;


void initUser()
{
	if (celeb)delete celeb;
	celeb = new Trie;
	for (int i = 1; i <= 50000; ++i) {
		stud[i].blind = 0;
		for (int j = 0; j < 4; ++j)stud[i].celebID[j][0] = '\0';
	}
}

/// 설문조사 결과를 저장
void my_strcpy(char *dst, char *src)
{
	int i = 0;
	while (src[i])dst[i] = src[i++];
	dst[i] = '\0';
}
void addSurveyResult(int stdID, int cnt, char celebID[][11])
{
	for (int i = 0; i < cnt; ++i) {
		if (celeb->add(celebID[i], stdID))stud[stdID].blind++;
		my_strcpy(stud[stdID].celebID[i], celebID[i]);
	}
}

/// 설문조사 결과 등록을 취소

void cancelSurveyResult(int stdID)
{
	for (int i = 0; i < 4; ++i) {
		if (stud[stdID].celebID[i][0]) {
			celeb->cancel(stud[stdID].celebID[i], stdID);
			stud[stdID].celebID[i][0] = '\0';
		}
	}
	stud[stdID].blind = 0;
}

/// 특정 유명 인물에 대한 모든 선호도 기록을 제외시키기

void blindCelebID(char celebID[])
{
	celeb->on_blind(celebID);
}

/// 특정 유명 인물에 대한 모든 선호도 기록이 제외되어 있다면 다시 복원

void recoverCelebID(char celebID[])
{
	celeb->off_blind(celebID);
}

/// 특정인물을 선호하는 학생수를 리턴한다.
/// 단, blind 처리된 인물을 선정하지 않은 학생이 대상이 된다.
/// mode == 0 : 단일 인물을 선호하는 학생 수
/// mode == 1 : 두 인물 모두를 선호하는 학생 수
/// mode == 2 : 둘 중 하나 이상을 선호하는 학생 수

int query(int mode, char celebID[][11])
{
	if (mode == 0)return celeb->count(celebID[0]);
	else if (mode == 1)return count_all(celeb->func(celebID[0]), celeb->func(celebID[1]));
	else return celeb->count(celebID[0]) + celeb->count(celebID[1]) - count_all(celeb->func(celebID[0]), celeb->func(celebID[1]));
}
