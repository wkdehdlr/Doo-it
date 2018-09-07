#ifndef NULL
#define NULL 0
#endif
#define IN 1
#define OUT 0

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
}*head[4], *tail[4], *cur[4];
int flag;

void initUser() {
	for (int i = 1; i < 4; ++i) {
		head[i] = new node();
		tail[i] = new node();
		head[i]->prev = head[i];
		head[i]->next = tail[i];
		tail[i]->prev = head[i];
		tail[i]->next = tail[i];
		cur[i] = head[i];
	}
	flag = 0;
}
void clear(int n)
{
	node *p = head[n];
	while (p->next != tail[n]) {
		node *tmp = p->next;
		p->next = tmp->next;
		p->next->prev = tmp->prev;
		delete tmp;
	}
	cur[n] = head[n];
}
void listcpy(int src, int dst)
{
	node *p = head[src];
	while (p->next != tail[src]) {
		cur[dst]->next = new node(p->next->ch, cur[dst], cur[dst]->next);
		cur[dst]->next->next->prev = cur[dst]->next;
		cur[dst] = cur[dst]->next;
		p = p->next;
	}
}
void backup()
{
	cur[3] = cur[1];
	clear(2);
	listcpy(1, 2);
}
void swaplist()
{
	clear(3);
	listcpy(2,3);
	clear(2);
	listcpy(1,2);
	clear(1);
	listcpy(3,1);
	cur[1]->next = cur[3]->next;
}
void push(char ch)
{
	cur[1]->next = new node(ch, cur[1], cur[1]->next);
	cur[1]->next->next->prev = cur[1]->next;
	cur[1] = cur[1]->next;
}
void Insert(int len, char str[])
{
	if (flag == OUT)backup();
	for (int i = 0; i < len; ++i)push(str[i]);
	flag = IN;
}
void Backspace(int len) {
	if (flag == IN)backup();
	while (len--) {
		node *p = cur[1]->prev;
		node *tmp = p->next;
		cur[1]->prev->next = cur[1]->next;
		cur[1]->next->prev = cur[1]->prev;
		cur[1] = cur[1]->prev;
		delete tmp;
		if (cur == head)break;
	}
	flag = OUT;
}

void Delete(int len) {
	if (flag == IN)backup();
	for (int i = 0; i < len; ++i) {
		if (cur[1]->next == tail[1])break;
		node *p = cur[1]->next;
		cur[1]->next = p->next;
		cur[1]->next->prev = p->prev;
		delete p;
	}
	flag = OUT;
}

void moveForward(int moveCnt) {
	while (moveCnt--) {
		cur[1] = cur[1]->prev;
		if (cur == head)break;
	}
}

void moveBackward(int moveCnt) {
	while (moveCnt--) {
		if (cur[1]->next == tail[1])break;
		cur[1] = cur[1]->next;
	}
	//cur[1] = tail[1]->prev;
}

void Undo() {
	flag ^= 1;
	swaplist();
}
void getString(int stPos, int len, char str[])
{
	node *pos = head[1]->next;
	while (stPos--)
		pos = pos->next;
	for (int i = 0; i < len; ++i) {
		str[i] = pos->ch;
		pos = pos->next;
		if (pos == tail[1])break;
	}
}