#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;

struct info
{
	bool visited;
	int cnt;
};
int cnt = 0;
int N, K;
int arrN[101];
info arr[101];

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= K; ++i)
	{
		scanf("%d", &arrN[i]);
		arr[arrN[i]].cnt++;
	}


	for (int i = 1; i <= K; ++i)
	{
		if (N)//������ �����ְ�
		{
			if (!arr[arrN[i]].visited)//���� ���������� ��ǰ�̸�
			{
				arr[arrN[i]].visited = true;//�Ŵ´�
				N--;//�����ϳ� ���δ�
				arr[arrN[i]].cnt--;
			}
			else
			{
				arr[arrN[i]].cnt--;
			}
		}
		else//������ ����
		{
			if (arr[arrN[i]].visited)//�̹� ���� ��ǰ
			{
				arr[arrN[i]].cnt--;//������ ����
			}
			else//���βȾƾ��ϴ���ǰ
			{
				int maxN = 0;
				int max_idx = 0;
				for (int j = 1; j <= K; ++j)
				{
					if (arr[j].visited)
					{
						if (!arr[j].cnt)
						{
							arr[j].visited = false;
							arr[arrN[i]].visited = true;
							arr[arrN[i]].cnt--;
							max_idx = 0;
							break;
						}
						else
						{
							for (int y = i + 1; y <= K; ++y)
							{
								if (j == arrN[y])
								{
									if (max_idx < y)
									{
										max_idx = y;
										maxN = arrN[y];
									}
									break;
								}
							}
						}
					}
				}
				if (max_idx)
				{
					arr[maxN].visited = false;
					arr[arrN[i]].visited = true;
					arr[arrN[i]].cnt--;
				}
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}
/*
2 7
2 3 2 3 1 2 7
2

2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
2

1 7
1 2 1 1 2 2 3
4
*/