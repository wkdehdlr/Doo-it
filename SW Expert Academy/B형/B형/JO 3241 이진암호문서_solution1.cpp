//#include<cstdio>
const int DOC_MAX_SIZE = 1 << 8;
const int DOC_SIZE = 1 << 7;

char rotate[DOC_SIZE][DOC_SIZE];
char vdsd[5][DOC_SIZE][DOC_SIZE];
char pd[DOC_MAX_SIZE][DOC_MAX_SIZE];
int chk[5], order[4], idx, len;
int dr[4] = { 0,0,1,1 };
int dc[4] = { 0,1,0,1 };
void userInit(int docSize)
{
	for (int i = 0; i < DOC_MAX_SIZE; ++i) {
		for (int j = 0; j < DOC_MAX_SIZE; ++j) {
			pd[i][j] = 0;
		}
	}
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < DOC_SIZE; ++i) {
			for (int j = 0; j < DOC_SIZE; ++j) {
				vdsd[k][i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		chk[i] = 0;
		if (i == 4)break;
		order[i] = 0;
	}
	idx = 0;
	len = docSize / 2;
}
void shuffleVDSD(char document[][DOC_MAX_SIZE])
{
	//printf("===========\n");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			vdsd[idx][i][j] = document[i][j];
			//printf("%d", vdsd[idx][i][j] ? 1 : 0);
		}
		//printf("\n");
	}
	idx++;
}
void rot(int val, char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (val == 0)rotate[i][j] = document[i][j];
			else if (val == 1)rotate[len - 1 - j][i] = document[i][j];
			else rotate[j][len - 1 - i] = document[i][j];
		}
	}
}
int set(char document[][DOC_MAX_SIZE])
{
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				pd[dr[k] * len + i][dc[k] * len + j] = vdsd[order[k]][i][j];
			}
		}
	}
	for (int r = 0; r <= len / 8; ++r) {
		for (int c = 0; c <= len / 8; ++c) {

			for (int k = 0; k < 3; ++k) {
				rot(k, document);
				int same = 0;
				for (int i = 0; i < len; ++i) {
					for (int j = 0; j < len; ++j) {
						if (pd[8 * r + i][8 * c + j] != rotate[i][j])same++;
					}
				}
				if (20 * same <= len * len)return 1;
			}
		}
	}
	return 0;
}
int dfs(int n, char document[][DOC_MAX_SIZE])
{
	if (n == 4) {
		if (set(document))return 1;
		return 0;
	}
	for (int i = 0; i < 5; ++i) {
		if (chk[i])continue;
		chk[i] = 1;
		order[n] = i;
		if (dfs(n + 1, document))return 1;
		chk[i] = 0;
	}
	return 0;
}
int verifyDocument(char document[][DOC_MAX_SIZE])
{
	for (int i = 0; i < 5; ++i) {
		chk[i] = 0;
		if (i == 4)break;
		order[i] = 0;
	}

	if (dfs(0, document))return 1;
	return 0;
}