#include<cstdio>
#define INPUT 1
#define BACKSPACE 2
#define DELETE 3
#define FORWARD 4
#define BACKWARAD 5
#define UNDO 6
#define GETSTRING 7

int op[100001];
int idx;
struct node {
	char ch;
	node *prev, *next;
	node() {
		ch = 'h';
		prev = next = NULL;
	}
	node(char ch, node *prev, node *next) {
		this->ch = ch;
		this->prev = prev;
		this->next = next;
	}
}*head, *tail, *cur;

void initUser()
{
	head = new node();
	tail = new node();
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	cur = head;

	for (; idx >= 0; --idx)op[idx] = 0;
	idx = 0;
}
void push(char ch)
{
	cur->next = new node(ch, cur, cur->next);
	cur->next->next->prev = cur->next;
	cur = cur->next;
}
void Insert(char str[])
{
	op[idx++] = INPUT;
	for (int i = 0; str[i]; ++i)
		push(str[i]);
	
}
void del_front()
{
	if (cur == head)return;
	node *p = cur->prev;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	cur = cur->prev;
	delete p->next;
}
void del_back()
{
	if (cur->next == tail)return;
	cur = cur->next;
	del_front();
}
void Backspace(int count)
{
	op[idx++] = BACKSPACE;
	for (int i = 0; i < count; ++i)del_front();
}
void Delete(int count)
{
	op[idx++] = DELETE;
	for (int i = 0; i < count; ++i)del_back();
}
void moveForward(int moveCnt)
{
	op[idx++] = FORWARD;
	for (int i = 0; i < moveCnt; ++i) {
		if (cur == head)return;
		cur = cur->prev;
	}
}
void moveBackward(int moveCnt)
{
	op[idx++] = BACKWARAD;
	for (int i = 0; i < moveCnt; ++i) {
		if (cur == tail)return;
		cur = cur->next;
	}
}
void Undo()
{
	if (op[idx - 1] == INPUT || op[idx - 2] == INPUT) {

	}
	if ((op[idx - 1] == DELETE || op[idx - 1] == BACKSPACE) && (op[idx - 2] == DELETE || op[idx - 2] == BACKSPACE)){

	}
	op[idx++] = UNDO;
}
void getString(int stPos, int len, char str[])
{
	op[idx++] = GETSTRING;
	node *p = head->next;
	for (int i = 0; i < stPos; ++i)p = p->next;
	for (int i = 0; i < len; ++i) {
		str[i] = p->ch;
		p = p->next;
	}
}