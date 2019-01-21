#include<cstdio>
#include<cmath>
#define PI 3.14159265
using namespace std;

int n, r;
long double R;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &r);
	long double va = sin((long double)PI / (long double)n);
	printf("%.7Lf\n", (long double)r*(va / ((long double)1 - va)));
}