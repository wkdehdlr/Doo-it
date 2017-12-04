#pragma warning(disable : 4996)
#include<cstdio>
#include<list>
using namespace std;

list<int> lst;
int N, K,temp,idx,cnt;
char c;

int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		lst.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &temp);
			lst.push_back(temp);
		}

		scanf("%d", &K);
		for (int i = 0; i < K; ++i)
		{
			scanf("%c", &c);
			scanf("%c", &c);
			scanf("%c", &c);
			scanf("%d", &idx);
			scanf("%d", &cnt);
			for (int j = 0; j < cnt; ++j)
			{
				scanf("%d", &temp);
				auto it = lst.begin();
				for (int k = 0; k < idx+j; ++k)
					it++;
				lst.insert(it, temp);
			}
		}
		printf("#%d", tc + 1);
		auto it = lst.begin();
		for (int i = 0; i < 10; ++i)
		{
			printf(" %d", *it);
			it++;
		}
		printf("\n");
	}
}