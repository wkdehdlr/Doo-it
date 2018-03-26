#pragma warning(disable : 4996)
#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int in[4];
bool visited[10000];
int res[10000];
int idx = 1;
void preset()
{
	for (int i = 1111; i < 10000; ++i)
	{
		if (i % 1000 < 100 || i % 100 < 10 || i % 10 == 0)continue;
		else {
			if (visited[i])continue;
			int val = i;
			int tmp = 0;
			res[val] = idx++;
			for (int k = 0; k < 4; ++k)
			{
				visited[val] = true;
				tmp = val / 1000;
				val -= ((val / 1000) * 1000);
				val *= 10;
				val += tmp;
			}
		}
	}
}
int main()
{

	preset();
	for (int i = 0; i < 4; ++i)scanf("%d", &in[i]);	
	for (int tc = 0; tc < 4; ++tc)
	{
		int tmp = 0;
		for (int i = 0; i < 4; ++i)
		{
			tmp *= 10;
			tmp += in[i];
		}
		q.push(tmp);
		rotate(in, in+1, in + 4);
	}
	printf("%d\n", res[q.top()]);
	return 0;
}