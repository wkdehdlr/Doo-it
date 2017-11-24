#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

map<long long, int> ma;
vector<int> vec;
int T, N, P;
void func(vector<int>);
int main()
{
	vector<int> vec_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		vec.clear();
		scanf("%d %d", &N, &P);
		vec.push_back(N - P + 1);
		for (int i = 0; i < P - 1; ++i)
		{
			vec.push_back(1);
		}
		vec_temp = vec;
		func(vec_temp);
	}
}
void func(vector<int> vect)
{
	if (1)
	{

	}
	else
	{
		for (int i = 0; i < P - 1; ++i)
		{
			for (int j = i + 1; j < P; ++j)
			{
				if (vect[i] != 1)
				{
					vect[i]--;
					vect[j]++;
					char temp[10];

					do {
						string str;
						for (int i = 0; i < 3; ++i)
						{
							itoa(vec[i], temp, 10);
							for (int j = 0; temp[j] != '\0'; ++j)
							{
								str.push_back(temp[j]);
							}
						}
						long long res = stoll(str);
						if (ma.count(res))
							break;
						else
							ma[res] = 1;
					} while (prev_permutation(vec.begin(), vec.end()));
				}
			}
		}
	}
}