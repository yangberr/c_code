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
	//����P��ֵΪ0x100000�����±��ʽ��ֵ�ֱ�Ϊ���٣�
	//��֪���ṹ��Test������С��20���ֽ�
	p = (struct Test*)0x1000000;
	printf("%p\n", p + 0x1);//ָ��ӽṹ���С
	printf("%p\n", (unsigned long)p + 0x1);//ָ��ת�������μ�1
	printf("%p\n", (unsigned int*)p + 0x1);//ָ��ת�������ε�ַ��1(4���ֽ�)

}

void test3()
{
	int a[4] = { 1,2,3,4 };//С�˴洢
	int *ptr1 = (int *)(&a + 1);   //&a+1ָ��ָ������β��
	int *ptr2 = (int *)((int)a + 1);//��a���׵�ַת���������ټ�1,�൱�ڵ�ַ��1,��ת��intָ��
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
	int (*p)[4];//�˱������﷨��ͨ��
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
	const char **pa = a;//char*���ͽ��� a ��������ʾ��Ԫ�ص�ַ
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