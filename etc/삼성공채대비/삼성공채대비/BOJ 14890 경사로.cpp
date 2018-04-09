#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<cmath>

int cnt = 0;
int N, L;
int arr[101][101];
bool visited[101][101];
bool check_visit(int rc,int i, int j, int k)
{
	if (!rc)
	{
		for (; j <= k; ++j)
		{
			if (visited[i][j])return true;
		}
		return false;
	}
	else
	{
		for (; j <= k; ++j)
		{
			if (visited[j][i])return true;
		}
		return false;
	}
}
bool check_adj(int rc, int i, int j, int k)
{
	if (!rc)
	{
		for (; j < k; ++j)
		{
			if (arr[i][j] != arr[i][j + 1])return true;
		}
		return false;
	}
	else
	{
		for (; j < k; ++j)
		{
			if (arr[j][i] != arr[j + 1][i])return true;
		}
		return false;
	}

}
void visit(int rc, int i, int j, int k)
{
	if (!rc)
	{
		for (; j <= k; ++j)
			visited[i][j] = true;
	}
	else
	{
		for (; j <= k; ++j)
			visited[j][i] = true;
	}

}
void check_row()
{
	for (int i = 1; i <= N; ++i)
	{
		bool ok = true;
		for (int j = 1; j < N; ++j)
		{
			if (arr[i][j] == arr[i][j + 1])continue;
			if (abs(arr[i][j] - arr[i][j + 1]) == 1)
			{
				if (arr[i][j] > arr[i][j + 1])//3 2 2 .....
				{
					if (j + L > N) { ok = false; break; }
					if (check_visit(0,i, j + 1, j + L)) { ok = false; break; }//중복검사
					if (check_adj(0,i, j + 1, j + L)) { ok = false; break; }//연속된개수
					visit(0,i, j + 1, j + L);//중복적용
					j += (L - 1);
				}
				else//.. 2 2 3
				{
					if (j - L < 0) { ok = false; break; }
					if (check_visit(0,i, j - L + 1, j)) { ok = false; break; }//중복검사
					if (check_adj(0,i, j - L + 1, j)) { ok = false; break; }//연속된개수
					visit(0,i, j - L + 1, j);//중복적용
				}
			}
			else { ok = false; break; }//차이가 1 이상임->불가능함
		}
		if (ok)cnt++;
	}
}
void check_col()
{
	for (int j = 1; j <= N; ++j)
	{
		bool ok = true;
		for (int i = 1; i < N; ++i)
		{
			if (arr[i][j] == arr[i + 1][j])continue;
			if (abs(arr[i][j] - arr[i + 1][j]) == 1)
			{
				if (arr[i][j] > arr[i + 1][j])//3 2 2 .....
				{
					if (i + L > N) { ok = false; break; }
					if (check_visit(1,j, i + 1, i + L)) { ok = false; break; }//중복검사
					if (check_adj(1,j, i + 1, i + L)) { ok = false; break; }//연속된개수
					visit(1,j, i + 1, i + L);//중복적용
					i += (L - 1);
				}
				else//.. 2 2 3
				{
					if (i - L < 0) { ok = false; break; }
					if (check_visit(1,j, i - L + 1, i)) { ok = false; break; }//중복검사
					if (check_adj(1,j, i - L + 1, i)) { ok = false; break; }//연속된개수
					visit(1,j, i - L + 1, i);//중복적용
				}
			}
			else { ok = false; break; }//차이가 1 이상임->불가능함
		}
		if (ok)cnt++;
	}
}
int main()
{
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &arr[i][j]);

	check_row();
	memset(visited, 0, sizeof(visited));
	check_col();
	printf("%d\n", cnt);
}