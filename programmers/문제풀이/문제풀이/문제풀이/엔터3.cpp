#pragma warning(disable : 4996)
#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;

priority_queue< int, vector<int>, less<int> > pq;//√÷¥Î»¸
priority_queue< int, vector<int>, greater<int> > mpq;//√÷º“»¸

vector<float> vec;

float tmp;
int N, K;

float Rounding(float x, int digit)
{
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}

bool func(float mid) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt += (vec[i] / mid);
	}
	if (K <= cnt)return true;
	else return false;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		vec.push_back(Rounding(tmp, 3));
	}
	float low = 0;
	float high = *max_element(vec.begin(), vec.end());	
	float mid;

	bool ok = true;
	while (low < high) {
		mid = (low + high + 0.001) / 2;
		if (func(mid)) {
			low = mid;
		}
		else {
			high = mid - 0.001;
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << Rounding(low, 2) << endl;
	return 0;
}