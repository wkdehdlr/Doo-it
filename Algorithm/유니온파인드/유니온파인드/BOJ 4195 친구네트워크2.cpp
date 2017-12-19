#pragma warning(disable : 4996)
#include<cstdio>
#include<map>
#include<unordered_map>
#include<cstring>
using namespace std;


int cnt = 0;
int T, F;
char temp1[21];
char temp2[21];
string str1;
string str2;
unordered_map<string, int> mp;
int arr[200001];

int find(int a)
{
	if (arr[a] < 0)return  a;
	return arr[a] = find(arr[a]);
}
void merge(int a, int b)
{
	a =	find(a);
	b =	find(b);
	if (a == b)
	{
		printf("%d\n", -arr[a]);
		return;
	}
	arr[a] += arr[b];
	arr[b] = a;
	printf("%d\n", -arr[a]);
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(arr, -1, sizeof(arr));
		mp.clear();
		cnt = 0;
		scanf("%d", &F);
		for (int i = 0; i < F; ++i)
		{
			scanf("%s %s", temp1, temp2);
			str1 = temp1; str2 = temp2;
			if (mp.end() == mp.find(str1))
			{
				mp[str1] = cnt++;
				arr[mp[str1]] = -1;
			}
			if (mp.end() == mp.find(str2))
			{
				mp[str2] = cnt++;
				arr[mp[str2]] = -1;
			}
			merge(mp[str1], mp[str2]);
		}
	}
}