#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <errno.h>

void test1()
{
	//size_t == unsigned int
	//int len1 = strlen("abcde");
	//printf("%d", len1);

	if (strlen("abc") - strlen("abcde") > 0)
	{
		printf("hehe");
	}
	else
	{
		printf("haha");
	}

	//err
	/*char arr[] = { 'a','b','c','d','e' };
	int len2 = strlen(arr);*/
	//printf("%d", len2);

}

void test2()//strtok()字符串拆分函数
{
	char arr[] = "1431@qq.com";
	char *p = "@.";
	char buf[1024] = { 0 };
	strcpy(buf, arr);
	char *ret = NULL;
	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}



}

void test3()
{
	//char *str = strerror(5);//将错误码翻译为错误信息
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	
	//char *str = strerror(errno);//errno是一个全局的错误码变量当c语言在执行过程中，发生了错误，就会把对应的错误码赋值到errno中
	//printf("%s\n", str);
}

int main()
{

	//test1();
	//test2();
	test3();
	return 0;
}