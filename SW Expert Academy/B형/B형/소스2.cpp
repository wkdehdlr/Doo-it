void my_strcpy(char *str1, char *str2)
{
	int idx = 0;
	while (str2[idx]) {
		str1[idx] = str2[idx];
		idx++;
	}
	str1[idx] = '\0';
}
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
int my_strlen(char *name)
{
	int idx = 0;
	while (name[idx])idx++;
	return idx;
}

struct data
{
	char name[13];
	data *parent, *next, *child;
	data() {
		parent = next = child = NULL;
	}
	data(char na[], data *pa, data *ne, data *ch) {
		my_strcpy(name, na), parent = pa, next = ne, child = ch;
	}
} *root, *cur;


int del_all(data *p)
{
	int cnt = 0;
	while (p->next != NULL) {
		cnt += del_all(p->next->child) + 1;
		delete p->next->child;
		data *tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
	return cnt;
}

void init_user()
{
	if (root) del_all(root->child);
	else 	root = cur = new data("root", NULL, NULL, new data());
	root->parent = root;
	cur = root;
}

void Add_child(char name[])
{
	data *p = cur->child;
	while (p->next != NULL && my_strcmp(p->next->name, name) < 0)
		p = p->next;
	if (p->next != NULL && my_strcmp(p->next->name, name) == 0)
		return;
	p->next = new data(name, cur, p->next, new data());
}

int del_find(data *p, char name[])
{
	int cnt = 0, len = my_strlen(name);
	if (p->next == NULL || my_strncmp(p->next->name, name, len) > 0)
		return 0;
	cnt += del_find(p->next, name);
	if (my_strncmp(p->next->name, name, len) == 0) {
		data *tmp = p->next;
		cnt += del_all(tmp->child) + 1;
		p->next = tmp->next;
		delete tmp->child;
		delete tmp;
	}
	return cnt;
}

int Delete(char name[])
{
	if (my_strcmp(name, "ALL") == 0) return del_all(cur->child);
	return del_find(cur->child, name);
}


void Move(char name[])
{
	if (my_strcmp(name, "root") == 0) cur = root;
	else if (my_strcmp(name, "parent") == 0) cur = cur->parent;
	else if (cur->child->next != NULL) {
		data *p = cur->child->next;
		if (my_strcmp(name, "first") == 0) cur = p;
		else {
			int len = my_strlen(name);
			while (p->next != NULL && my_strcmp(p->name, name) < 0)
				p = p->next;
			if (my_strncmp(p->name, name, len) == 0) cur = p;
		}
	}
}

int count(data *p, char name[]) {
	if (p == NULL) return 0;
	int len = my_strlen(name);
	int cnt = count(p->next, name) + count(p->child->next, name);
	if (my_strncmp(p->name, name, len) == 0) cnt++;
	return cnt;
}

int Count(char name[])
{
	if (my_strcmp(name, "ALL") == 0) name[0] = 0;
	return count(cur->child->next, name);
}