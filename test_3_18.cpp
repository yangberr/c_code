#include <stdio.h>
#include <string.h>
#include <assert.h>

void move_arr(char* str ,int k, int n)//暴力求解
{
	assert(str);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		char temp = *str;
		int j = 0;
		for (j = 0; j < n - 1; j++)//将所有元素前移
		{
			//*str = *(str + 1);//将字符指针转换整形指针再进行指针运算操作
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
	//move_arr2(arr ,4);//三步翻转法
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
			int flag = strcmp(str1, str2); //相同返回0
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
		if (len2 > len1) //如果str1遍历到长度小于str2时还未相等 则str1和str2不相等
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


int Is_reverse(char* str1, char* str2)//追加判断法
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	char* start1 = str1;
	char* start2 = str2;
    //strcpy(str1,  str1);//复制str1中内容  strcmp只能处理字符串
	
	int i = 0;
	for (i = 0; i < len1 ; i++)//循环判断str1中是否存在str2
	{
		str1 = start1 + i;
		str2 = start2;
		int flag = my_strcmp(str1, str2);//返回0相等 返回1不相等  //找子串库函数 strstr(str1 ,str2) str1里面找str2 找到返回地址 找不到返回空指针

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
	my_strcpy(arr1, arr1, len1, len2);//自定义追加函数  库函数strcat不能自己追加自己 库函数strncat 追加自己 
    //int flag =  Is_converse(arr1 ,arr2);//是就返回1 否则返回0 暴力求解
	
	int flag = Is_reverse(arr1 ,arr2);    //是就返回1 否则返回0                                //追加判断法

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

	//test1();//旋转字符串
	//test2();//写一个函数，判断一个字符串是否为另外一个字符串旋转之后得到
	test();
	return 0;
}
