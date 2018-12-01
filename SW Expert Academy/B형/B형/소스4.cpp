#ifndef NULL
#define NULL 0
#endif
/*int strcmp(const char*s, const char*t) {
while (*s && *s == *t)++s, ++t;
return *s - *t;
}
void strcpy(char *dest, char *src) {
while (*dest++ = *src++);
}
*/
int prefix(const char*s, const char*t) {
	while (*s && *s == *t)++s, ++t;
	return *s == 0;
}

struct node {
	char name[15];
	node *next, *child, *parent;
	node() {
		strcpy(this->name, "91");
		this->next = '\0';
		this->child = '\0';
		this->parent = '\0';
	}
	node(char name[], node *next, node *child, node *parent) {
		strcpy(this->name, name);
		this->next = next;
		this->child = child;
		this->parent = parent;
	}
}*root, *cur;

int del_all(node *p)
{
	int cnt = 0;
	while (p->next) {
		cnt += del_all(p->next->child) + 1;
		delete p->next->child;
		node *tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
	return cnt;
}
void init_user() {

	if (root)del_all(root->child);
	else root = new node("root", NULL, new node(), NULL);
	root->parent = root;
	cur = root;
}



void Add_child(char name[]) {
	node *p = cur->child;
	while (p->next && strcmp(p->next->name, name) < 0)p = p->next;
	if (!(p->next)) {
		p->next = new node(name, NULL, new node(), cur);
	}
	else {
		if (strcmp(p->next->name, name) == 0)return;
		else p->next = new node(name, p->next, new node(), cur);
	}
}

/// name[]이 "ALL"인 경우에는 현재 멤버의 모든 자식을 그 후손들과 함꼐 제거하고 그 수를 반환한다.

/// 그렇지 않은 경우 name[]으로 시작하는 모든 자식을 찾아 그 후손들과 함께 제거하고 그 수를 반환한다.

int del(node* p, char name[])
{
	int cnt = 0;
	while (p->next) {
		if (prefix(name, p->next->name) == 1) {
			cnt += del_all(p->next->child) + 1;
			delete p->next->child;
			node *tmp = p->next;
			p->next = tmp->next;
			delete tmp;
		}
		else p = p->next;
	}
	return cnt;
}

int Delete(char name[]) {
	if (strcmp(name, "ALL") == 0)return del_all(cur->child);
	else return del(cur->child, name);
}



/// name[]이 "root"인 경우에는 최상위(root)로 이동한다.

/// name[]이 "parent"인 경우에는 부모 노드로 이동한다.​

/// name[]이 "first"인 경우에는 사전순으로 가장 빠른 이름을 가진 자식 노드로 이동한다.

/// 그렇지 않은 경우 name[]으로 시작하는 사전순으로 가장 빠른 이름을 가진 자식 노드로 이동한다.​

void Move(char name[]) {
	if (strcmp(name, "root") == 0)cur = root;
	else if (strcmp(name, "parent") == 0 && cur->parent)cur = cur->parent;
	else if (strcmp(name, "first") == 0 && cur->child->next)cur = cur->child->next;
	else {
		node *p = cur->child;
		while (p->next) {
			if (prefix(name, p->next->name) == 1) {
				cur = p->next;
				return;
			}
			else p = p->next;
		}
	}
}



/// name[]이 "ALL"인 경우에는 현재 멤버의 자식을 포함한 모든 후손들의 수를 반환한다.

/// 그렇지 않은 경우 현재멤버의 자식을 포함한 모든 후손들 중에 name[]으로 시작하는 후손들의 수를 반환한다.

int count_all(node *p)
{
	int cnt = 0;
	while (p->next) {
		cnt += count_all(p->next->child) + 1;
		p = p->next;
	}
	return cnt;
}
int count(node *p, char name[])
{
	int cnt = 0;
	while (p->next) {
		if (prefix(name, p->next->name) == 1)cnt++;
		cnt += count(p->next->child, name);
		p = p->next;
	}
	return cnt;
}
int Count(char name[]) {
	if (strcmp(name, "ALL") == 0)return count_all(cur->child);
	else return count(cur->child, name);
}