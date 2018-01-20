#pragma warning(disable : 4996)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<char> vec = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t' };
	printf("%d\n", vec.size());
	int cnt = 0;
	FILE *fp = fopen("output.txt", "w");
	do {
		for (char x : vec)
		{
			fprintf(fp, "%c", x);
		}
		fprintf(fp, "\n");
		cnt++;
		if (cnt == 500000)break;
	} while (next_permutation(vec.begin(),vec.end()));
	fclose(fp);
}