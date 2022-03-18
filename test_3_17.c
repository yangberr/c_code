#include <stdio.h>

void test1()
{
	//      1
	//	  1 2 1
	//  1  3  3 1
	//1  4   6  4  1 
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			if (i == j)
				arr[i][j] = 1;
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

			}
		}

	}
	int z = 0;
	for (i = 0; i < 10; i++)
	{
		z = 10 - i;
		for (j = 0; j <= i ; j++)
		{
			while (z)
			{ 
				z -= 1;
				printf(" ");
			}
			printf("%d  ", arr[i][j]);
		}
		printf("\n");

	}

}

void test2()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a' ) + (killer == 'c') + (killer == 'd') + ( killer!= 'd') == 3) //a说不是我，b说是c c说是d d说c在胡说 
		{
			printf("killer = %c", killer);
		}
	}
}

int main()
{

	test1();//打印杨辉三角
	test2();//猜凶手   赛马问题 烧香问题（牛客网智力题）
	return 0;
}