#include<cstdio>
using namespace std;

int main()
{
	int b = 5;
	int &a = b;
	int &c = b;
	b = 7;
	a = 8;
	printf("%d\n", 1 << 21);

	return 0;
}