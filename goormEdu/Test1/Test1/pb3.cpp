#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<vector<int> > m(101, vector<int>(101));
bool visited[101][101];
int r, c;
/**
@description
�κ� �湮 ������ ���� ��Ÿ m�� ä���ִ� �Լ�

@param m	�κ� �湮 ������ ������ r�� c���� ����, m[i][j] := (i�� j��)ĭ�� �κ��� �湮 ���� ��ȣ
@param r	���� ��
@param c	���� ��
*/
void DFS(int i, int j, int num,int dir)
{
	if (r*c == num)
	{
		m[i][j] = num;
	}
	else
	{
		visited[i][j] = true;
		m[i][j] = num;
		int x = i + dr[dir];
		int y = j + dc[dir];
		if (x >= 1 && x <= r && y >= 1 && y <= c && !visited[x][y])
		{
			DFS(x, y, num + 1, dir);
		}
		else
		{
			DFS(i + dr[(dir + 1) % 4], j + dc[(dir + 1) % 4], num + 1, (dir + 1) % 4);
		}
	}
}

/*
** ���� �Լ����� �׽�Ʈ���̽��� ����¿� ���� �⺻���� ���� �ڵ尡 �ۼ��Ǿ� �ֽ��ϴ�.
** ����� �Լ��� �ϼ��Ͽ��� ������ �ذ��� �� ������,
** ���� �Լ��� ������ �� ������ �ڵ带 ��� �ۼ��Ͽ��� �����մϴ�.
** ��, ������ �ۼ��� �ڵ�� ���� �߻��� ���� ���� ��� �����ڿ��� å���� �ֽ��ϴ�.
*/
int main() {
	ios_base::sync_with_stdio(false);

	//�׽�Ʈ���̽��� ���� �Է� �޴´� 
	int caseNum;
	cin >> caseNum;

	//������� �� �׽�Ʈ���̽��� �����͸� �Է¹ް� ������ ����Ѵ�
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++)
	{
		//��� ���� ���� �Է¹޴´�
		cin >> r >> c;

		//0���� �ʱ�ȭ �� r�� c���� ���͸� �����Ѵ�

		//�־��� �Լ��� �����Ͽ� �� ĭ�� �κ� û�ұⰡ �湮�ϴ� ������ ���Ϳ� ����Ѵ�
		DFS(1, 1, 1, 0);

		//���̽� ��ȣ�� ����Ѵ�
		cout << "Case #" << caseIndex << "\n";

		//�� ĭ�� �湮 ������ ��� ���Ŀ� �°� ����Ѵ�
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (j > 1)
					cout << " ";
				cout << m[i][j];
			}
			cout << "\n";
		}
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				visited[i][j] = false;
			}

		}
		//memset(visited, false, sizeof(bool) * 101 * 101);
	}
	return 0;
}