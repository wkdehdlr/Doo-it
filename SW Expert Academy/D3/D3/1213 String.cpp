#pragma warning(disable : 4996)
#include<iostream>
#include<string>
using namespace std;



int main()
{
	string str;
	string find_str;
	int num;


	for (int tc = 0; tc < 10; tc++)
	{
		int index = 0;
		getline(cin, find_str);
	//	num = stoi(find_str);
		getline(cin, find_str);
		getline(cin, str);
		int length = find_str.length();
		int cnt = 0;

		index = str.find(find_str);
		cout << index << '\n';
		
		if (index != -1)
		{
			//index = str.find(find_str);//처음찾은위치
			cnt++;
			index = str.find(find_str, index + length);
			while (index != -1)
			{
				index = str.find(find_str, index + length);
				cnt++;
			}
			cout << "#" << tc + 1 << " " << cnt << '\n';
			//cout << "#" + (tc + 1) +  + cnt << '\n';
			//printf("#%d %d\n", tc + 1, cnt);
		}
		else//못찾으면
		{
			printf("#%d %d\n", tc + 1, 0);
		}
	}
}