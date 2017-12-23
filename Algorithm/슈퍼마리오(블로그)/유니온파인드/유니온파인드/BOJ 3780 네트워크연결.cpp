#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

int arr[200001][2];
int N,T;
char str[2];

pair<int,int> find(int n)
{
	if (arr[n][0] == 0)
	{
		return make_pair(n,0);
	}
    pair<int, int> p = find(arr[n][0]);
	arr[n][0] = p.first;
	arr[n][1] += p.second;
	p.second = arr[n][1];
	return p;
}
void merge(int a, int b)
{
	arr[a][1] = abs(a - b) % 1000;
	arr[a][0] = b;
}

int main()
{
	int I, J;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%d", &N);
 		while (1)
		{
			scanf("%s", str);
			if (str[0] == 'O')
				break;
			else if (str[0] == 'E')
			{
				scanf("%d", &I);
				printf("%d\n", find(I).second);
			}
			else if (str[0] == 'I')
			{
				scanf("%d %d", &I, &J);
				merge(I, J);
			}
		}
		for (int i = 0; i <= N; ++i)
			arr[i][0] = 0;
	}
}