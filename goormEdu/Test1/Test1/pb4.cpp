#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;


/**
@description
��ǰ ���߿� �ʿ��� ������ �Ķ���ͷ� �޾� ��ǰ ���߿� �ʿ��� �ּ��� Ư�� ������ ���� ����Ͽ� ��ȯ���ִ� �Լ�

@param n      ���� X���� ���� �� �ִ� �⺻ ������ ������
@param g      ��ǰ ���߿� �ʿ��� Ư�� �ռ� ������ ��
@param needs  ��ǰ ���߿� �ʿ��� N���� �⺻ ������ ��
@return       ��ǰ ���߿� �ʿ��� �ּ��� Ư�� ���� X�� ����
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
		//�⺻ ������ �� N�� �ʿ��� Ư�� �ռ� ������ �� G�� �Է¹޴´�.
		int n, g;
		cin >> n >> g;

		//�� ������ �ʿ��� ���� ���ʷ� �Է¹޾� ���Ϳ� �����Ѵ�
		vector<int> needs(n);
		for (int i = 0; i < n; i++) {
			cin >> needs[i];
		}

		//�־��� �Լ��� �̿��� ������ ����Ѵ�
		int answer = get_least_quantities(n, g, needs);

		//���Ŀ� �°� ������ ����Ѵ�
		cout << "Case #" << caseIndex << "\n";;
		cout << answer << "\n";
	}

	return 0;
}