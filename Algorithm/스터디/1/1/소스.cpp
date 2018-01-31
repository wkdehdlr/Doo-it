#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;
ll s, c, left, right, mid, gesu;
int main(void)
{
	ll allhap = 0;
	scanf("%lld %lld", &s, &c);
	left = 0;
	vector<ll> L(s + 10); //≥À≥À«œ∞‘ ¿‚æ∆¡‹
	for (int i = 0; i<s; i++)
	{
		scanf("%lld", &L[i]); allhap += L[i];
	}
	right = (allhap / c) + 10; //≥À≥À«œ∞‘ ¿‚æ∆¡‹ 
	mid = (left + right) / 2;
	for (; left <= right;)
	{
		gesu = 0;
		for (int i = 0; i<s; i++)
			gesu += (L[i] / mid);
		if (gesu >= c)
			left = mid + 1;
		else if (gesu<c)
			right = mid - 1;
		mid = (left + right) / 2;
	}
	allhap -= (mid*c);
	printf("%lld", allhap);
}
