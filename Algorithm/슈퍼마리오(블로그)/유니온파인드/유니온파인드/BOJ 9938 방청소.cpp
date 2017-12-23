#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;


int arr[300001];
int N, L;
int find(int);
void merge(int, int);
int main()
{

	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (arr[find(a)]<0)//비어있으면
		{
			merge(a, b);
			printf("LADICA\n");
			continue;
		}
		else//차있으면
		{
			if (arr[find(b)]<0)//비어있으면
			{
				merge(b, a);
				printf("LADICA\n");
				continue;
			}
			printf("SMECE\n");
		}
	}
}
int find(int n)//find는 인자로 넘어온 원소n의 루트를 찾아주는 함수이다.
			   //뭔말인고하니....루트의 값이 아니라 단순히 루트가 뭔지 알려주는거다.
			   //한마디로 배열 인덱스를 알려주는거지 배열값을 알려주는게 아니란거다.
{
	if (arr[n] < 0) return n;
	if (arr[n] == n)return n;
	return arr[n] = find(arr[n]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	//if (a == b)return;
	arr[a] = b;
}