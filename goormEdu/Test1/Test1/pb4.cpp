#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;


/**
@description
약품 개발에 필요한 정보를 파라미터로 받아 약품 개발에 필요한 최소의 특수 광물의 수를 계산하여 반환해주는 함수

@param n      광물 X에서 얻을 수 있는 기본 물질의 가짓수
@param g      약품 개발에 필요한 특수 합성 물질의 양
@param needs  약품 개발에 필요한 N가지 기본 물질의 양
@return       약품 개발에 필요한 최소의 특수 광물 X의 갯수
*/
int get_least_quantities(int n, int g, vector<int>& needs)
{
	vector<int> need;
	int maxN = *(max_element(needs.begin(), needs.end()));
	if (maxN % 50)
		maxN = ((maxN / 50) + 1) * 50;
	int size = needs.size();
	need.resize(size);
	for (int i = 0; i < size; ++i)
	{
		need[i] = needs[i];
	}

	while (1)
	{
		for (int i = 0; i < size; ++i)
		{
			need[i] = maxN - need[i];
		}

		int sum = 0;
		sort(need.begin(), need.end(),greater<int>());
		while (need[0] && need[1] && need[2])
		{
			need[0] -= need[2];
			need[1] -= need[2];
			sum += need[2];
			need[2] -= need[2];
			if (sum >= g)
				break;
			sort(need.begin(), need.end(),greater<int>());
		}

		if (sum >= g)
			return maxN / 50;
		else
		{
			for (int i = 0; i < size; ++i)
			{
				need[i] = needs[i];
			}
			maxN += 50;
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
		//기본 물질의 수 N과 필요한 특수 합성 물질의 양 G를 입력받는다.
		int n, g;
		cin >> n >> g;

		//각 물질이 필요한 양을 차례로 입력받아 벡터에 저장한다
		vector<int> needs(n);
		for (int i = 0; i < n; i++) {
			cin >> needs[i];
		}

		//주어진 함수를 이용해 정답을 계산한다
		int answer = get_least_quantities(n, g, needs);

		//형식에 맞게 정답을 출력한다
		cout << "Case #" << caseIndex << "\n";;
		cout << answer << "\n";
	}

	return 0;
}