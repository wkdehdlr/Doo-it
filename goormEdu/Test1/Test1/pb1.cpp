#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

/**
@description
���ĺ����� ������ �̸��� ���� �Է¹޾� ������ �������� ���� ��ȯ�ϴ� �Լ�

@param first_name ���ĺ����� �̷���� �̸�
@param last_name  ���ĺ����� �̷���� ��
@return           ������ �־��� �������� ������ ���ڿ�
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
** ���� �Լ����� �׽�Ʈ���̽��� ����¿� ���� �⺻���� ���� �ڵ尡 �ۼ��Ǿ� �ֽ��ϴ�.
** ����� �Լ��� �ϼ��Ͽ��� ������ �ذ��� �� ������,
** ���� �Լ��� ������ �� ������ �ڵ带 ��� �ۼ��Ͽ��� �����մϴ�.
** ��, ������ �ۼ��� �ڵ�� ���� �߻��� ���� ���� ��� �����ڿ��� å���� �ֽ��ϴ�.
*/
int main() {
	ios_base::sync_with_stdio(false);

	//�׽�Ʈ���̽��� ���� �Է¹޴´� 
	int caseNum;
	cin >> caseNum;

	//�� �׽�Ʈ���̽��� ���Ͽ� �����͸� �Է¹ް� ������ ���ʷ� ����Ѵ�
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++)
	{
		string first_name;
		string last_name;

		//�̸��� ���� ���ʷ� �Է¹޴´�
		cin >> first_name >> last_name;

		//�־��� �Լ��� �����õ� �̸��� ��´� 
		string answer = get_formatted_name(first_name, last_name);

		//������ ����Ѵ�
		cout << "Case #" << caseIndex << "\n";
		cout << answer << "\n";
	}
	return 0;
}
