#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
#include<list>
using namespace std;

char temp[6];
int N;
int num;
list<int> vec;
//auto itt = vec.begin();
std::list<int>::iterator it = vec.begin();
int main()
{
	//std::list<int>::iterator it = vec.begin();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s",temp);

		if (strcmp("PUSH", temp) == 0)
		{
			scanf("%d", &num);
			vec.push_back(num);
			vec.sort();
			//sort(vec.begin(), vec.end(), greater<int>());
			if (!(vec.size() % 2))//Â¦¼ö
			{
				 it = vec.begin();
				for (int i = 1; i < vec.size() / 2; ++i)
				{
					it++;
				}
				printf("%d\n", *it);
			}
			else//È¦¼ö
			{
				it = vec.begin();
				for (int i = 1; i < (vec.size()+1) / 2; ++i)
				{
					it++;
				}
				printf("%d\n", *it);
			}
			continue;
		}

		if (strcmp("POP", temp) == 0)
		{
			if (!(vec.size() % 2))//Â¦¼ö
			{
				 it = vec.begin();
				for (int i = 1; i < vec.size() / 2; ++i)
				{
					it++;
				}
				it = vec.erase(it);
				if (vec.size())
				{
					printf("%d\n", *it);
				}
				else
				{
					printf("NO ITEM\n");
				}
			}
			else//È¦¼ö
			{
				 it = vec.begin();
				for (int i = 1; i < (vec.size()+1) / 2; ++i)
				{
					it++;
				}
				it = vec.erase(it);
				if (vec.size())
				{
					it--;
					printf("%d\n", *it);
				}
				else
				{
					printf("NO ITEM\n");
				}
			}
			continue;
		}

		if (strcmp("SIZE", temp) == 0)
		{
			printf("%d\n", vec.size());
			continue;
		}
	}
}