#pragma warning(disable : 4996)
#include<cstdio>
#define MXID 100001
#define MNID 100002
int fre[100015];

struct Tree {
	int maxid, minid;
	Tree() {
		this->maxid = MXID;
		this->minid = MNID;
	}
	Tree(int id) {
		this->maxid = this->minid = id;
	}
	bool operator<(Tree t) {
		if (fre[this->minid] != fre[t.minid]) return fre[this->minid] < fre[t.minid];
		return this->minid < t.minid;
	}
	bool operator>(Tree t) {
		if (fre[this->maxid] != fre[t.maxid])return fre[this->maxid] > fre[t.maxid];
		return this->maxid > t.maxid;
	}
}tree[1 << 18];
int k = 1 << 17;
int ret = 0, cnt = 0;
void update(int idx)
{
	if (idx < 1)return;
	tree[idx].minid = tree[idx * 2] < tree[idx * 2 + 1] ? tree[idx * 2].minid : tree[idx * 2 + 1].minid;
	tree[idx].maxid = tree[idx * 2] > tree[idx * 2 + 1] ? tree[idx * 2].maxid : tree[idx * 2 + 1].maxid;
	update(idx / 2);
}
void input()
{
	int id, frcy;
	scanf("%d %d", &id, &frcy);
	fre[id] = frcy;
	ret += frcy;
	cnt++;
	tree[id + k] = Tree(id);
	update((id + k) / 2);
}
void delmin()
{
	if (!cnt)return;
	int id = tree[1].minid;
	printf("%d\n", id);
	ret -= fre[id];
	cnt--;
	tree[id + k] = Tree();
	update((id + k) / 2);
}
void delmax()
{
	if (!cnt)return;
	int id = tree[1].maxid;
	printf("%d\n", id);
	ret -= fre[id];
	cnt--;
	tree[id + k] = Tree();
	update((id + k) / 2);
}
void output()
{
	if (cnt <= 2)printf("0\n");
	else printf("%d\n", ret - fre[tree[1].maxid] - fre[tree[1].minid]);
}
int N, M;
int main()
{
	fre[MXID] = -1;
	fre[MNID] = 99999;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 0:input(); break;
		case 1:delmin(); break;
		case 2:delmax(); break;
		case 3:output(); break;
		}
	}
}