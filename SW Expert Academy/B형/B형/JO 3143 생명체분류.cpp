#pragma warning(disable : 4996)
#include<cstdio>


struct Trie {
	int cnt = 0;
	Trie *next[26];
	Trie() {
		for (int i = 0; i < 26; ++i)next[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)if (next[i])delete next[i];
	}
	void insert(char *p)
	{
		cnt++;
		if (!p[0])return;
		int idx = p[0] - 'A';
		if (!next[idx])next[idx] = new Trie();
		next[idx]->insert(p + 1);
	}
	int search(char *p)
	{
		if (!p[0])return cnt;
		int idx = p[0] - 'A';
		if (!next[idx])return 0;
		return next[idx]->search(p + 1);
	}
};
int T,N;
char str[30], ch;
int main()
{
	scanf("%d", &T);
	while (T--) {
		Trie *trie = new Trie();
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf(" %c %s", &ch, str);
			if (ch == 'I')trie->insert(str);
			else printf("%d ", trie->search(str));
		}
		printf("\n");
		delete trie;
	}
}