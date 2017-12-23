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

		if (arr[find(a)]<0)//���������
		{
			merge(a, b);
			printf("LADICA\n");
			continue;
		}
		else//��������
		{
			if (arr[find(b)]<0)//���������
			{
				merge(b, a);
				printf("LADICA\n");
				continue;
			}
			printf("SMECE\n");
		}
	}
}
int find(int n)//find�� ���ڷ� �Ѿ�� ����n�� ��Ʈ�� ã���ִ� �Լ��̴�.
			   //�����ΰ��ϴ�....��Ʈ�� ���� �ƴ϶� �ܼ��� ��Ʈ�� ���� �˷��ִ°Ŵ�.
			   //�Ѹ���� �迭 �ε����� �˷��ִ°��� �迭���� �˷��ִ°� �ƴ϶��Ŵ�.
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