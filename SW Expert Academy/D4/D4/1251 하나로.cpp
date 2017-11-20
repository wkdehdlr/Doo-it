#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;


char tmp[10];
int fac_N = 1;
int T, N;
double E;
long long minN;
vector<vector<int> > arr(1001, vector<int>(2,0));
vector<int> next_pe;

long long calc(int);
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		fac_N = 1;
		minN = 9223372036854775807;
		next_pe.clear();
		scanf("%d", &N);
		next_pe.resize(N);
		for (int i = 0; i < N; ++i)
		{
			next_pe[i] = i + 1;
		}
		for (int i = 1; i <= N; ++i)
		{
			fac_N *= i;
		}

		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &arr[i][0]);
		}
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &arr[i][1]);
		}
		scanf("%lf", &E);
		//E = atof(tmp);
		
		/*for (int i = 0; tmp[i] != '\0'; ++i)
		{
			if (tmp[i] != '.')
			{
				E *= 10;
				E += tmp[i] - '0';
			}
		}
		for (int i = 0; i < strlen(tmp) - 2; ++i)
		{
			E *= 0.1;
		}*/


		long long sum = 0;
		long long temp = 0;
		int cnt = 1;

		for (int i = 0; i < N - 1; ++i)
		{
			temp = calc(i);
			sum += (temp*temp);
		}
		sum *= E;
		minN = sum;
		cnt++;
		next_permutation(next_pe.begin(), next_pe.end());
		if (N != 2)
		{
			while (1)
			{
				sum = 0;
				for (int i = 0; i < N - 1; ++i)
				{
					temp = calc(i);
					sum += (temp*temp);
				}
				sum *= E;
				if (minN > sum)
					minN = sum;

				if (cnt == fac_N / 2)
					break;
				cnt++;
				next_permutation(next_pe.begin(), next_pe.end());
			}
		}

		printf("#%d %lld\n", tc + 1, minN);
	}
}
long long calc(int i)
{
	long long x1 = arr[next_pe[i]][0];
	long long x2 = arr[next_pe[i + 1]][0];
	long long y1 = arr[next_pe[i]][1];
	long long y2 = arr[next_pe[i + 1]][1];
	return sqrtl(powl(x1 - x2, 2) + powl(y1 - y2, 2));
}