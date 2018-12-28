#define MAX_KEY 19
#define MAX_TABLE 50001

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

typedef struct
{
	char key[MAX_KEY + 1];
	int cnt = 0;
}Hash;
Hash nametb[MAX_TABLE], numbertb[MAX_TABLE], birthtb[MAX_TABLE], emailtb[MAX_TABLE], memotb[MAX_TABLE];
int strcmp(char *s1, const char *s2) {

}
void strcpy(char *dst, const char *src)
{
	int i = 0;
	while (!src[i]) {
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
}
unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}
void erase(Hash *tb, unsigned long hs)
{
	tb[hs].cnt--;
	if (!tb[hs].cnt)tb[hs].key[0] = '\0';
	//tb[hs].key[0] = '\0';
}
unsigned long find(Hash *tb, const char *key)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return h;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 999999999;
}
int add(Hash *tb, const char *key)
{
	unsigned long h = hash(key);

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			tb[h].cnt++;
			return h;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	return h;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
struct node {
	unsigned long name;
	unsigned long number;
	unsigned long birth;
	unsigned long email;
	unsigned long memo;
	node *next;
	node(unsigned long name, unsigned long number, unsigned long birth, unsigned long email, unsigned long memo, node *next) {
		this->name = name;
		this->number = number;
		this->birth = birth;
		this->email = email;
		this->memo = memo;
		this->next = next;
	}
}*list;
void pop()
{
	node *tmp = list;
	list = tmp->next;
	erase(nametb, tmp->name);
	erase(numbertb, tmp->number);
	erase(birthtb, tmp->birth);
	erase(emailtb, tmp->email);
	erase(memotb, tmp->memo);
	delete tmp;
}

void InitDB()
{
	if (list)while (list)pop();
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	list = new node(add(nametb, name), add(numbertb, number), add(birthtb, birthday), add(emailtb, email), add(memotb, memo), list);
}
int del(FIELD field, unsigned long hs)
{
	while (list && list->birth == hs) {
		pop();
	}
	node *p = list;
	while (p->next) {
		if (p->next->birth == hs) {
			node *tmp = p->next;
			p->next = tmp->next;
			erase(nametb, tmp->name);
			erase(numbertb, tmp->number);
			erase(birthtb, tmp->birth);
			erase(emailtb, tmp->email);
			erase(memotb, tmp->memo);
			delete tmp;
		}
		else p = p->next;
	}
}
int Delete(FIELD field, char* str)
{
	if (field == NAME) {
		unsigned long hs = find(nametb, str);
		if (hs == 999999999)return 0;
		else {
			return del(field, hs);
		}
	}
	else if (field == NUMBER) {
		unsigned long hs = find(numbertb, str);
		if (hs == 999999999)return 0;
		else {
			return del(field, hs);
		}
	}
	else if (field == BIRTHDAY) {
		unsigned long hs = find(birthtb, str);
		if (hs == 999999999)return 0;
		else {
			return del(field, hs);
		}
	}
	else if (field == EMAIL) {
		unsigned long hs = find(emailtb, str);
		if (hs == 999999999)return 0;
		else {
			return del(field, hs);
		}
	}
	else if (field == MEMO) {
		unsigned long hs = find(memotb, str);
		if (hs == 999999999)return 0;
		else {
			return del(field, hs);
		}
	}
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	return -1;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	RESULT result;
	result.count = -1;

	return result;
}