#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<int> people = { 1,2,3 };
vector<int> tshirts = { 1,1 };
int main()
{
	sort(people.begin(), people.end(), greater<int>());
	sort(tshirts.begin(), tshirts.end());
	int cnt = 0;
	while (!people.empty()) {
		int data = people.back();
		people.pop_back();
		if (lower_bound(tshirts.begin(), tshirts.end(), data) == tshirts.end())continue;
		tshirts.erase(lower_bound(tshirts.begin(), tshirts.end(), data));
		cnt++;
	}
	printf("%d\n", cnt);
}