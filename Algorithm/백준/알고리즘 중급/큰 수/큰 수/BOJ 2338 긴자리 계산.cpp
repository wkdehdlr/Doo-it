#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>

char num1[1005];
char num2[1005];
char res[1010];
int mul[2050];
int len_num1, len_num2, ori_num1, ori_num2;
bool flag = false;
int whichBig()
{
	if (num1[0] == '-')
	{
		for (int i = 1; i <= len_num1; ++i)
		{
			if (num1[i] > num2[i - 1])
				return 1;
			else if (num1[i] < num2[i - 1])
				return -1;
		}
		return 0;
	}
	else//num2[0]=='-';
	{
		for (int i = 1; i <= len_num2; ++i)
		{
			if (num1[i-1] > num2[i])
				return 1;
			else if (num1[i-1] < num2[i])
				return -1;
		}
		return 0;
	}
}
int whichBig2()
{
	if (num1[0] == '-')
	{
		for (int i = 1; i <= len_num1; ++i)
		{
			if (num1[i] > num2[i])
				return 1;
			else if (num1[i] < num2[i])
				return -1;
		}
		return 0;
	}
	else//num2[0]=='-';
	{
		for (int i = 0; i <= len_num1; ++i)
		{
			if (num1[i] > num2[i])
				return 1;
			else if (num1[i] < num2[i])
				return -1;
		}
		return 0;
	}
}

void plus()
{
	int tLen1 = len_num1;
	int tLen2 = len_num2;
	int tLen3 = 0;

	int limit1 = (num1[0] == '-' ? 1 : 0);
	int limit2 = (num2[0] == '-' ? 1 : 0);

	//�� ���� ��ȣ�� �ٸ���
	if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
	{
		//��ȣ ���̸� ����
		if (num1[0] == '-')len_num1--;
		if (num2[0] == '-')len_num2--;

		if (len_num1 > len_num2)//num1�� �� ���
		{
			bool carry = false;
			for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
			{
				int tmp = 0;
				if (tLen1 >= limit1)
					tmp += (num1[tLen1] - '0');
				if (tLen2 >= limit2)
					tmp -= (num2[tLen2] - '0');


				if (carry)
					tmp -= 1;

				if (tmp < 0)
				{
					tmp += 10;
					carry = true;
				}
				else
					carry = false;

				res[tLen3++] = tmp + '0';
			}
			if (num1[0] == '-')
				res[tLen3++] = '-';
		}
		else if (len_num1 == len_num2)//��ȣ�� �� ���̰� ����
		{
			//���̰� �������� ���밪�� ���� �� ū�� �˾ƾ���
			int which = whichBig();
			if (which == 1)//num1�� �� ŭ
			{
				bool carry = false;
				for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
				{
					int tmp = 0;
					if (tLen1 >= limit1)
						tmp += (num1[tLen1] - '0');
					if (tLen2 >= limit2)
						tmp -= (num2[tLen2] - '0');


					if (carry)
						tmp -= 1;

					if (tmp < 0)
					{
						tmp += 10;
						carry = true;
					}
					else
						carry = false;
					res[tLen3++] = tmp + '0';
				}
				if (num1[0] == '-')
					res[tLen3++] = '-';
			}
			else if (which == -1)//num2�� �� ŭ
			{
				bool carry = false;
				for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
				{
					int tmp = 0;
					if (tLen1 >= limit1)
						tmp -= (num1[tLen1] - '0');
					if (tLen2 >= limit2)
						tmp += (num2[tLen2] - '0');


					if (carry)
						tmp -= 1;

					if (tmp < 0)
					{
						tmp += 10;
						carry = true;
					}
					else
						carry = false;
					res[tLen3++] = tmp + '0';
				}
				if (num2[0] == '-')
					res[tLen3++] = '-';
			}
			else
			{
				flag = true;
				printf("0\n");
			}
		}
		else//num2�� �� ���
		{
			bool carry = false;
			for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
			{
				int tmp = 0;
				if (tLen1 >= limit1)
					tmp -= (num1[tLen1] - '0');
				if (tLen2 >= limit2)
					tmp += (num2[tLen2] - '0');


				if (carry)
					tmp -= 1;

				if (tmp < 0)
				{
					tmp += 10;
					carry = true;
				}
				else
					carry = false;
				res[tLen3++] = tmp + '0';
			}
			if (num2[0] == '-')
				res[tLen3++] = '-';
		}

		if (!flag)
		{
			int i = tLen3 - 1;
			if (res[i] == '-')
			{
				printf("%c", res[i--]);
				while (res[i] == '0')
					--i;
				for (; i >= 0; --i)
				{
					printf("%c", res[i]);
				}
				printf("\n");
			}
			else
			{
				while (res[i] == '0')
					--i;
				for (; i >= 0; --i)
				{
					printf("%c", res[i]);
				}
				printf("\n");
			}
		}
	}
	else//�� ���� ��ȣ�� ���� ��
	{
		int carry = 0;
		for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
		{
			int tmp = 0;
			if (tLen1 >= limit1)
				tmp += (num1[tLen1] - '0');
			if (tLen2 >= limit2)
				tmp += (num2[tLen2] - '0');
			if (carry)
				tmp += 1;

			if (tmp >= 10)
				carry = 1;
			else
				carry = 0;

			res[tLen3++] = (tmp % 10) + '0';
		}
		if (num1[0] == '-')
			printf("-");
		if (carry)
			printf("1");
		for (int i = tLen3 - 1; i >= 0; --i)
		{
			printf("%c", res[i]);
		}
		printf("\n");
	}
}

void minus()
{
	int tLen1 = len_num1;
	int tLen2 = len_num2;
	int tLen3 = 0;

	int limit1 = (num1[0] == '-' ? 1 : 0);
	int limit2 = (num2[0] == '-' ? 1 : 0);

	//�� ���� ��ȣ�� �ٸ� ��
	if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
	{
		int carry = 0;
		for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
		{
			int tmp = 0;
			if (tLen1 >= limit1)
				tmp += (num1[tLen1] - '0');
			if (tLen2 >= limit2)
				tmp += (num2[tLen2] - '0');
			if (carry)
				tmp += 1;

			if (tmp >= 10)
				carry = 1;
			else
				carry = 0;

			res[tLen3++] = (tmp % 10) + '0';
		}
		if (num1[0] == '-')
			printf("-");
		if (carry)
			printf("1");
		for (int i = tLen3 - 1; i >= 0; --i)
		{
			printf("%c", res[i]);
		}
		printf("\n");
	}
	else//�� ���� ��ȣ�� ���� ��
	{
		if (num1[0] == '-')len_num1--;
		if (num2[0] == '-')len_num2--;

		if (len_num1 > len_num2)//num1�� �� ���
		{
			bool carry = false;
			for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
			{
				int tmp = 0;
				if (tLen1 >= limit1)
					tmp += (num1[tLen1] - '0');
				if (tLen2 >= limit2)
					tmp -= (num2[tLen2] - '0');


				if (carry)
					tmp -= 1;

				if (tmp < 0)
				{
					tmp += 10;
					carry = true;
				}
				else
					carry = false;

				res[tLen3++] = tmp + '0';
			}
			if (num1[0] == '-')
				res[tLen3++] = '-';
		}
		else if (len_num1 == len_num2)//��ȣ�� �� ���̰� ����
		{
			//���̰� �������� ���밪�� ���� �� ū�� �˾ƾ���
			int which = whichBig2();
			if (which == 1)//num1�� �� ŭ
			{
				bool carry = false;
				for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
				{
					int tmp = 0;
					if (tLen1 >= limit1)
						tmp += (num1[tLen1] - '0');
					if (tLen2 >= limit2)
						tmp -= (num2[tLen2] - '0');


					if (carry)
						tmp -= 1;

					if (tmp < 0)
					{
						tmp += 10;
						carry = true;
					}
					else
						carry = false;
					res[tLen3++] = tmp + '0';
				}
				if (num1[0] == '-')
					res[tLen3++] = '-';
			}
			else if (which == -1)//num2�� �� ŭ
			{
				bool carry = false;
				for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
				{
					int tmp = 0;
					if (tLen1 >= limit1)
						tmp -= (num1[tLen1] - '0');
					if (tLen2 >= limit2)
						tmp += (num2[tLen2] - '0');


					if (carry)
						tmp -= 1;

					if (tmp < 0)
					{
						tmp += 10;
						carry = true;
					}
					else
						carry = false;
					res[tLen3++] = tmp + '0';
				}
				if (num2[0] != '-')
					res[tLen3++] = '-';
			}
			else
			{
				flag = true;
				printf("0\n");
			}
		}
		else//num2�� �� ���
		{
			bool carry = false;
			for (--tLen1, --tLen2; tLen1 >= limit1 || tLen2 >= limit2; --tLen1, --tLen2)
			{
				int tmp = 0;
				if (tLen1 >= limit1)
					tmp -= (num1[tLen1] - '0');
				if (tLen2 >= limit2)
					tmp += (num2[tLen2] - '0');


				if (carry)
					tmp -= 1;

				if (tmp < 0)
				{
					tmp += 10;
					carry = true;
				}
				else
					carry = false;
				res[tLen3++] = tmp + '0';
			}
			if (num2[0] != '-')
				res[tLen3++] = '-';
		}

		if (!flag)
		{
			int i = tLen3 - 1;
			if (res[i] == '-')
			{
				printf("%c", res[i--]);
				while (res[i] == '0')
					--i;
				for (; i >= 0; --i)
				{
					printf("%c", res[i]);
				}
				printf("\n");
			}
			else
			{
				while (res[i] == '0')
					--i;
				for (; i >= 0; --i)
				{
					printf("%c", res[i]);
				}
				printf("\n");
			}
		}
	}
}

void multiply()
{
	if (num1[0] == '0' || num2[0] == '0')
	{
		printf("0\n");
		return;
	}


	int tLen = 0;
	int limit1 = (num1[0] == '-' ? 1 : 0);
	int limit2 = (num2[0] == '-' ? 1 : 0);

	if (num1[0] == '-')len_num1--;
	if (num2[0] == '-')len_num2--;

	int start1 = (num1[0] == '-' ? len_num1 : len_num1 - 1);
	int start2 = (num2[0] == '-' ? len_num2 : len_num2 - 1);


	if (len_num1 > len_num2)//num1�� �� ��� num1�� num2�� ���Ѵ�
	{
		int carry = 0;
		for (int i = start2; i >= limit2; --i)
		{
			carry = 0;
			tLen = ori_num2 - i - 1;
			for (int j = start1; j >= limit1; --j)
			{
				int tmp = (num1[j] - '0') * (num2[i] - '0');
				if (carry)
					tmp += carry;
				else
					carry = 0;

				int ans = tmp % 10;
				carry = tmp / 10;
				mul[tLen] += ans;
				if (mul[tLen] >= 10)
				{
					mul[tLen] %= 10;
					carry++;
				}
				tLen++;
			}
			if (carry)
				mul[tLen++] = carry;
		}
	}
	else//num2�� �� ��� num2�� num1�� ���Ѵ�
	{
		int carry = 0;
		for (int i = start1; i >= limit1; --i)
		{
			carry = 0;
			tLen = ori_num1 - i - 1;
			for (int j = start2; j >= limit2; --j)
			{
				int tmp = (num2[j] - '0') * (num1[i] - '0');
				if (carry)
					tmp += carry;
				else
					carry = 0;

				int ans = tmp % 10;
				carry = tmp / 10;
				mul[tLen] += ans;
				if (mul[tLen] >= 10)
				{
					mul[tLen] %= 10;
					carry++;
				}
				tLen++;
			}
			if (carry)
				mul[tLen++] = carry;
		}
	}

	if ((num1[0] == '-' && num2[0] != '-') || (num2[0] == '-' && num1[0] != '-'))
		printf("-");

	for (int i = tLen - 1; i >= 0; --i)
	{
		printf("%d", mul[i]);
	}
	printf("\n");
}
void initialize()
{
	flag = false;
	len_num1 = ori_num1;
	len_num2 = ori_num2;
	for (int i = 0; i < 1010; ++i)res[i] = '\0';
}
bool check()
{
	if (num1[0] == '-' && num1[1] == '0')
	{
		num1[0] = '0';
		num1[1] = '\0';
	}
	if (num2[0] == '-' && num2[1] == '0')
	{
		num2[0] = '0';
		num2[1] = '\0';
	}
}
int main()
{
	scanf("%s", num1);
	scanf("%s", num2);
	check();
	ori_num1 = len_num1 = strlen(num1);
	ori_num2 = len_num2 = strlen(num2);
	
	initialize();
	plus();
	initialize();
	minus();
	initialize();
	for (int i = 0; i < 2050; ++i)mul[i] = 0;
	multiply();	
}