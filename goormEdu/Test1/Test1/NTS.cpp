#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main()
{
	char num[6];//�ִ� 99999 5�ڸ����� �Է°����ϰ� �ڿ� �ι���
	char length;//�Է¹��������� �ڸ��� ���� 5�ڸ��� �ִ��̹Ƿ� ���� int�� ������ �ʿ䰡 ����.
				
	scanf("%s", num);
	length = strlen(num);

	for (char i = 0; i < length; ++i)
	{
		switch (num[i])//if else�� �Ⱦ��� switch�� �� ������ 
					   //if else�� ��� ���ؾ��ϴµ� 
					   //switch�� �ش����̽��� �ٷ� �̵��ϱ� ������
					   //���ʿ��� ������带 ���� �� �ִ�.
		{
		case '0':continue;
		case '1':if (i == length - 1)printf("��"); break;
		case '2':printf("��"); break;
		case '3':printf("��"); break;
		case '4':printf("��"); break;
		case '5':printf("��"); break;
		case '6':printf("��"); break;
		case '7':printf("ĥ"); break;
		case '8':printf("��"); break;
		case '9':printf("��"); break;
		}

		switch (length - 2 - i)
		{
		case 0:printf("��"); break;
		case 1:printf("��"); break;
		case 2:printf("õ"); break;
		case 3:printf("��"); break;
		}
	}

	printf("\n");
	return 0;
}

/*
int main()
{
	char num[6];//�ִ� 99999 5�ڸ����� �Է°����ϰ� �ڿ� �ι���
	char length = 0;//�Է¹��������� �ڸ��� ���� 5�ڸ��� �ִ��̹Ƿ� ���� int�� ������ �ʿ䰡 ����.

	scanf("%s", num);
	length = strlen(num);

	for (char i = 0; i < length; ++i)
	{
		if (num[i] == '0')
		{
			continue;
		}
		else if (num[i] == '1')
		{
			if (i == length - 1)
			{
				printf("��"); 
				break;
			}
		}
		else if (num[i] == '2')
		{
			printf("��");
		}
		else if (num[i] == '3')
		{
			printf("��");
		}
		else if (num[i] == '4')
		{
			printf("��");
		}
		else if (num[i] == '5')
		{
			printf("��");
		}
		else if (num[i] == '6')
		{
			printf("��");
		}
		else if (num[i] == '7')
		{
			printf("ĥ");
		}
		else if (num[i] == '8')
		{
			printf("��");
		}
		else
		{
			printf("��");
		}
		
		if (length - 2 - i == 0)
		{
			printf("��");
		}
		else if (length - 2 - i == 1)
		{
			printf("��");
		}
		else if (length - 2 - i == 2)
		{
			printf("õ");
		}
		else
		{
			printf("��");
		}
	}
	printf("\n");
	return 0;
}*/