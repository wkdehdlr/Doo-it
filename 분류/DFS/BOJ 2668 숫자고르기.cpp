#pragma warning(disable : 4996)
#include<cstdio>
#include<algorithm>
using namespace std;
int res[101];
int visited[101];
int arr[101];
int N;
int cnt = 0, tmp = -1;
bool mycomp(int i, int j)
{
	return i < j;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; ++i)
	{
		int idx = i;
		tmp += 2;
		while (1)
		{
			if (visited[idx] == 0)//���� �湮�� ���Ѱ��̸�
			{
				visited[idx] = tmp;
				idx = arr[idx];
			}
			else if (visited[idx] == tmp)//����Ŭ�� ã����
			{
				res[cnt++] = arr[idx];
				//cnt++;
				visited[idx]++;
				idx = arr[idx];
			}
			else//�湮�Ѱ��̸�
			{
				break;
			}
		}
	}
	sort(res, res + cnt, mycomp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)printf("%d\n", res[i]);
}