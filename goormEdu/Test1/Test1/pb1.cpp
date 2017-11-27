#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

/**
@description
알파벳으로 구성된 이름과 성을 입력받아 일정한 형식으로 합쳐 반환하는 함수

@param first_name 알파벳으로 이루어진 이름
@param last_name  알파벳으로 이루어진 성
@return           문제에 주어진 형식으로 합쳐진 문자열
*/
string get_formatted_name(string &first_name, string& last_name)
{
	string formatted_name;
	transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);
	toupper(last_name[0]);

	formatted_name = last_name;

	transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
	toupper(first_name[0]);
	formatted_name += (" " + first_name);
	return formatted_name;
}

/*
** 메인 함수에는 테스트케이스와 입출력에 대한 기본적인 뼈대 코드가 작성되어 있습니다.
** 상단의 함수만 완성하여도 문제를 해결할 수 있으며,
** 메인 함수를 제거한 후 스스로 코드를 모두 작성하여도 무방합니다.
** 단, 스스로 작성한 코드로 인해 발생한 에러 등은 모두 참가자에게 책임이 있습니다.
*/
int main() {
	ios_base::sync_with_stdio(false);

	//테스트케이스의 수를 입력받는다 
	int caseNum;
	cin >> caseNum;

	//각 테스트케이스에 대하여 데이터를 입력받고 정답을 차례로 출력한다
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++)
	{
		string first_name;
		string last_name;

		//이름과 성을 차례로 입력받는다
		cin >> first_name >> last_name;

		//주어진 함수로 포매팅된 이름을 얻는다 
		string answer = get_formatted_name(first_name, last_name);

		//정답을 출력한다
		cout << "Case #" << caseIndex << "\n";
		cout << answer << "\n";
	}
	return 0;
}
