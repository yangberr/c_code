#include <stdio.h>
#include <string.h>
void test1()
{
	int a[5] = { 1,2,3,4,5 };
	int *ptr = (int *)(&a + 1);
	printf("%d %d", *(a + 1), *(ptr - 1));

}

struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];

} *p ;

void test2()
{
	//假设P的值为0x100000，如下表达式的值分别为多少？
	//已知，结构体Test变量大小是20个字节
	p = (struct Test*)0x1000000;
	printf("%p\n", p + 0x1);//指针加结构体大小
	printf("%p\n", (unsigned long)p + 0x1);//指针转换成整形加1
	printf("%p\n", (unsigned int*)p + 0x1);//指针转换成整形地址加1(4个字节)

}

void test3()
{
	int a[4] = { 1,2,3,4 };//小端存储
	int *ptr1 = (int *)(&a + 1);   //&a+1指针指向数组尾部
	int *ptr2 = (int *)((int)a + 1);//将a的首地址转换成整数再加1,相当于地址加1,再转成int指针
	printf("%x , %x", ptr1[-1], *ptr2);
}

void test4() 
{
	int a[3][2] = { (0,1),(2,3),(4,5) };
	int *p;
	p = a[0];
	printf("%d", p[0]);

}

void test5()
{
	int a[5][5];
	int (*p)[4];//此编译器语法不通过
	//p = a;// int (*)[4] 0 --- int (*)[5]
	//printf("%p,%d\n",&p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

}

void test6()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
}

void test7()
{
	const char *a[] = {"work","at","alibaba" };//
	const char **pa = a;//char*类型接收 a 数组名表示首元素地址
	pa++;
	printf("%s\n", *pa);

}

void test8()
{
	const char *c[] = { "ENTER","NEW","POINT","FIRST" };
	const char* *cp[] = { c + 3,c + 2,c + 1,c };
	const char** *cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1]+ 1);
}

int main()
{

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	return 0;
}