#ifndef NULL
#define NULL 0
#endif // NULL

void my_strcpy(char *str1, char *str2)
{
	for (int i = 0; i < 12; ++i)str1[i] = str2[i];
}
int my_strlen(char *str)
{
	int i = 0;
	while (str[i])i++;
	return i;
}
int my_strcmp(char *str1, char *str2)
{
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	if (len1 != len2)return 1;
	for (int i = 0; i < len1; ++i) {
		if (str1[i] != str2[i])return 1;
	}
	return 0;
}
struct data {
	char id[12];
	char ps[12];
	int tick;
	data *next;
	data(char *id, char *ps, int tick, data *next) {
		my_strcpy(this->id, id);
		my_strcpy(this->ps, ps);
		this->tick = tick;
		this->next = next;
	}
	data(char *id, char *ps, data *next) {
		my_strcpy(this->id, id);
		my_strcpy(this->ps, ps);
		this->tick = 0;
		this->next = next;
	}
} *member, *login, *logout;
int login_cnt;
int bt;
/// ������� �ڵ带 �ʱ�ȭ �Ѵ�.
/// �� �׽�Ʈ ���̽����� �ѹ� ȣ�� �ȴ�.

void pop(int n)
{
	data *tmp;
	switch (n)
	{
	case 1:tmp = member;
		member = tmp->next;
		delete tmp;
		break;
	case 2:tmp = login;
		login = tmp->next;
		delete tmp;
		break;
	case 3:tmp = logout;
		logout = tmp->next;
		delete tmp;
		break;
	}
}
void del(data *p, char *id)
{
	if (p && my_strcmp(p->id, id) == 0) {
		pop(2);
		return;
	}
	else {
		while (p->next) {
			if (my_strcmp(p->next->id, id) == 0) {
				data *tmp = p->next;
				p->next = tmp->next;
				delete tmp;
				break;
			}
			p = p->next;
		}
	}
}
void initUser(int baseTick)
{
	while (member)pop(1);
	while (login)pop(2);
	while (logout)pop(3);
	bt = baseTick;
	login_cnt = 0;
}

/// PC�濡 �� ���ο� �մ��� ȸ�������ϴ� ��� ����ϰ� �⺻�̿�ð��� �����Ѵ�.
/// ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.
/// ���� ȸ���� identity�� ���� ȸ���� �Էµ��� ������ �ִ� 50000�� ȣ�� �� �� �ִ�.


int joinGuest(char* identity, char  *password)
{
	member = new data(identity, password, bt, member);
	login = new data(identity, password, bt, login);
	login_cnt++;
	return login_cnt;
}

/// id�� identity�� �մ��� �α� �ƿ��� ��û�� ��� ó���ϴ� �ڵ��̴�.
/// �̹� �α� �ƿ��� id�� �Էµ� �� �ִ�.
/// ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.

bool check(data *p, char *id)
{
	while (p) {
		if (my_strcmp(p->id, id) == 0) {
			return true;
			break;
		}
		p = p->next;
	}
	return false;
}
int logoutGuest(char *identity)
{
	if (check(logout, identity))return login_cnt;
	else {
		logout = new data(identity, "null", 0, logout);
		//push(logout, identity, NULL, 0);
		del(login, identity);
		login_cnt--;
		return login_cnt;
	}
}

/// 1. ���� �α��ε� ȸ���̰�(identity�� ��ϵǾ� �ְ� �α��ε�) password�� �´´ٸ�
///    �մ��� �̿�ð��� baseTick���� �ʱ�ȭ�ϰ� ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.
/// 2. �̹� ȸ�������� �� ȸ���̰�(identity�� ��ϵ�) password�� �´´ٸ�
///    �մ��� �̿�ð��� baseTick���� �ʱ�ȭ�ϰ� ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.
/// 3. ���Ե� ȸ���� �ƴϰų� password�� ���� �ʴٸ� ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.
int check2(data *p, char *id, char *ps)
{
	while (p) {
		if (my_strcmp(p->id, id) == 0 && my_strcmp(p->ps, ps) == 0) {
			p->tick = bt;
			return 1;
		}
		p = p->next;
	}
	return 0;
}
int check3(data *p, char *id, char *ps)
{
	while (p) {
		if (my_strcmp(p->id, id) == 0 && my_strcmp(p->ps, ps) == 0) {
			return 1;
		}
		p = p->next;
	}
	return 0;
}
int contactGuest(char*identity, char*password)
{
	if (check3(member,identity,password) && check2(login, identity, password))return login_cnt;
	if (check2(member, identity, password)) {
		login = new data(identity, password, bt, login);
		login_cnt++;
		return login_cnt;
	}

	return login_cnt;
}

/// ��� �α��ε� �մ��� tick�� 1 ���δ�.
/// ���� �ð��� 0�� ����ڸ� �ϰ� �α׾ƿ� ��Ű�� �̶� �α׾ƿ��� �մ��� ���� ��ȯ�Ѵ�.

int reduceTick()
{
	int cnt = 0;
	data *p = login;
	while (p) {
		if (p->tick == 1) {
			logout = new data(p->id, "null", 0, logout);
			//push(logout, p->id, NULL, 0);
			pop(2);
			cnt++;
			login_cnt--;
		}
		else {
			(p->tick)--;
			break;
		}
	}
	while (p->next) {
		if (p->next->tick == 1) {
			logout = new data(p->next->id, "null", 0, logout);
			//push(logout, p->next->id, NULL, 0);
			data *tmp = p->next;
			p->next = tmp->next;
			delete tmp;
			cnt++;
			login_cnt--;
		}
		else {
			(p->next->tick)--;
			p = p->next;
		}
	}
	return cnt;
}

/// ���� ���ӵǾ� �ִ� ȸ������ ��ȯ�Ѵ�.
/// �� �׽�Ʈ ���̽�����  1�� ȣ��ȴ�.

int remainGuest()
{
	return login_cnt;
}