#include<iostream>
using namespace std;

int n, cnt;

//�Է�
void input() {
	cin >> n;
}

//���� ���̴� (c>=b>=a) ���Դϴ�.(c�� ���� �亯)
void solution() {

	for (int a = 1; a<n; a++) {    // a�� ���� ª����
		for (int b = a; b<n; b++) { // b>=a
			int c = n - (a + b);
			if (c < b) break;    //�ߺ�����
			if (b + a > c) cnt++;  //�ﰢ�� �����ϴ���
		}
	}

}

//���
void output() {
	cout << cnt;
}

int main(void) {
	input();
	solution();
	output();
	return 0;
}
