#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

set<int> pq0, pq1, pq2;

//한 문자당 n/3개씩 가져가야 balnced하다
int n;
string str;
int main()
{
	cin >> n >> str;
	n /= 3;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '0')pq0.insert(i);
		else if (str[i] == '1')pq1.insert(i);
		else if (str[i] == '2')pq2.insert(i);
	}
	
	if (pq0.size() == pq1.size() && pq1.size() == pq2.size()) cout << str;
	else {
		while (!(n == pq0.size() && n == pq1.size() && n == pq2.size())) {
			int size0 = pq0.size();
			int size1 = pq1.size();
			int size2 = pq2.size();

			if (size2 != n) {
				if (size2 > n) {//2를 줄여야하는 케이스
					if (size0 < n) {//0으로 바꿈
						auto it = pq2.begin();
						str[*it] = '0';
						pq0.insert(*it);
						pq2.erase(it);
					}
					else if (size1 < n) {//1로 바꿈
						auto it = pq2.begin();
						str[*it] = '1';
						pq1.insert(*it);
						pq2.erase(it);
					}
				}
				else if (size2 < n) {//2를 늘려야하는 케이스					
					if (size0 > n) {//0을 2로 바꿈
						auto it = pq0.end();
						str[*(--it)] = '2';
						pq2.insert(*it);
						pq0.erase(it);
					}
					else if (size1 > n) {//1을 2로 바꿈
						auto it = pq1.end();
						str[*(--it)] = '2';
						pq2.insert(*it);
						pq1.erase(it);
					}
				}
			}
			else if (size1 != n) {//1을 바꿔야함
				if (size0 > n) {//0을 줄여야함
					auto it = pq0.end();
					str[*(--it)] = '1';
					pq1.insert(*it);
					pq0.erase(it);
				}
				else if (size0 < n) {//0을 늘려야함
					auto it = pq1.begin();
					str[*it] = '0';
					pq0.insert(*it);
					pq1.erase(it);
				}
			}
		}
		cout << str;
	}
}