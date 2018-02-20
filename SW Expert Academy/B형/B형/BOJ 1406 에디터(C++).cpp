#pragma warning(disable : 4996)
#include<cstdio>
#include<list>
using namespace std;

list<char> lst;
char str[100001];
int N;

int main()
{
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i)
		lst.push_back(str[i]);
		
	auto it = lst.end();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", str);
		switch (str[0])
		{
		case 'L': if (it != lst.begin())it--; break;
		case 'D': if (it != lst.end())it++; break;
		case 'B': if (it != lst.begin()) { it = lst.erase(--it); } break;
		case 'P': scanf("%s", str); lst.insert(it, str[0]); break;
		}
	}
	for (auto ite = lst.begin(); ite != lst.end(); ++ite)
		printf("%c", *ite);
	printf("\n");
}