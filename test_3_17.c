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
		if ((killer != 'a' ) + (killer == 'c') + (killer == 'd') + ( killer!= 'd') == 3) //a˵�����ң�b˵��c c˵��d d˵c�ں�˵ 
		{
			printf("killer = %c", killer);
		}
	}
}

int main()
{

	test1();//��ӡ�������
	test2();//������   �������� �������⣨ţ���������⣩
	return 0;
}