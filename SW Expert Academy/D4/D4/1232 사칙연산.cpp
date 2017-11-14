#pragma warning(disable : 4996)
#include<iostream>
#include<stack>
#include<stdio.h>
#include<sstream>
using namespace std;

struct node {
	int left;
	double data;
	int right;
};

node arr[1001];
int N;
stack<double> st;
void order(int);


int main()
{
	char str[100];
	int temp_num=0;
	int node_num = 0;
	for (int t = 0; t < 10; t++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &node_num);
			scanf("%s", str);
			/*

			stoi를 못쓰는 상황에서 atoi 구현 개쩌는방법 ㅅㅂ
			직접구현했지만 지저분하지않고 존나깔끔함

			*/
			arr[node_num].left = 0; arr[node_num].right = 0;
		}
		order(1);
		printf("#%d %d\n", t + 1, (int)st.top());
		st.pop();
	}
}
void order(int node_num)
{
	if (arr[node_num].data != 0)
	{
		order(arr[node_num].left);
		order(arr[node_num].right);
		if (arr[node_num].data == 42 || arr[node_num].data == 43 || arr[node_num].data == 45 || arr[node_num].data == 47)
		{
			double num2 = st.top(); st.pop();
			double num1 = st.top(); st.pop();
			double temp;
			if (arr[node_num].data == 42)//*
			{
				temp = num1 * num2;
			}
			else if (arr[node_num].data == 43)//+
			{
				temp = num1 + num2;
			}
			else if (arr[node_num].data == 45)//-
			{
				temp = num1 - num2;
			}
			else// /
			{
				temp = num1 / num2;
			}
			st.push(temp);
		}
		else//숫자면 stack에 넣는다.
		{
			st.push(arr[node_num].data);
		}
	}
}