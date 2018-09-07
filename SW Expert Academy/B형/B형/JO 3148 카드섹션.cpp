#pragma warning(disable : 4996)
#include<cstdio>

struct MAP {
	int id;
	char color;
	MAP *next;
	MAP(int id, char color, MAP *next) {
		this->id = id;
		this->color = color;
		this->next = next;
	}
} *map[1010][1010];

struct data {
	int r, c, w, h;
	char color[1650];
} arr[10001];
int T, N, M, r, c, w, h, num, id;
char color[1650];
void pop(int r, int c)
{
	MAP *tmp = map[r][c];
	map[r][c] = tmp->next;
	delete tmp;
}
void find(int r, int c, int id)
{
	if (map[r][c]->id == id) {
		pop(r, c);
	}
	else {
		MAP *p = map[r][c];
		while (p->next) {
			if (p->next->id == id) {
				MAP *tmp = p->next;
				p->next = tmp->next;
				delete tmp;
				break;
			}
			p = p->next;
		}
	}
}
void del(int id)
{
	for (int i = 0; i < arr[id].w; ++i) {
		for (int j = 0; j < arr[id].h; ++j) {
			find(arr[id].r + i, arr[id].c + j, id);
		}
	}
}
void push(int r, int c, int id, char color)
{
	map[r][c] = new MAP(id, color, map[r][c]);
}

void set(int id)
{
	int k = 0;
	for (int i = 0; i < arr[id].w; ++i) {
		for (int j = 0; j < arr[id].h; ++j) {
			push(arr[id].r + i, arr[id].c + j, id, arr[id].color[k++]);
		}
	}
}
void output(int r, int c)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (map[r + i][c + j])printf("%c", map[r + i][c + j]->color);
			else printf("0");
		}
	}
	printf("\n");
}
void reset()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			while (map[r][c])pop(r, c);
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &num);
			switch (num)
			{
			case 1:scanf("%d", &id); scanf("%d %d %d %d %s", &arr[id].r, &arr[id].c, &arr[id].w, &arr[id].h, arr[id].color);
				set(id);
				break;
			case 2:scanf("%d", &id);
				del(id);
				break;
			case 3:scanf("%d", &id);
				del(id);
				set(id);
				break;
			case 4:scanf("%d", &id);
				del(id);
				scanf("%d %d", &arr[id].r, &arr[id].c);
				set(id);
				break;
			case 5:scanf("%d %d", &r, &c);
				output(r, c);
				break;
			}
		}
		reset();
	}
}