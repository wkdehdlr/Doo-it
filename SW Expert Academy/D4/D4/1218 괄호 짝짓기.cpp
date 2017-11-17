#pragma warning(disable:4996)
#include<cstdio>
#include<stack>
using namespace std;


int main()
{
	char temp[300];
	int length;
	char stack_top;
	bool flag = false;

	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &length);
		scanf("%s", temp);
		flag = false;
		stack<char> st;
		printf("#%d ", tc + 1);
		for (int i = 0; i < length; ++i)
		{
			if (temp[i] == '('|| temp[i] == '{'|| temp[i] == '['|| temp[i] == '<')
			{
				st.push(temp[i]);
			}
			else
			{
				if (!st.empty())
				{
					stack_top = st.top();
					switch (temp[i])
					{
					case ')':if (stack_top == '(')st.pop(); else flag = true; break;
					case '}':if (stack_top == '{')st.pop(); else flag = true; break;
					case ']':if (stack_top == '[')st.pop(); else flag = true; break;
					case '>':if (stack_top == '<')st.pop(); else flag = true; break;
					}
				}
				else
				 flag = true;
				
				if (flag == true)
				{
					printf("0\n");
					break;
				}
			}
		}

		if (flag == false)
		{
			if (st.empty())
				printf("1\n");
			else
				printf("0\n");
		}
	}
}