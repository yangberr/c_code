#include <stdio.h>

//int FindNum(int arr[5][5], int n , int row ,int col)
//{
//	//��ά����ȡ��ÿ��Ԫ���׵�ַ(��һ�еĵ�ַ)
//	int x = 0;	     //�к�
//	int y = col - 1;//�к�
//	while (x <= col - 1, y >= 0) 
//	{
//		if (arr[x][y] > n)
//		{
//			y--;
//		}
//		else if (arr[x][y] < n)
//		{
//			x++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//
//}

int FindNum(int arr[5][5], int n , int *px ,int *py)
{
	//��ά����ȡ��ÿ��Ԫ���׵�ַ(��һ�еĵ�ַ)
	int x = 0;	     //�к�
	int y = *py - 1;//�к�
	while (x <= *px - 1, y >= 0) 
	{
		if (arr[x][y] > n)
		{
			y--;
		}
		else if (arr[x][y] < n)
		{
			x++;
		}
		else
		{
			*px = x + 1;
			*py = y + 1;
			return 1;
		}
	}

}

void test1()
{	//���Ͼ���

	int arr[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int  k = 15;
	int x = 5;
	int y = 5;
	int ret = FindNum(arr, k ,&x ,&y );
	if (1 == ret)
	{
		printf("�ҵ��ˣ�\n");
		printf("%d %d", x, y);
	}
	else
	{
		printf("û�ҵ���\n");
	}

}

int main()
{

	test1();
	return 0;
}