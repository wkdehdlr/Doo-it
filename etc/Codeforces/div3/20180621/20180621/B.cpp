#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int N, len;
char str[110];
vector<char> vec;
stack<int> st;
int main()
{
	scanf("%d %s", &N, str);
	for (int i = 0; i < N; ++i)vec.push_back(str[i]);
	int n = N;
	while (n) {
		st.push(n);
		n /= 2;
	}
	while (!st.empty())
	{
		reverse(vec.begin(), vec.begin() + st.top());
		st.pop();
	}
	for (int i = 0; i < N; ++i)
		printf("%c", vec[i]);
}