#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
int visited[100001];
int arr[100001];
int T, N;
int cnt = 0, tmp = -1;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		tmp = -1;
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
					cnt++;
					visited[idx]++;
					idx = arr[idx];
				}
				else//�湮�Ѱ��̸�
				{
					break;
				}
			}
		}
		printf("%d\n", N - cnt);
	}
}