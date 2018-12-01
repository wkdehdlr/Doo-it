#ifndef NULL
#define NULL  0
#endif

struct Member {
	int id, frequency;
};

/// === submit area start ===
#define ID (S+id)
Member arr[100010];
const int S = 1 << 17;
const int MAX_ID = 100001;
const int MIN_ID = 100002;
int sum[2], cnt[2];

struct Tree {
	int maxid, minid;
	Tree() {
		this->maxid = MAX_ID;
		this->minid = MIN_ID;
	}
	Tree(int id) {
		this->maxid = this->minid = id;
	}
	Tree(int mx, int mn) {
		this->maxid = mx;
		this->minid = mn;
	}
	bool operator<(Tree t) {
		if (arr[minid].frequency != arr[t.minid].frequency)return arr[minid].frequency < arr[t.minid].frequency;
		else return minid < t.minid;
	}
	bool operator>(Tree t) {
		if (arr[maxid].frequency != arr[t.maxid].frequency)return arr[maxid].frequency > arr[t.maxid].frequency;
		else return maxid > t.maxid;
	}
}tree[2][S * 2];
void update(int d, int idx)
{
	if (idx < 1)return;
	tree[d][idx].maxid = tree[d][idx * 2] > tree[d][idx * 2 + 1] ? tree[d][idx * 2].maxid : tree[d][idx * 2 + 1].maxid;
	tree[d][idx].minid = tree[d][idx * 2] < tree[d][idx * 2 + 1] ? tree[d][idx * 2].minid : tree[d][idx * 2 + 1].minid;
	update(d, idx / 2);
}
void balance()
{
	int from, to;
	if (cnt[0] + 1 < cnt[1])from = 1;
	else if (cnt[1] + 1 < cnt[0])from = 0;
	else return;
	to = 1 - from;

	int id, fr;
	if (from)id = tree[from][1].minid;
	else id = tree[from][1].maxid;
	fr = arr[id].frequency;

	sum[from] -= fr; cnt[from]--;
	sum[to] += fr; cnt[to]++;

	tree[from][ID] = Tree();
	tree[to][ID] = Tree(id);
	update(from, ID / 2); update(to, ID / 2);
}
void addMember(Member obj) {
	int id, fr, d;
	id = obj.id; fr = obj.frequency;

	arr[id].id = id;
	arr[id].frequency = fr;

	Tree tmp(id);
	d = tmp > tree[0][1] ? 1 : 0;
	tree[d][ID] = Tree(id);
	update(d, ID / 2);
	sum[d] += fr;
	cnt[d]++;
	balance();
}

int removeMembers(int mode) {
	int id, fr, d;
	if (mode == 1) {
		if ((cnt[0] + cnt[1]) % 2) {//È¦¼ö
			if (cnt[0] < cnt[1]);
			else;
		}
		else {//Â¦¼ö

		}
	}
	if (mode == 0) { d = 0; id = tree[0][1].minid; fr = arr[id].frequency; }
	else if (mode == 2) { d = 1; id = tree[1][1].maxid; fr = arr[id].frequency; }

	sum[d] -= fr;
	cnt[d]--;
	tree[d][ID] = Tree();
	update(d, ID / 2);
	return id;
}

void getSum(int sum[]) {
}

void userInit(int memberCount, Member members[]) {
	sum[0] = sum[1] = cnt[0] = cnt[1] = 0;
	for (int i = 0; i <= 100000; ++i) {
		arr[i].id = arr[i].frequency = 0;
	}

	arr[MAX_ID].id = MAX_ID; arr[MAX_ID].frequency = -1;
	arr[MIN_ID].id = MIN_ID; arr[MIN_ID].frequency = 100000;

	for (int i = 0; i < S * 2; ++i) {
		tree[0][i] = tree[1][i] = Tree();
	}
	for (int i = 0; i < memberCount; ++i) {
		addMember(members[i]);
	}
}