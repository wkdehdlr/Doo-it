#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char str[100010];
int arr[100010];
ll dp[100010][4];
int N;
ll func(int idx, int flag)
{
	if (flag == 4)return 1e18;
	if (idx == N)return 0;
	ll&ret = dp[idx][flag];
	if (ret != -1)return ret;
	ret = 1e18;


	if (str[idx] == 'h') {
		ret = min(ret,func(idx + 1, flag + (flag == 0 ? 1 : 0)));//h�� ������� ���
		ret = min(ret,func(idx + 1, flag) + arr[idx]);//h�� ����� ���
	}
	else if (str[idx] == 'a') {
		ret = min(ret,func(idx + 1, flag + (flag == 1 ? 1 : 0)));//a�� ������� ���
		ret = min(ret,func(idx + 1, flag) + arr[idx]);//a�� ����� ���
	}
	else if (str[idx] == 'r') {
		ret = min(ret,func(idx + 1, flag + (flag == 2 ? 1 : 0)));//r�� ������� ���
		ret = min(ret,func(idx + 1, flag) + arr[idx]);//r�� ����� ���
	}
	else if (str[idx] == 'd') {
		ret = min(ret,func(idx + 1, flag + (flag == 3 ? 1 : 0)));//d�� ������� ���
		ret = min(ret,func(idx + 1, flag) + arr[idx]);//d�� ����� ���
	}
	else ret = min(ret, func(idx + 1, flag));
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	scanf("%s", str);
	for (int i = 0; i < N; ++i)scanf("%d", &arr[i]);
	printf("%lld\n", func(0, 0));
}