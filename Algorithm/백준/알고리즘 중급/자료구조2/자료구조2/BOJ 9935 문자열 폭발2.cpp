#include<iostream>
using namespace std;

char str[1000001];
char bomb[37];
char res[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin >> str >> bomb;

	int lenS, lenB, lenR = 0 , idx = 0;
	for (lenB = 0; bomb[lenB] != '\0'; ++lenB);
	for (lenS = 0; str[lenS] != '\0'; ++lenS)
	{
		res[idx++] = str[lenS];
		if (res[idx - 1] == bomb[lenB - 1])
		{
			bool flag = true;
			for (int tmp_idx = 0; tmp_idx < lenB; ++tmp_idx)
			{
				if (bomb[tmp_idx] != res[idx - lenB + tmp_idx])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				idx -= lenB;
			}
		}
	}
	res[idx] = str[lenS];
	for (lenR = 0; res[lenR] != '\0'; ++lenR);
	if (lenR)
		cout << res;
	else
		cout << "FRULA";

	return 0;
}