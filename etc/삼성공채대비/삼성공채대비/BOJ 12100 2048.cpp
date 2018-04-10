#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue<vector<vector<int> > >q;
int N;
int mx = 0;
void left(vector<vector<int> > vec)
{
	for (int i = 1; i <= N; ++i)
	{
		int idx = 1;
		for (int j = 2; j <= N; ++j)
		{
			if (vec[i][j] == 0) { continue; }
			if (vec[i][idx] == 0)
			{
				vec[i][idx] = vec[i][j];
				vec[i][j] = 0;
				continue;
			}
			if (vec[i][idx] == vec[i][j])
			{
				vec[i][idx] += vec[i][j];
				vec[i][j] = 0;
				idx++;
				continue;
			}
			else if (vec[i][idx] != vec[i][j])
			{
				vec[i][idx + 1] = vec[i][j];
				idx++;
				if (idx == j)continue;
				vec[i][j] = 0;
				continue;
			}
			//idx++;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			//printf("%d ", vec[i][j]);
			if (mx < vec[i][j])
				mx = vec[i][j];
		}
		//printf("\n");
	}

	if (vec[0][0] < 5)
		q.push(vec);
}
void right(vector<vector<int> > vec)
{
	for (int i = 1; i <= N; ++i)
	{
		int idx = N;
		for (int j = N - 1; j >= 1; --j)
		{
			if (vec[i][j] == 0) { continue; }
			if (vec[i][idx] == 0)
			{
				vec[i][idx] = vec[i][j];
				vec[i][j] = 0;
				continue;
			}
			if (vec[i][idx] == vec[i][j])
			{
				vec[i][idx] += vec[i][j];
				vec[i][j] = 0;
				idx--;
				continue;
			}
			else if (vec[i][idx] != vec[i][j])
			{
				vec[i][idx - 1] = vec[i][j];
				idx--;
				if (idx == j)continue;
				vec[i][j] = 0;
				continue;
			}
			//idx--;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			//printf("%d ", vec[i][j]);
			if (mx < vec[i][j])
				mx = vec[i][j];
		}
		//printf("\n");
	}

	if (vec[0][0] < 5)
		q.push(vec);
}
void up(vector<vector<int> > vec)
{
	for (int j = 1; j <= N; ++j)
	{
		int idx = 1;
		for (int i = 2; i <= N; ++i)
		{
			if (vec[i][j] == 0) { continue; }
			if (vec[idx][j] == 0)
			{
				vec[idx][j] = vec[i][j];
				vec[i][j] = 0;
				continue;
			}
			if (vec[idx][j] == vec[i][j])
			{
				vec[idx][j] += vec[i][j];
				vec[i][j] = 0;
				idx++;
				continue;
			}
			else if (vec[idx][j] != vec[i][j])
			{
				vec[idx + 1][j] = vec[i][j];
				idx++;
				if (idx == i)continue;
				vec[i][j] = 0;
				continue;
			}
			//idx++;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
		//	printf("%d ", vec[i][j]);
			if (mx < vec[i][j])
				mx = vec[i][j];
		}
	//	printf("\n");
	}


	if (vec[0][0] < 5)
		q.push(vec);
}
void down(vector<vector<int> > vec)
{
	for (int j = 1; j <= N; ++j)
	{
		int idx = N;
		for (int i = N - 1; i >= 1; --i)
		{
			if (vec[i][j] == 0) { continue; }
			if (vec[idx][j] == 0)
			{
				vec[idx][j] = vec[i][j];
				vec[i][j] = 0;
				continue;
			}
			if (vec[idx][j] == vec[i][j])
			{
				vec[idx][j] += vec[i][j];
				vec[i][j] = 0;
				idx--;
				continue;
			}
			else if (vec[idx][j] != vec[i][j])
			{
				vec[idx - 1][j] = vec[i][j];
				idx--;
				if (idx == i)continue;
				vec[i][j] = 0;
				continue;
			}
			//idx--;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			//printf("%d ", vec[i][j]);
			if (mx < vec[i][j])
				mx = vec[i][j];
		}
		//printf("\n");
	}


	if (vec[0][0] < 5)
		q.push(vec);
}
void BFS()
{
	vector<vector<int> > vec(21, vector<int>(21));
	while(!q.empty())
	{
		vec = q.front();
		q.pop();

		vec[0][0]++;
		left(vec);
		right(vec);
		up(vec);
		down(vec);
	}
}

int main()
{
	vector<vector<int> > vec(21, vector<int>(21));
	vec[0][0] = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &vec[i][j]);
			if (mx < vec[i][j])
				mx = vec[i][j];
		}
	
	q.push(vec);
	BFS();
	printf("%d\n", mx);
}