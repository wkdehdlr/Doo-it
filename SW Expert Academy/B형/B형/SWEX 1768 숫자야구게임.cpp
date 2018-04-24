#define N 4

typedef struct {

	int strike;

	int ball;

} Result;

int guess2[N];
// API

extern Result query(int guess[]);

bool visited[10] = { false, };
bool guess_visited[1 << 11] = { false, };



int check2(int guess[])
{
	bool visited2[4] = { false, };
	int tmp[4] = { 0, };
	for (int i = 0; i < N; ++i)
	{
		tmp[i] = guess[i];
	}
	int idx = 0;
	for (int o = 0; o < 4; ++o)
	{
		if (!visited2[o])
		{
			visited2[o] = true;
			guess[idx++] = tmp[o];
			for (int t = 0; t < 4; ++t)
			{
				if (!visited2[t])
				{
					visited2[t] = true;
					guess[idx++] = tmp[t];
					for (int h = 0; h < 4; ++h)
					{
						if (!visited2[h])
						{
							visited2[h] = true;
							guess[idx++] = tmp[h];
							for (int f = 0; f < 4; ++f)
							{
								if (!visited2[f])
								{
									visited2[f] = true;
									guess[idx] = tmp[f];
									if (query(guess).strike == 4)
										return 1;
									visited2[f] = false;
								}
							}
							--idx;
							visited2[h] = false;
						}
					}
					--idx;
					visited2[t] = false;
				}
			}
			--idx;
			visited2[o] = false;
		}
	}
}
int doUserImplementation2(int guess[]) {

	int idx = 0;
	for (int o = 0; o < 10; ++o)
	{
		if (!visited[o])
		{
			visited[o] = true;
			guess[idx++] = o;
			for (int t = 0; t < 10; ++t)
			{
				if (!visited[t])
				{
					visited[t] = true;
					guess[idx++] = t;
					for (int h = 0; h < 10; ++h)
					{
						if (!visited[h])
						{
							visited[h] = true;
							guess[idx++] = h;
							for (int f = 0; f < 10; ++f)
							{
								if (!visited[f])
								{
									visited[f] = true;
									guess[idx] = f;

									//비교
									Result res1 = { 0,0 };
									int tmp1 = 0;
									for (int k = 0; k < N; ++k)
									{
										tmp1 |= (1 << guess[k]);
									}

									if (!guess_visited[tmp1])
									{
										guess_visited[tmp1] = true;
										res1 = query(guess);

										if (res1.strike == 4)//정답임
											return 1;
										if (res1.strike + res1.ball == 4)//이 4개중에 답있음
										{
											return check2(guess);
										}
									}
									visited[f] = false;
								}
							}
							--idx;
							visited[h] = false;
						}
					}
					--idx;
					visited[t] = false;
				}
			}
			--idx;
			visited[o] = false;
		}
	}
}
int compare(int guess[])
{
	Result res1 = { 0,0 }, res2 = { 0,0 };

	for (int k = 0; k < N; ++k)
	{
		int cnt = 0;
		while (visited[cnt])
		{
			cnt++;
		}
		visited[cnt] = true;
		guess2[k] = cnt;
	}


	int tmp1 = 0, tmp2 = 0;
	for (int k = 0; k < N; ++k)
	{
		tmp1 |= (1 << guess[k]);
		tmp2 |= (1 << guess2[k]);
	}

	if (!guess_visited[tmp1])
	{
		guess_visited[tmp1] = true;
		res1 = query(guess);

		if (res1.strike == 4)//정답임
			return 1;
		if (res1.strike + res1.ball == 4)//이 4개중에 답있음
		{
			return check2(guess);
		}
		if (res1.strike + res1.ball == 0)//이 4개모두 답이 아님->제외
		{
			visited[guess2[0]] = false;
			visited[guess2[1]] = false;
			visited[guess2[2]] = false;
			visited[guess2[3]] = false;
			return doUserImplementation2(guess);
		}
	}

	if (!guess_visited[tmp2])
	{
		guess_visited[tmp2] = true;
		res2 = query(guess2);

		if (res2.strike == 4)//정답임
			return 1;
		if (res2.strike + res2.ball == 4)//이 4개중에 답있음
		{
			return check2(guess);
		}
		if (res2.strike + res2.ball == 0)//이 4개모두 답이 아님->제외
		{
			visited[guess[0]] = false;
			visited[guess[1]] = false;
			visited[guess[2]] = false;
			visited[guess[3]] = false;
			return doUserImplementation2(guess);
		}
	}
	return 0;
}
void func(int guess[])
{
	int idx = 0;
	for (int o = 0; o < 10; ++o)
	{
		if (!visited[o])
		{
			visited[o] = true;
			guess[idx++] = o;
			for (int t = 0; t < 10; ++t)
			{
				if (!visited[t])
				{
					visited[t] = true;
					guess[idx++] = t;
					for (int h = 0; h < 10; ++h)
					{
						if (!visited[h])
						{
							visited[h] = true;
							guess[idx++] = h;
							for (int f = 0; f < 10; ++f)
							{
								if (!visited[f])
								{
									visited[f] = true;
									guess[idx] = f;

									//비교
									if (compare(guess) == 1)
										return;
									visited[guess2[0]] = false;
									visited[guess2[1]] = false;
									visited[guess2[2]] = false;
									visited[guess2[3]] = false;

									visited[f] = false;
								}
							}
							--idx;
							visited[h] = false;
						}
					}
					--idx;
					visited[t] = false;
				}
			}
			--idx;
			visited[o] = false;
		}
	}
}
void doUserImplementation(int guess[]) {
	for (int i = 0; i < N; ++i)guess2[i] = 0;
	for (int i = 0; i < 10; ++i)visited[i] = false;
	int k = 1 << 11;
	for (int i = 0; i < k; ++i)guess_visited[i] = false;
	func(guess);
}
