#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
using namespace std;

queue<pair<int, int> > q;
vector<bool> visited;
vector<map<int, int> >ma;
vector<vector<int> > vec;
int N, start, dat1, dat2;
int max_length;
int max_num;


void BFS();
int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		queue<pair<int, int> > q2;
		q = q2;
		max_num = 0;
		max_length = 0;
		visited.clear();
		visited.resize(101);
		ma.clear();
		ma.resize(101);
		vec.clear();
		vec.resize(101);
		scanf("%d %d", &N, &start);
		N /= 2;
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d %d", &dat1, &dat2);
			if (!ma[dat1].count(dat2))
			{
				vec[dat1].push_back(dat2);
				ma[dat1].insert({ dat2,1 });
			}
		}
		q.push({ start,0 });
		visited[start] = true;
		BFS();
		printf("#%d %d\n", tc + 1, max_num);
	}
}
void BFS()
{
	while (!q.empty())
	{
		int num = q.front().first;
		int length = q.front().second;
		q.pop();
		int size = vec[num].size();
		

		if (max_length < length)
		{
			max_length = length;
			max_num = num;
		}
		else if (max_length == length)
		{
			if (max_num < num)
				max_num = num;
		}
		
		for (int i = 0; i < size; ++i)
		{
			if (visited[vec[num][i]] == false)
			{
				visited[vec[num][i]] = true;
				q.push({ vec[num][i],length + 1 });
			}
		}
	}
}