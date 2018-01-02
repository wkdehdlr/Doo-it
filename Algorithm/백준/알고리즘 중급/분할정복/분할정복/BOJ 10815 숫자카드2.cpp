#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int N, M;
//unordered_map<int,bool> ma;
unordered_set<int> se;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int temp;
		scanf("%d", &temp);
		//ma[temp] = true;
		se.insert(temp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if (se.find(temp) != se.end())
			printf("1 ");
		else
			printf("0 ");
	}
}