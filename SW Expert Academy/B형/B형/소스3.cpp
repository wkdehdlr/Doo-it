#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
struct data {
	char id[12];
	char pw[12];
	int tick;
	data *next;
	data(char *id, char *pw, int tick, data *next) {
		strcpy(this->id, id);
		strcpy(this->pw, pw);
		this->tick = tick;
		this->next = next;
	}
	data(char *id, data *next) {
		strcpy(this->id, id);
		this->next = next;
	}
}*member;
void pop(data *p)
{
	data *tmp= p;
	*p = *(tmp->next);
	delete tmp;

}
int main()
{
	member = new data("장도익", "123", 0, member);
	member = new data("홍길동", "123", 0, member);
	pop(member);
	return 0;
}