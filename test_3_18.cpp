#include <stdio.h>
#include <string.h>
#include <assert.h>

void move_arr(char* str ,int k, int n)//�������
{
	assert(str);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		char temp = *str;
		int j = 0;
		for (j = 0; j < n - 1; j++)//������Ԫ��ǰ��
		{
			//*str = *(str + 1);//���ַ�ָ��ת������ָ���ٽ���ָ���������
			//str++;
			*(str + j) = *(str + j + 1);

		}
		*(str + n - 1) = temp;
	}

}
void reverse(char* arr ,int n)
{
	char* left = arr;
	char* right = arr + n - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

}

void move_arr2(char* str , int k)
{
	assert(str);
	int len = strlen(str);//abcdef
	reverse(str , k);
	reverse(str + k ,len - k);
	reverse(str ,len);
}

void test1()
{
	char arr[] = "abcdef";
	int len = strlen(arr);
	//move_arr(arr, 3 , len);
	//move_arr2(arr ,4);//������ת��
	printf("%s\n", arr);
	
}

int Is_converse(char* str1 , char* str2 )
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	else
	{
		int i = 0;
		for (i = 0; i < len1; i++)
		{
			move_arr2(str1, 1);
			int flag = strcmp(str1, str2); //��ͬ����0
			if (0 == flag)
				return 1;
		}
		return 0;
	}


}
void my_strcpy(char* str1, char* str2, int len1, int len2)
{
	int i = 0;
	for (i = 0; i < len2; i++)
	{
		*(str1 + len1) = *(str2);
		str1++;
		str2++;

	}

}

int my_strcmp(char* str1, char* str2)
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (i = 0; i < len2; i++)
	{
		if (len2 > len1) //���str1����������С��str2ʱ��δ��� ��str1��str2�����
			return 0;
		if (*str1 != *str2)
			break;
		else
		{
			str1++;
			str2++;
		}
	}
	if(i == len2)
		return 1;
}


int Is_reverse(char* str1, char* str2)//׷���жϷ�
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	char* start1 = str1;
	char* start2 = str2;
    //strcpy(str1,  str1);//����str1������  strcmpֻ�ܴ����ַ���
	
	int i = 0;
	for (i = 0; i < len1 ; i++)//ѭ���ж�str1���Ƿ����str2
	{
		str1 = start1 + i;
		str2 = start2;
		int flag = my_strcmp(str1, str2);//����0��� ����1�����  //���Ӵ��⺯�� strstr(str1 ,str2) str1������str2 �ҵ����ص�ַ �Ҳ������ؿ�ָ��

		if (1 == flag)
			return 1;
		
	}
	return 0;
}


void test2()
{
	char arr1[15] = "abcdef";
	char arr2[12] = "cdef";
	int len1 = strlen(arr1);
	int len2 = strlen(arr1);
	printf("%d %d", len1, len2);
	my_strcpy(arr1, arr1, len1, len2);//�Զ���׷�Ӻ���  �⺯��strcat�����Լ�׷���Լ� �⺯��strncat ׷���Լ� 
    //int flag =  Is_converse(arr1 ,arr2);//�Ǿͷ���1 ���򷵻�0 �������
	
	int flag = Is_reverse(arr1 ,arr2);    //�Ǿͷ���1 ���򷵻�0                                //׷���жϷ�

	if (1 == flag)
	{
		printf("yes\n");
	}
	else
	{
		printf("no \n");
	}

}


void test()
{
	char arr1[15] = "abcdef";
	char arr2[12] = "ghijkl";
	int len1 = strlen(arr1);
	int len2 = strlen(arr1);
	printf("%d %d", len1, len2);
	//my_strcpy(arr1, arr2 ,len1, len2);
	//strcat(arr1, arr2);
	strncat(arr1, arr1 ,6);

	printf("%s", arr1);
}

int main()
{

	//test1();//��ת�ַ���
	//test2();//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮��õ�
	test();
	return 0;
}
