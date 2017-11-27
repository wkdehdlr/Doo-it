#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main()
{
	char num[6];//최대 99999 5자리까지 입력가능하고 뒤에 널문자
	char length;//입력받은숫자의 자릿수 저장 5자리가 최대이므로 굳이 int로 선언할 필요가 없다.
				
	scanf("%s", num);
	length = strlen(num);

	for (char i = 0; i < length; ++i)
	{
		switch (num[i])//if else를 안쓰고 switch를 쓴 이유는 
					   //if else는 계속 비교해야하는데 
					   //switch는 해당케이스로 바로 이동하기 때문에
					   //불필요한 오버헤드를 줄일 수 있다.
		{
		case '0':continue;
		case '1':if (i == length - 1)printf("일"); break;
		case '2':printf("이"); break;
		case '3':printf("삼"); break;
		case '4':printf("사"); break;
		case '5':printf("오"); break;
		case '6':printf("육"); break;
		case '7':printf("칠"); break;
		case '8':printf("팔"); break;
		case '9':printf("구"); break;
		}

		switch (length - 2 - i)
		{
		case 0:printf("십"); break;
		case 1:printf("백"); break;
		case 2:printf("천"); break;
		case 3:printf("만"); break;
		}
	}

	printf("\n");
	return 0;
}

/*
int main()
{
	char num[6];//최대 99999 5자리까지 입력가능하고 뒤에 널문자
	char length = 0;//입력받은숫자의 자릿수 저장 5자리가 최대이므로 굳이 int로 선언할 필요가 없다.

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
				printf("일"); 
				break;
			}
		}
		else if (num[i] == '2')
		{
			printf("이");
		}
		else if (num[i] == '3')
		{
			printf("삼");
		}
		else if (num[i] == '4')
		{
			printf("사");
		}
		else if (num[i] == '5')
		{
			printf("오");
		}
		else if (num[i] == '6')
		{
			printf("육");
		}
		else if (num[i] == '7')
		{
			printf("칠");
		}
		else if (num[i] == '8')
		{
			printf("팔");
		}
		else
		{
			printf("구");
		}
		
		if (length - 2 - i == 0)
		{
			printf("십");
		}
		else if (length - 2 - i == 1)
		{
			printf("백");
		}
		else if (length - 2 - i == 2)
		{
			printf("천");
		}
		else
		{
			printf("만");
		}
	}
	printf("\n");
	return 0;
}*/