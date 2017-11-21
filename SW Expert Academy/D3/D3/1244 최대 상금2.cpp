#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
using namespace std;

int arr[6];
char temp[10];
int T, cnt, N;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc)
	{
		scanf("%s %d", temp, &cnt);
		N = strlen(temp);//몇자리 숫자인지
		for (int i = 0; i < N; ++i)
		{
			arr[i] = temp[i] - '0';
		}
	}
}