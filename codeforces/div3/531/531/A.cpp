#include<cstdio>


long long n;
//�� ������ ���� �ִ��� ����ϰ� �Ϸ���
//
int main()
{
	long long res = 0;
	scanf("%lld", &n);
	if (((n*(n + 1)) / 2) % 2)printf("1\n");
	else printf("0");
}