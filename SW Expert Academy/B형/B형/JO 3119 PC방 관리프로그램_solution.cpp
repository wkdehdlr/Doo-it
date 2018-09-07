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
/// 사용자의 코드를 초기화 한다.
/// 매 테스트 케이스마다 한번 호출 된다.

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

/// PC방에 온 새로운 손님이 회원가입하는 경우 등록하고 기본이용시간을 제공한다.
/// 현재 접속되어 있는 회원수를 반환한다.
/// 기존 회원과 identity가 같은 회원이 입력되지 않으며 최대 50000번 호출 될 수 있다.


int joinGuest(char* identity, char  *password)
{
	member = new data(identity, password, bt, member);
	login = new data(identity, password, bt, login);
	login_cnt++;
	return login_cnt;
}

/// id가 identity인 손님이 로그 아웃을 요청한 경우 처리하는 코드이다.
/// 이미 로그 아웃된 id가 입력될 수 있다.
/// 현재 접속되어 있는 회원수를 반환한다.

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

/// 1. 현재 로그인된 회원이고(identity가 등록되어 있고 로그인됨) password가 맞는다면
///    손님의 이용시간을 baseTick으로 초기화하고 현재 접속되어 있는 회원수를 반환한다.
/// 2. 이미 회원가입이 된 회원이고(identity가 등록됨) password가 맞는다면
///    손님의 이용시간을 baseTick으로 초기화하고 현재 접속되어 있는 회원수를 반환한다.
/// 3. 가입된 회원이 아니거나 password가 맞지 않다면 현재 접속되어 있는 회원수를 반환한다.
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

/// 모든 로그인된 손님의 tick을 1 줄인다.
/// 남은 시간이 0인 사용자를 일괄 로그아웃 시키고 이때 로그아웃된 손님의 수를 반환한다.

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

/// 현재 접속되어 있는 회원수를 반환한다.
/// 매 테스트 케이스마다  1번 호출된다.

int remainGuest()
{
	return login_cnt;
}