#include <stdio.h>
#include <string.h>

typedef struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_age(const void*e1 ,const void*e2)//定义比较函数
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;//比较结构体成员的年龄 
}

int cmp_stu_by_name(const void*e1 , const void*e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);

}

void print(struct Stu s1[] , int n)//定义打印函数
{
	int i = 0;
	for (i = 0; i <= n - 1; i++)
	{
		printf("%s ", s1[i].name);
		printf("%d ", s1[i].age);
		printf("\n");
	}
}

void swap(char* buf1 , char* buf2 ,int width) //char*传入 char*接收
{
	int i = 0;
	for (i = 0; i < width ; i++)
	{
		char* temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void*base , int sz , int width ,int(*cmp(void*e1 , void*e2)) )//定义冒泡排序函数 参考qsort  int(*cmp(void*e1 , void*e2)接收比较函数的地址
{
	int i = 0;
	
	for (i = 0; i < sz - 1; i++)//趟数
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{ //每一趟比较少的对数
			int k = cmp((char*)base + j * width, (char*)base + (j + 1)*width);
			if (k > 0) //通过地址访问相邻两个元素  char* 类型地址占一个字节 可直接加上宽度访问下一个元素
			{
				swap((char*)base + j * width, (char*)base + (j + 1)*width ,  width);
			}

		}

	}

}


void test()
{
	struct Stu s1[3] = { { "zhangsan",18},{"wangwu",30},{"lisi",11}   };
	int sz = sizeof(s1) / sizeof(s1[0]);
	//qsort使用方法 1.传入比较元素的起始地址  2.传入元素个数  3.传入一个元素所占宽度（字节） 4.传入比较方法函数地址
	//qsort(s1, sz, sizeof(s1[0]) , cmp_stu_by_age );
	//冒泡排序满足任何数据类型
	bubble_sort(s1, sz, sizeof(s1[0]), cmp_stu_by_name);
	
	print(s1 , sz );
}

int main()
{
	
	test();
	return 0;
}