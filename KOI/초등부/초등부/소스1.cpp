#include<iostream>
using namespace std;

int n, cnt;

//입력
void input() {
	cin >> n;
}

//변의 길이는 (c>=b>=a) 순입니다.(c가 제일 긴변)
void solution() {

	for (int a = 1; a<n; a++) {    // a가 가장 짧은변
		for (int b = a; b<n; b++) { // b>=a
			int c = n - (a + b);
			if (c < b) break;    //중복제외
			if (b + a > c) cnt++;  //삼각형 성립하는지
		}
	}

}

//출력
void output() {
	cout << cnt;
}

int main(void) {
	input();
	solution();
	output();
	return 0;
}
