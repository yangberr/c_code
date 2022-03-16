#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>



void test1()
{
	unsigned long pulArray[] = { 6,7,8,9,10 };
	unsigned long *pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d", *pulPtr, *(pulPtr + 3));//6 , 12
}

void reverse1(char arr[] ,int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
void reverse2(char* arr)//递归实现字符串逆序
{
	//int len = strlen(arr);
	//char* left = arr;
	//char* right = arr + len - 1;
	//if (left > right)
	//	return;
	//char temp = *left;
	//*left = *right;
	//left++;
	//*right = '/0';
	//reverse2(arr);
	//*right = temp;
	assert(arr);
	int len = strlen(arr);
	char* left = arr;
	char* right = arr + len - 1;
	if (*left == 0)
		return;
	char temp = *left;
	*left = *right;
	*right = 0;
	arr++;
	reverse2(arr);
	*right = temp;
}

void test2()
{
	const char arr[] = "ni hao zhangsan!";
	int sz = strlen(arr);
	//reverse1(arr ,sz );
	//reverse2(arr);
	printf("%s\n", arr);
}

int my_add_a_n(int a , int n)
{
	int sum = 0;
	int x = a;
	int i = 1;
	int j = 1;
	//求 前n项之和 a +aa +aaa+ aaaa+ ...+
	while (i <= n)// 1          2
	{		
		j = j * 10;
		sum = sum + a;
		a = (x* j + a); 
		i++;
	}
	return sum;
}

int add_a_n(int a, int n)
{
	int i = 0;
	int sum = 0;
	int ret = 0;
	for (i = 0; i < n; i++)
	{
		ret = ret * 10 + a; 
		sum = sum + ret;   
	}
	return sum;
}

void test3()
{
	int a = 3;
	int n = 5;
	int sum1 = my_add_a_n(a, n);
	int sum2 = add_a_n(a, n);	
	printf("%d\n", sum1);
	printf("%d\n", sum2);

}
void my_self_mi(int n)
{
	int x = 0;
	int count = 0;
	int c = n;
	while (c)
	{
		c = c / 10;
		count++;//计算位数
	}
	int sum = 0;
	int y = n;
	while (n)
	{
		x = n % 10;  //3 5
		n = n / 10;  //15 1
		int ret = x;
		for (int i = 0; i < count-1; i++)
		{
			
			ret = ret * x;//求出每一位数的次方27  125
			
		}
		sum = sum + ret;
		//sum = sum + pow(x,count);//27 152 153 pow 求一个数的n次方函数 
	}
	if(sum == y)
	printf("%d  ", sum);
}

void test4()
{
	int i = 0;

	for (i = 100; i < 100000; i++)
	{
		my_self_mi(i);

	}

}

void test5()
{

	int line = 7;
	int i = 0;
	for (i = 0; i < line; i++)//控制行数
	{
		int j = 0;
		for (j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");

		}
		printf("\n");
	}
	for (i = line - 1; i > 0; i--)
	{
		int j = 0;
		for (j = 0; j < line - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//for (i = 0; i < line - 1; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j <= i; j++)
	//	{
	//		printf(" ");
	//	}
	//	for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

}


int main()
{

	//test1(); 
	//test2();//逆序字符串内容
	//test3();//计算求和
	//test4();//求1 -10000 的自幂数
	//test5();//打印菱形
	return 0;
}