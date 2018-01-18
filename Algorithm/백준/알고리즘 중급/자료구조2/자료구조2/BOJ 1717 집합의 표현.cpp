#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
using namespace std;

int arr[1000001];
int N, M;
int find(int num)
{
	if (arr[num] == num)return num;
	else return arr[num] = find(arr[num]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return;
	arr[b] = a;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin >> N >> M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		arr[i] = i;
	for (int i = 0; i < M; ++i)
	{
		int tmp, num1, num2;
		scanf("%d %d %d", &tmp, &num1, &num2);
		//cin >> tmp >> num1 >> num2;
		if (tmp)
		{
			if (find(num1) == find(num2))
				printf("YES\n");
			//cout << "YES" << '\n';
			else
				printf("NO\n");
				//cout << "NO" << '\n';
		}
		else
		{
			merge(num1,num2);
		}
	}
}