#pragma warning(disable : 4996)
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 201
#define MAX_M 201

// A�� B�� ������ ����
int n, m;

// adj[i][j] = Ai�� Bj�� ����Ǿ� �ִ°�?
bool adj[MAX_N][MAX_M];

// �� ������ ��Ī�� ��� ������ ��ȣ�� �����Ѵ�.
vector<int> aMatch, bMatch;

// dfs()�� �湮 ����
vector<bool> visited;

// A�� ������ a���� B�� ��Ī���� ���� �������� ���� ��θ� ã�´�.
bool dfs(int a)
{
	if (visited[a])
		return false;

	visited[a] = true;

	for (int b = 0; b < m; b++)
	{
		if (adj[a][b])
		{
			// b�� ��Ī�Ǿ� ���� �ʴٸ� bMatch[b]�������� ������ ���� ��θ� ã�´�.
			// ��Ī�Ǿ� �ִٸ� dfs���� ��Ī�Ǿ��ִ� A������ �ٸ� ���� ��Ī �� �� �ִ��� ����.
			if (bMatch[b] == -1 || dfs(bMatch[b]))
			{
				// ���� ��θ� �߰��Ͽ��� ��, a�� b�� ��ġ��Ų��.(�̾��ش�.)
				aMatch[a] = b;
				bMatch[b] = a;

				return true;
			}
		}
	}

	return false;
}

// aMatch, bMatch �迭�� ����ϰ� �ִ� ��Ī ũ�⸦ ��ȯ�Ѵ�.
int bipartiteMatch()
{
	// -1�� �ʱ�ȭ (� �������� ����Ǿ� ���� �ʴٴ� �ǹ�)
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;

	for (int start = 0; start < n; start++)
	{
		visited = vector<bool>(n, false);

		// ���� �켱 Ž���� �̿��� start���� �����ϴ� ���� ��θ� ã�´�.
		if (dfs(start))
			size++;
	}

	return size;
}

int main()
{

	scanf("%d", &n);
	m = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			adj[i][j] = true;
		}
	}
	cout << bipartiteMatch() << endl;

	return 0;
}
