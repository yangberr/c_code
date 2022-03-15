#include <stdio.h>
#include <string.h>

typedef struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_age(const void*e1 ,const void*e2)//����ȽϺ���
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;//�ȽϽṹ���Ա������ 
}

int cmp_stu_by_name(const void*e1 , const void*e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);

}

void print(struct Stu s1[] , int n)//�����ӡ����
{
	int i = 0;
	for (i = 0; i <= n - 1; i++)
	{
		printf("%s ", s1[i].name);
		printf("%d ", s1[i].age);
		printf("\n");
	}
}

void swap(char* buf1 , char* buf2 ,int width) //char*���� char*����
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

void bubble_sort(void*base , int sz , int width ,int(*cmp(void*e1 , void*e2)) )//����ð�������� �ο�qsort  int(*cmp(void*e1 , void*e2)���ձȽϺ����ĵ�ַ
{
	int i = 0;
	
	for (i = 0; i < sz - 1; i++)//����
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{ //ÿһ�˱Ƚ��ٵĶ���
			int k = cmp((char*)base + j * width, (char*)base + (j + 1)*width);
			if (k > 0) //ͨ����ַ������������Ԫ��  char* ���͵�ַռһ���ֽ� ��ֱ�Ӽ��Ͽ�ȷ�����һ��Ԫ��
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
	//qsortʹ�÷��� 1.����Ƚ�Ԫ�ص���ʼ��ַ  2.����Ԫ�ظ���  3.����һ��Ԫ����ռ��ȣ��ֽڣ� 4.����ȽϷ���������ַ
	//qsort(s1, sz, sizeof(s1[0]) , cmp_stu_by_age );
	//ð�����������κ���������
	bubble_sort(s1, sz, sizeof(s1[0]), cmp_stu_by_name);
	
	print(s1 , sz );
}

int main()
{
	
	test();
	return 0;
}