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
로봇 방문 순서에 따라 벡타 m을 채워주는 함수

@param m	로봇 방문 순서를 저장할 r행 c열의 벡터, m[i][j] := (i행 j열)칸의 로봇의 방문 순서 번호
@param r	행의 수
@param c	열의 수
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
** 메인 함수에는 테스트케이스와 입출력에 대한 기본적인 뼈대 코드가 작성되어 있습니다.
** 상단의 함수만 완성하여도 문제를 해결할 수 있으며,
** 메인 함수를 제거한 후 스스로 코드를 모두 작성하여도 무방합니다.
** 단, 스스로 작성한 코드로 인해 발생한 에러 등은 모두 참가자에게 책임이 있습니다.
*/
int main() {
	ios_base::sync_with_stdio(false);

	//테스트케이스의 수를 입력 받는다 
	int caseNum;
	cin >> caseNum;

	//순서대로 각 테스트케이스의 데이터를 입력받고 정답을 출력한다
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++)
	{
		//행과 열의 수를 입력받는다
		cin >> r >> c;

		//0으로 초기화 된 r행 c열의 벡터를 생성한다

		//주어진 함수를 실행하여 각 칸을 로봇 청소기가 방문하는 순서를 벡터에 계산한다
		DFS(1, 1, 1, 0);

		//케이스 번호를 출력한다
		cout << "Case #" << caseIndex << "\n";

		//각 칸의 방문 순서를 출력 형식에 맞게 출력한다
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