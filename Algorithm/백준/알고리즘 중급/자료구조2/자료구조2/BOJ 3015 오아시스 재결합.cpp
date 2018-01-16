#include<iostream>
#include<stack>

typedef long long ll;
using namespace std;
ll ans;
int N;
int arr;
stack<pair<int, int> > st;
int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr;
		pair<int, int> p = { arr,1 };
		while (!st.empty())
		{
			if (st.top().first <= arr)
			{
				ans += (ll)st.top().second;
				if (st.top().first == arr)
					p.second += st.top().second;
				st.pop();
			}
			else
				break;
		}

		if (!st.empty())
			ans += 1;
		st.push(p);
	}
	cout << ans << '\n';
}