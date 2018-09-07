
char op[11];
int st[11][55];
int res[55];
int A[55];
int B[55];
int idx = 0;
int top = 0;
void input(char ch, char *user)
{
	user[idx] = ch;
	idx++;
	for (int i = idx; i < 55; ++i)
		user[i] = '\0';
}
void init(char *user)
{
	top = 0;
	idx = 0;
	for (int i = 0; i < 55; ++i) {
		res[i] = A[i] = B[i] = 0;
		user[i] = '\0';
	}
	for (int i = 0; i < 11; ++i) {
		op[i] = '\0';
		for (int j = 0; j < 55; ++j)
			st[i][j] = 0;
	}
	user[0] = '0';
}
void encode(char *str1, int *str2)
{
	int i = 50;
	for (int j = idx - 1; j >= 0; --i, --j)
		str2[i] = str1[j] - '0';
	for (; i >= 0; --i)
		str2[i] = 0;
}
void decode(char *user, int *ary)
{
	int i = 0;
	while (i <= 50 && !ary[i])i++;
	if (i == 51)user[0] = '0';
	for (int j = 0; i <= 50; ++i, ++j)
		user[j] = ary[i] + '0';
}
void set(char ch, char *user)
{
	op[top++ ] = ch;
	for (int i = 0; i < idx; ++i)
		user[i] = '\0';
	idx = 0;
}
int chminus(int *ary1, int pos1, int *ary2, int pos2, int len2)
{
	for (int i = pos1, j = pos2; i <= pos1 + len2 - 1; ++i, ++j) {
		if (ary1[i] > ary2[j])break;
		else if (ary1[i] < ary2[j])return 0;
	}

	for (int i = pos1 + len2 - 1, j = 50; i >= pos1; --i, --j) {
		ary1[i] -= ary2[j];
		if (ary1[i] < 0) {
			ary1[i] += 10;
			ary1[i - 1]--;
		}
	}
	return 1;
}
void divide(int *ary1, int *ary2)
{
	int C[55] = { 0, };
	int len1 = 0, len2 = 0, i = 0;
	while (len1 <= 50 && !ary1[len1])len1++;
	while (len2 <= 50 && !ary2[len2])len2++;

	for (int j = len1; j <= len2; ++j, ++i) {
		while (chminus(ary1, j, ary2, len2, 51 - len2))C[i]++;
		ary1[j + 1] += ary1[j] * 10;
	}

	--i;
	int j = 50;
	for (; i >= 0; --i, --j)
		ary1[j] = C[i];
	for (; j >= 0; --j)
		ary1[j] = 0;
}
void multi(int *ary1, int *ary2)
{
	int C[110] = { 0, };
	int len1 = 0, len2 = 0;
	while (len1 <= 50 && !ary1[len1])len1++;
	while (len2 <= 50 && !ary2[len2])len2++;

	for (; len1 <= 50; ++len1) {
		for (int j = len2; j <= 50; ++j) {
			C[len1 + j] += ary1[len1] * ary2[j];
		}
	}
	for (int i = 100; i >= 50; --i) {
		if (C[i] >= 10) {
			C[i - 1] += C[i] / 10;
			C[i] %= 10;
		}
	}

	for (int i = 50; i <= 100; ++i)
		ary1[i - 50] = C[i];
}
void sub(int *ary1, int *ary2)
{
	int C[55] = { 0, };
	for (int i = 50; i >= 0; --i) {
		C[i] += (ary1[i] - ary2[i]);
		if (!i)break;
		if (C[i] < 0) {
			C[i] += 10;
			C[i - 1]--;
		}
	}

	for (int i = 0; i <= 50; ++i)
		ary1[i] = C[i];
}
void sum(int *ary1, int *ary2)
{
	int C[55] = { 0, };
	for (int i = 50; i >= 0; --i) {
		C[i] += (ary1[i] + ary2[i]);
		if (!i)break;
		if (C[i] >= 10) {
			C[i - 1] = C[i] / 10;
			C[i] %= 10;
		}
	}

	for (int i = 0; i <= 50; ++i)
		ary1[i] = C[i];
}
void process(int *ary1, int *ary2, char ch)
{
	switch (ch)
	{
	case '+':sum(ary1, ary2);
		break;
	case '-':sub(ary1, ary2);
		break;
	case '*':multi(ary1, ary2);
		break;
	case '/':divide(ary1, ary2);
		break;
	//case '=':if (op == '+')sum(ary1, ary2); else sub(ary1, ary2);
		//break;
	}
}
int check(char ch)
{
	if (ch == '+' || ch == '-') {
		if (op[top - 2] == '+' || op[top - 2] == '-')return 1;
		else return 2;
	}
	else {
		if (op[top - 2] == '+' || op[top - 2] == '-')return 0;
		else return 1;
	}
}
void reset()
{
	op[top - 2] = op[top - 1];
	--top;
}

void Cal(char ch, char user[]) {
	if (ch == 'C')init(user);
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=') {
		if (top && op[top - 1] == '=') {
			op[top - 1] = ch;
			return;
		}
		if (ch == '=') {
			encode(user, st[top]);
			while (top) {
				process(st[top - 1], st[top], op[top - 1]);
				--top;
			}
			set(ch, user);
			decode(user, st[top - 1]);
			return;
		}
		if (!top) {
			encode(user, st[top]);
			set(ch, user);
			decode(user, st[top - 1]);
		}
		else {
			encode(user, st[top]);
			set(ch, user);
			int ret = check(ch);
			if (ret == 1) {
				process(st[top - 2], st[top - 1], op[top - 2]);
				reset();
				decode(user, st[top - 1]);
				return;
			}
			else if (ret == 2) {
				while (top >= 2) {
					process(st[top - 2], st[top - 1], op[top - 2]);
					op[top - 2] = op[top - 1];
					--top;
				}
				decode(user, st[top - 1]);
				return;
			}
			decode(user, st[top - 1]);
		}
	}
	else {
		input(ch, user);
	}
}