#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;



int main()
{
	vector<int> vec;
	vec.push_back(34);	vec.push_back(33);	vec.push_back(33);
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
		int res = stoi(str);

	} while (prev_permutation(vec.begin(), vec.end()));
	/*
	do {
		for (int i = 0; i < 3; ++i)
		{
			printf("%d", vec[i]);
		}
		printf("\n");

	} while (next_permutation(vec.begin(), vec.end()));	*/
}