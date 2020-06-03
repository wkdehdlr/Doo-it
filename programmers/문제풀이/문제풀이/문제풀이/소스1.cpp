#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int n, m;
int arr[65][65];
int tmp[65][65];

int nk1[25][25];
int nk2[25][25];
int nk3[25][25];
int nk4[25][25];



void rotate(vector<vector<int>> key) {
	for (int k = 0; k < 4; ++k) {
		if (k == 0) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					nk1[i][j] = key[i][j];
				}
			}
		}
		else if (k == 1) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					nk2[j][m - 1 - i] = key[i][j];
				}
			}
		}
		else if (k == 2) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					nk3[m - 1 - i][m - 1 - j] = key[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					nk4[m - 1 - j][i] = key[i][j];
				}
			}
		}
	}
}
bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (tmp[i + m - 1][j + m - 1] == 0 || tmp[i + m - 1][j + m - 1] == 2)return false;
		}
	}
	return true;
}
void init() {
	for (int i = 0; i < 65; ++i) {
		for (int j = 0; j < 65; ++j) {
			tmp[i][j] = arr[i][j];
		}
	}
}
bool func2(int k, int i, int j) {
	if (k == 0) {
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < m; ++c) {
				tmp[i + r][c + j] = nk1[r][c] + tmp[i + r][c + j];
			}
		}
	}
	else if (k == 1) {
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < m; ++c) {
				tmp[i + r][c + j] = nk2[r][c] + tmp[i + r][c + j];
			}
		}
	}
	else if (k == 2) {
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < m; ++c) {
				tmp[i + r][c + j] = nk3[r][c] + tmp[i + r][c + j];
			}
		}
	}
	else {
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < m; ++c) {
				tmp[i + r][c + j] = nk4[r][c] + tmp[i + r][c + j];
			}
		}
	}
	return true;
}
bool func() {
	for (int i = 0; i < n + m - 2; ++i) {
		for (int j = 0; j < n + m - 2; ++j) {

			for (int k = 0; k < 4; ++k) {
				init();
				if (!func2(k, i, j))continue;;
				if (check())return true;
			}
		}
	}
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	n = lock.size();
	m = key.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i + m - 1][j + m - 1] = tmp[i + m - 1][j + m - 1] = lock[i][j];
		}
	}
	rotate(key);
	return func();
}

int main() {
	vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	bool res = solution(key, lock);
	return 0;
}