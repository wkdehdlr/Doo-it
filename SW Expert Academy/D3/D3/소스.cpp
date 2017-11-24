#include<cstdio>
using namespace std;

int main()
{
	int sum = 0;
	int i = 1;
	for (; i < 1000; ++i)
	{
		sum += i;
		if (sum >= 10000)
			break;
	}
	printf("%d %d\n", i,sum);
	//141 10011
}