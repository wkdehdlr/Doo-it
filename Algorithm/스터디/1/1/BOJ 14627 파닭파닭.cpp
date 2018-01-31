#pragma warning(disable : 4996)
#include<cstdio>
using namespace std;
typedef long long ll;
ll maxn = 0;
ll total = 0;
int S, C;
ll arr[1000000];
int main()
{
	scanf("%d %d", &S, &C);
	for (int i = 0; i < S; ++i)
	{
		scanf("%lld", &arr[i]);
		total += arr[i];
	}

	ll left = 1;
	ll right = 1000000000;
	ll mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < S; ++i)
		{
			cnt += (arr[i] / mid);
		}

		if (cnt >= C)
		{
			left = mid + 1;
		}
		else if (cnt < C)
		{
			right = mid - 1;
		}
	}
	total -= (right*C);
	printf("%lld\n", total);
}