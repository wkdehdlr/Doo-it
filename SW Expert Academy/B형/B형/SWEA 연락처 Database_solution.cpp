typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;
RESULT res;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void my_strcpy(char *dst, char *src)
{
	int i = 0;
	while (src[i]) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
typedef struct leaf leaf;
struct node {
	char name[20], number[20], birthday[20], email[20], memo[20];
	node *next, *prev;
	leaf *p[5];
	node(char name[], char number[], char birthday[], char email[], char memo[], node *next) {
		my_strcpy(this->name, name);
		my_strcpy(this->number, number);
		my_strcpy(this->birthday, birthday);
		my_strcpy(this->email, email);
		my_strcpy(this->memo, memo);
		this->next = next;
		this->prev = prev;
		for (int i = 0; i < 5; ++i)this->p[i] = '\0';
	}
}*list;

struct leaf{
	leaf *next, *prev;
	struct node *p;
	leaf() {
		this->next = '\0';
		this->prev = '\0';
		this->p = '\0';
	}
	leaf(leaf *next, node *p) {
		this->prev = '\0';
		this->next = next;
		this->p = p;
	}
};

struct Trie {
	Trie *next[27];
	leaf *lf;
	Trie() {
		for (int i = 0; i < 27; ++i)next[i] = '\0';
		lf = '\0';
	}
	~Trie() {
		for (int i = 0; i < 27; ++i)if (next[i])delete next[i];
		while (lf) {
			leaf *tmp = lf;
			lf = tmp->next;
			delete tmp;
		}
	}
	leaf* insert(char *p, node *p2) {
		if (!(*p)) {
			lf = new leaf(lf, p2);
			if (lf->next)lf->next->prev = lf;
			return lf;
		}
		int i = 0;
		if (*p == '@')i = 26;
		else if (*p >= 'a' && *p <= 'z') i = *p - 'a';
		else if (*p >= '0' && *p <= '9') i = *p - '0';
		if (!next[i])next[i] = new Trie();
		return next[i]->insert(p + 1, p2);
	}
	int erase(char *p) {
		if (!(*p)) {
			int cnt = 0;
			while (lf) {
				node *p = lf->p;
				cnt++;
				for (int i = 0; i < 5; ++i) {
					leaf* tmp = p->p[i];
					if (!tmp->prev) {
						p->p[i] = tmp->next;
					}
					else {
						tmp->prev->next = tmp->next;
						if (tmp->next)tmp->next->prev = tmp->prev;
					}
					delete tmp;
				}
				if (!p->prev) {
					list = p->next;
				}
				else {
					p->prev->next = p->next;
					if (p->next)p->next->prev = p->prev;
				}
				delete p;
			}
			return cnt;
		}
		int i = 0;
		if (*p == '@')i = 26;
		else if (*p >= 'a' && *p <= 'z') i = *p - 'a';
		else if (*p >= '0' && *p <= '9') i = *p - '0';
		return next[i]->erase(p + 1);
	}
	void search(char *p, FIELD field) {
		if (!(*p)) {
			res.count = 0;
			while (lf) {
				res.count++;
				if (res.count == 1) {
					if (field == NAME)my_strcpy(res.str, lf->p->name);
					else if (field == NUMBER)my_strcpy(res.str, lf->p->number);
					else if (field == BIRTHDAY)my_strcpy(res.str, lf->p->birthday);
					else if (field == EMAIL)my_strcpy(res.str, lf->p->email);
					else if (field == MEMO)my_strcpy(res.str, lf->p->memo);
				}
				lf = lf->next;
			}
			return;
		}
		int i = 0;
		if (*p == '@')i = 26;
		else if (*p >= 'a' && *p <= 'z') i = *p - 'a';
		else if (*p >= '0' && *p <= '9') i = *p - '0';
		if (!next[i])next[i] = new Trie();
		next[i]->search(p + 1, field);
	}
	int change(char *p, int flag, char* changestr) {
		if (!(*p)) {
			int cnt = 0;
			while (lf) {
				cnt++;
				leaf* tmp = lf->p->p[flag];
				if (tmp->prev)tmp->prev->next = tmp->next;
				if (tmp->next)tmp->next->prev = tmp->prev;
				delete tmp;
				my_strcpy(lf->p->name, changestr);
				namet->insert(changestr, lf->p);
				lf = lf->next;
			}
			return cnt;
		}
		int i = 0;
		if (*p == '@')i = 26;
		else if (*p >= 'a' && *p <= 'z') i = *p - 'a';
		else if (*p >= '0' && *p <= '9') i = *p - '0';
		if (!next[i])next[i] = new Trie();
		return next[i]->change(p + 1, flag, changestr);
	}

}*namet, *numbert, *birtht, *emailt, *memot;

void InitDB()
{
	if (namet)delete namet;
	if (numbert)delete numbert;
	if (birtht)delete birtht;
	if (emailt)delete emailt;
	if (memot)delete memot;
	namet = new Trie;
	numbert = new Trie;
	birtht = new Trie;
	emailt = new Trie;
	memot = new Trie;

	while (list) {
		node *tmp = list;
		list = tmp->next;
		delete tmp;
	}
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	list = new node(name, number, birthday, email, memo, list);
	if (list->next)list->next->prev = list;
	list->p[0] = namet->insert(name, list);
	list->p[1] = numbert->insert(number, list);
	list->p[2] = birtht->insert(birthday, list);
	list->p[3] = emailt->insert(email, list);
	list->p[4] = memot->insert(memo, list);
}

int Delete(FIELD field, char* str)
{
	if (field == NAME) {
		return namet->erase(str);
	}
	else if (field == NUMBER) {
		return numbert->erase(str);
	}
	else if (field == BIRTHDAY) {
		return birtht->erase(str);
	}
	else if (field == EMAIL) {
		return emailt->erase(str);
	}
	else if (field == MEMO) {
		return memot->erase(str);
	}
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	int flag = 0;
	if (changefield == NAME)flag = 0;
	else if (changefield == NUMBER)flag = 1;
	else if (changefield == BIRTHDAY)flag = 2;
	else if (changefield == EMAIL)flag = 3;
	else if (changefield == MEMO)flag = 4;

	if (field == NAME) {
		return namet->change(str,flag,changestr);
	}
	else if (field == NUMBER) {
		return numbert->change(str, flag, changestr);
	}
	else if (field == BIRTHDAY) {
		return birtht->change(str, flag, changestr);
	}
	else if (field == EMAIL) {
		return emailt->change(str, flag, changestr);
	}
	else if (field == MEMO) {
		return memot->change(str, flag, changestr);
	}
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	if (field == NAME) {
		namet->search(str, ret_field);
	}
	else if (field == NUMBER) {
		numbert->search(str, ret_field);
	}
	else if (field == BIRTHDAY) {
		birtht->search(str, ret_field);
	}
	else if (field == EMAIL) {
		emailt->search(str, ret_field);
	}
	else if (field == MEMO) {
		memot->search(str, ret_field);
	}
	return res;
}