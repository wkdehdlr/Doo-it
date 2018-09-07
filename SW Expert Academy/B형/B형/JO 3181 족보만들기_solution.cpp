int my_strncmp(char *str1, char *str2, int len)
{
	unsigned char *ps1, *ps2;
	int i;
	ps1 = (unsigned char *)str1;
	ps2 = (unsigned char *)str2;

	for (i = 0; i < len; i++)
	{
		if ((*ps1) != (*ps2))
		{
			if ((*ps1) >(*ps2))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if ((*ps1) == 0)
		{
			return 0;
		}
		*ps1++;
		*ps2++;
	}
	return 0;
}
int my_strcmp(char *str1, char *str2)
{
	unsigned char *ps1, *ps2;

	ps1 = (unsigned char *)str1;
	ps2 = (unsigned char *)str2;
	for (;;)
	{
		if ((*ps1) != (*ps2))
		{
			if ((*ps1) > (*ps2))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if ((*ps1) == 0)
		{
			return 0;
		}
		*ps1++;
		*ps2++;
	}
}

struct data {
	char name[15];
	data *parent, *child, *next;
	data() {
		parent = child = next = '\0';
	}

	data(char *name, data *parent, data *child, data *next) {
		strcpy(this->name, name);
		this->parent = parent;
		this->child = child;
		this->next = next;
	}
};
data *root, *cur;


void Add_child(char name[])
{
	data *p = cur->child;
	while (p->next && my_strcmp(p->next->name, name) < 0)p = p->next;
	if (p->next && my_strcmp(p->next->name, name) == 0)return;
	p->next = new data(name, cur, new data(), p->next);
}

int del_all(data *p)
{
	int cnt = 0;
	while (p->next) {
		cnt += del_all(p->next->child) + 1;
		delete p->next->child;
		data *tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
	return cnt;
}

int del(char *name)
{
	int cnt = 0;
	int len = strlen(name);
	data *p = cur->child;
	while (p->next) {
		if (my_strncmp(p->next->name, name, len)==0) {
			cnt += del_all(p->next->child) + 1;
			data *tmp = p->next;
			p->next = tmp->next;
			delete tmp->child;
			delete tmp;
		}
		else p = p->next;
	}
	return cnt;
}
int Delete(char name[])
{
	if (my_strcmp(name, "ALL") == 0)return del_all(cur->child);
	else return del(name);
}

void Move(char name[])
{
	if (my_strcmp(name, "root") == 0)cur = root;
	else if (my_strcmp(name, "parent") == 0)cur = cur->parent;
	else if (my_strcmp(name, "first") == 0 && cur->child->next)cur = cur->child->next;
	else {
		int len = strlen(name);
		data *p = cur->child;
		while (p->next) {
			if (my_strncmp(p->next->name, name, len)==0) {
				cur = p->next;
				break;
			}
			p = p->next;
		}
	}
}
int count(data *p, char *name, int len)
{
	int cnt = 0;
	while (p->next) {
		if (my_strncmp(p->next->name, name, len) == 0)cnt++;
		cnt += count(p->next->child, name, len);
		p = p->next;
	}
	return cnt;
}
int ccount(data *p)
{
	int cnt = 0;
	while (p->next) {
		cnt += ccount(p->next->child) + 1;
		p = p->next;
	}
	return cnt;
}
int Count(char name[])
{
	int len = strlen(name);
	if (my_strcmp(name, "ALL") == 0)return ccount(cur->child);
	else return count(cur->child, name, len);
}
void init_user()
{
	if (root) {
		del_all(root->child);
	}
	else {
		root = new data("root", NULL, new data(), NULL);
	}
	root->parent = root;
	cur = root;
}