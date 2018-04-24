#define N 4

bool done;
int idx = 0;
int arr[5040][N];
bool visited2[5040];
int tmp[N];
bool visited[10];
bool digits[10];


extern Data query(int supose[]);
// API
Data my_query(int idx, int i)
{
	Data result;
	result.strike = 0;
	result.ball = 0;

	for (int j = 0; j < N; ++j)
		if (arr[idx][j] == arr[i][j])
			result.strike++;
		else if (digits[arr[i][j]])
			result.ball++;

	return result;
}
void init()
{
	idx = 0;
	for (int i = 0; i < 5040; ++i)
		visited2[i] = false;
	for (int i = 0; i < 10; ++i)
		visited[i] = false;
}
void DFS(int dep)
{
	if (dep == 4)
	{
		for (int i = 0; i < 4; ++i)
			arr[idx][i] = tmp[i];
		idx++;
	}
	else
	{
		for (int i = 0; i <= 9; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				tmp[dep] = i;
				DFS(dep + 1);
				visited[i] = false;
			}
		}
	}
}
bool check(int k)
{
	for (int i = 0; i < 4; ++i)
	{
		if (visited[arr[k][i]])return true;
	}
	return false;
}
void go2(int idx, int s, int b)
{
	for (int i = 0; i < 5040; ++i)
	{
		if (visited2[i])continue;
		Data res = my_query(idx, i);
		if (!(res.strike == s && res.ball == b))
			visited2[i] = true;
	}
}
void go(int guess[])
{
	for (int i = 0; i < 5040; ++i)
	{
		if (visited2[i] || check(i)) continue;
		Data res = query(arr[i]);
		if (res.strike == 4)//찾음
		{
			for (int j = 0; j < 4; ++j)
				guess[j] = arr[i][j];
			return;
		}
		if (!res.strike && !res.ball)//현재값에 없음
		{
			for (int j = 0; j < 4; ++j)
				visited[arr[i][j]] = true;
			visited2[i] = true;
		}
		else//그 외 ex> 2s 1b;
		{
			for (int j = 0; j < 10; ++j)digits[j] = false;
			for (int j = 0; j < N; ++j)digits[arr[i][j]] = true;
			go2(i, res.strike, res.ball);
			visited2[i] = true;
		}
	}
}
void tryBest(int suppose[]) {
	if (!done) {
		DFS(0);
		done = true;
	}
	init();
	go(suppose);
}