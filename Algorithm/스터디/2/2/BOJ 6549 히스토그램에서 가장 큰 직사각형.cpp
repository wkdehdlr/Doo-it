#pragma warning(disable : 4996)
#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
ll ans = 0, maxn = 0;
ll N;
ll arr[100000];
stack<pair<ll,ll> > st;
int main()
{
	for (; scanf("%lld", &N), N;)
	{
		ans = 0, maxn = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%lld", &arr[i]);
		}

		for (int i = 0; i < N; ++i)
		{
			if (st.empty())//������ ��������� �׳� �ִ´�
				st.push({ arr[i],i });
			else
			{
				if(st.top().first <= arr[i])//ž���� �� ���ų� ������ �׳� �ִ´�.
					st.push({ arr[i],i });
				else//�� ������ ������
				{
					while (!st.empty() && st.top().first > arr[i])
					{
						ll len = 0;
						ll height = st.top().first;
						st.pop();

						if (st.empty())
							len = i;
						else
							len = i - st.top().second - 1;

						ans = height * len;
						if (ans > maxn)
							maxn = ans;
					}
					st.push({ arr[i],i });
				}
			}
		}

		while (!st.empty())
		{
			ll len = 0;
			ll height = st.top().first;
			st.pop();

			if (st.empty())
				len = N;
			else
				len = N - st.top().second - 1;

			ans = height * len;
			if (ans > maxn)
				maxn = ans;
		}
		printf("%lld\n", maxn);
	}
}