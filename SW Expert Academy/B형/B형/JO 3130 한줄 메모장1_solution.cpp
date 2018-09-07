#ifndef NULL
#define NULL 0
#endif

struct node {
	char ch;
	node *prev, *next;
	node() {
		this->ch = 0;
		this->prev = NULL;
		this->next = NULL;
	}
	node(char ch, node *prev, node *next) {
		this->ch = ch;
		this->prev = prev;
		this->next = next;
	}
}*head, *tail, *cur;
struct data {
	int flag;
	int len;
	char str[350010];
}ud;

void initUser() {
	head = new node();
	tail = new node();
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	cur = head->next;
}
void my_strcpy(char dst[], char src[])
{
	int i;
	for (i = 0; src[i]; ++i)
		dst[i] = src[i];
	//dst[i] = '\0';
}
void push(char ch)
{
	cur->next = new node(ch, cur, cur->next);
	cur->next->next->prev = cur->next;
	cur = cur->next;
}
void Insert(int len, char str[])
{
	for (int i = 0; i < len; ++i) {
		push(str[i]);
	}
	ud.flag = 1;
	ud.len = len;
	my_strcpy(ud.str, str);
}

void func(int len)
{
	for (int i = 0; i < ud.len; ++i) {
		ud.str[i + len] = ud.str[i];
	}
}
void Backspace(int len) {
	//int length = len;
	if (!ud.flag) {
		func(len);
		ud.len += len;
	}
	else {
		ud.flag = 0;
		ud.len = len;
	}
	while (len--) {
		ud.str[len] = cur->ch;
		node *p = cur->prev;
		node *tmp = p->next;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		cur = cur->prev;
		delete tmp;
		if (cur == head)break;
	}
	if (len) {
		int dis = len;
		for (len; len < ud.len; ++len) {
			ud.str[len - dis] = ud.str[len];
		}
	}
}

void Delete(int len) {
	int i, j;
	if (!ud.flag) {
		i = ud.len;
		j = ud.len + len;
		ud.len += len;
	}
	else {
		ud.flag = 0;
		i = 0;
		j = len;
		ud.len = len;
	}
	for (; i < j; ++i) {
		if (cur->next == tail)break;
		ud.str[i] = cur->next->ch;
		node *p = cur->next;
		cur->next = p->next;
		cur->next->prev = p->prev;
		delete p;
	}
}

void moveForward(int moveCnt) {
	while (moveCnt--) {
		cur = cur->prev;
		if (cur == head)break;
	}
}

void moveBackward(int moveCnt) {
	while (moveCnt--) {
		cur = cur->next;
		if (cur == tail)break;
	}
	cur = tail->prev;
}

void Undo() {
	if (ud.flag) {//삽입에 대한 undo
		Backspace(ud.len);
	}
	else {//삭제에 대한 undo
		Insert(ud.len, ud.str);
	}
}
void getString(int stPos, int len, char str[])
{
	node *pos = head->next;
	//while (stPos--)pos = pos->next;
	for (int i = 0; i < stPos; ++i)pos = pos->next;
	for (int i = 0; i < len; ++i) {
		str[i] = pos->ch;
		pos = pos->next;
		if (pos == tail)break;
	}
}