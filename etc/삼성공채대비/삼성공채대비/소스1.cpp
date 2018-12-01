#include<stdio.h>




int map[52][52];
bool visit[52][52];

int min = 1000000000;
int N;
void greedy2_dfs(int pre_x, int pre_y, int x, int y, int depth);
void greedy_dfs(int pre_x, int pre_y, int x, int y, int depth);
void dfs(int pre_x, int pre_y, int x, int y, int depth);



int main()
{
	int i, j, k, t, tc, input;

	//freopen("eval_input.txt", "r", stdin);

	scanf("%d", &t);
	for (tc = 1; tc <= t; tc++) {

		min = 100000000;
		scanf("%d", &N);
		for (i = 0; i <= N + 1; i++) {
			for (j = 0; j <= N + 1; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		map[N][N + 1] = 1;
		map[1][0] = 1;

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		greedy_dfs(N, N + 1, N, N, 1);
		for (i = 0; i <= N + 1; i++) {
			for (j = 0; j <= N + 1; j++) {

				visit[i][j] = 0;
			}
		}
		//  dfs(N, N + 1, N, N, 1);
		printf("#%d %d\n", tc, min - 1);
	}

	return 0;
}





void dfs(int pre_x, int pre_y, int x, int y, int depth) {
	int next_x, next_y;
	int optimal;
	int check;



	if (x == 1 && y == 0) {
		if (min > depth) {
			min = depth;
		}
		return;
	}
	if (map[x][y] < 3) {
		//type 1,2
		if (pre_y == y) {
			// type == 2
			if (pre_x == x - 1) {
				next_x = x + 1;
			}
			else if (pre_x == x + 1) {
				next_x = x - 1;
			}
			next_y = y;
		}
		else if (pre_x == x) {
			// type == 1
			if (pre_y == y - 1) {
				next_y = y + 1;
			}
			else if (pre_y == y + 1) {
				next_y = y - 1;
			}
			next_x = x;
		}
		if (next_x != -1) {
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;
				dfs(x, y, next_x, next_y, depth + 1);
				visit[next_x][next_y] = 0;
			}
		}
	}
	else if (map[x][y] > 2) {
		check = 0;
		//type 3, 4, 5, 6
		if (pre_x == x) {
			next_y = y;
			next_x = x - 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;
				dfs(x, y, next_x, next_y, depth + 1);
				visit[next_x][next_y] = 0;
				check = 1;
			}

			next_x = x + 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) < min) {
				visit[next_x][next_y] = 1;

				dfs(x, y, next_x, next_y, depth + 1);

				visit[next_x][next_y] = 0;
			}

		}
		else if (pre_y == y) {
			next_x = x;
			next_y = y - 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;

				dfs(x, y, next_x, next_y, depth + 1);

				visit[next_x][next_y] = 0;
				check = 1;
			}

			next_y = y + 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) < min) {
				visit[next_x][next_y] = 1;

				dfs(x, y, next_x, next_y, depth + 1);

				visit[next_x][next_y] = 0;
			}

		}

	}




}



void greedy_dfs(int pre_x, int pre_y, int x, int y, int depth) {
	int next_x, next_y;
	int optimal;
	int check;




	if (x == 1 && y == 0) {
		if (min > depth) {
			min = depth;
		}
		return;
	}




	if (map[x][y] < 3) {
		//type 1,2
		if (pre_y == y) {
			// type == 2
			if (pre_x == x - 1) {
				next_x = x + 1;
			}
			else if (pre_x == x + 1) {
				next_x = x - 1;
			}
			next_y = y;
		}
		else if (pre_x == x) {
			// type == 1
			if (pre_y == y - 1) {
				next_y = y + 1;
			}
			else if (pre_y == y + 1) {
				next_y = y - 1;
			}
			next_x = x;
		}
		if (next_x != -1) {
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;
				dfs(x, y, next_x, next_y, depth + 1);
				visit[next_x][next_y] = 0;
			}
		}
	}
	else if (map[x][y] > 2) {
		check = 0;
		//type 3, 4, 5, 6
		if (pre_x == x) {
			next_y = y;
			next_x = x - 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;
				dfs(x, y, next_x, next_y, depth + 1);
				visit[next_x][next_y] = 0;
				check = 1;
			}
			if (check == 0) {
				next_x = x + 1;
				if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) < min) {
					visit[next_x][next_y] = 1;

					dfs(x, y, next_x, next_y, depth + 1);

					visit[next_x][next_y] = 0;
				}
			}
		}
		else if (pre_y == y) {
			next_x = x;
			next_y = y - 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) <min) {
				visit[next_x][next_y] = 1;

				dfs(x, y, next_x, next_y, depth + 1);

				visit[next_x][next_y] = 0;
				check = 1;
			}
			//  if (check == 0){
			next_y = y + 1;
			if (map[next_x][next_y] != 0 && visit[next_x][next_y] == 0 && (next_x + next_y + depth) < min) {
				visit[next_x][next_y] = 1;

				dfs(x, y, next_x, next_y, depth + 1);

				visit[next_x][next_y] = 0;
			}
			//}
		}

	}




}