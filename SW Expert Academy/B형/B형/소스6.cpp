struct node {
	int num;
	node *next;
	node(int num, node *next) {
		this->num = num;
		this->next = next;
	}
} *map[1000][1000];

void push(int r, int c, int num) {
	map[r][c] = new node(num, map[r][c]);
}

void func() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			arr[i / 2][j / 2] = arr[i / 2][j / 2] * 2 + map[i][j];
		}
	}
}