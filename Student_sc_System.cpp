#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

//定义结构体
typedef struct Student_Node
{
	int id;           //学号
	char name[50];	  //姓名
	char sex[10];	  //性别
	int ch, ma, en;	  //语数外成绩
	int sum;		  //总成绩
	struct Student_Node *next; //定义指针域
}Student_Node;
Student_Node List;//链表

void display_menu();//打印菜单
void Add_Student(Student_Node *L);//增加学生信息  
int Fix_Student(Student_Node *L);//修改学生信息
int Det_Student(Student_Node *L);//删除学生信息
int Search_Student(Student_Node *L);//查找学生信息
void Print_Student(Student_Node *L);//输出学生信息
void my_Exit();//退出系统
void insertStuIfo(Student_Node *L, Student_Node s);//插入节点函数
int Search_Id(Student_Node *L , int s_id);//学好查重函数
int Find_Max_Sc(Student_Node *L, int mode);//查找最高分数
void My_Sort(Student_Node *L );//自定义排序函数 实现可按照学号以及各科成绩进行链表的排序 调用qsort 
int Node_Swap(Student_Node *node1, Student_Node *node2 ,int ch);//定义判断函数

//读取文件
int readFile(Student_Node *L);//定义链表指针
//写入文件
int writeFile(Student_Node *L);



int main()
{
	int choice = 0;
	int i = 0;
	readFile(&List);
	display_menu();//菜单打印

	do
	{
	
		printf("请选择功能:\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
			
		case 1://增加学生信息
			Add_Student(&List);
			break;
		case 2://修改学生信息
			i = Fix_Student(&List);
			if (i == 1) 
			{
				printf("修改成功！\n");
			}
			else
			{
				printf("修改失败!\n");
			}
			break;
		case 3://删除学生信息
		    i = Det_Student(&List);
			if (i == 1)
			{
				printf("删除成功！\n");
			}
			else
			{
				printf("失败!\n");
			}
			break;
		case 4://查询学生信息
			i = Search_Student(&List);
			if (0 != i)
			{
				printf("查找失败！\n");
			}
			break;
		case 5://输出学生信息
			Print_Student(&List);
			break;
		case 6:
			My_Sort(&List);
			break;
		case 0://退出系统
			my_Exit();
			break;
		default:
			printf("输入错误，请重新输入:\n");
			break;
		}
		
	} while (choice);

	return 0;
}

void display_menu() 
{
	//system("cls");
	printf("--------------------------------\n");
	printf("--------------------------------\n");
	printf("----欢迎使用学生成绩管理系统----\n");
	printf("-----    1. 增加学生信息    ----\n");
	printf("-----    2. 修改学生信息    ----\n");
	printf("-----    3. 删除学生信息    ----\n");
	printf("-----    4. 查询学生信息    ----\n");
	printf("-----    5. 输出学生信息    ----\n");
	printf("-----    6. 排序学生信息    ----\n");
	printf("-----    0. 退出管理系统    ----\n");
	printf("--------------------------------\n");
	printf("--------------------------------\n");
}

void Add_Student(Student_Node *L)//增加学生信息
{
	Student_Node s;
	Student_Node *p = L;
	printf("请输入新增学生信息:\n");
	printf("学号:\n");
	int s_id = 0;
    start1:scanf("%d",&s_id);
	//assert(s_id < 20220001 && s_id>202201000);
	int ret = Search_Id(L, s_id);
	if (1 == ret)
	{
		s.id = s_id;
	}
	else if (0 == ret)
	{
		printf("该学号已存在！请重新输入:\n");
		goto start1;
	}
	printf("姓名:\n");
	scanf("%s", s.name);
	printf("性别:\n");
	scanf("%s", s.sex);
	printf("语文分数:\n");
	scanf("%d", &s.ch);
	printf("数学分数:\n");
	scanf("%d", &s.ma);
	printf("英语分数:\n");
	scanf("%d", &s.en);
	s.sum = (s.ch + s.en + s.ma);

	insertStuIfo(&List, s);//定义插入函数 
	
}

int Fix_Student(Student_Node *L)//修改学生信息
{
	Student_Node *p = L;
	int chioce = 0;
	printf("请输入要修改学生的学号:\n");
	int id = 0;
	scanf("%d", &id);
	int s_id = 0;//定义修改后的id
	int ret = 0;//判断id是否存在标志
	

	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("查找到您要修改的学生:\n");
			printf("------------------------------------------------------\n");
			printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			printf("请选择需要修改的信息:\n");
			printf("学号 - 1\t姓名 - 2\t性别 - 3\t语文分数 - 4\t数学分数 - 5\t英语分数 - 6 \n");
			scanf("%d", &chioce);
			switch (chioce)
			{
			case 1:
				printf("学号:\n");
			    start:scanf("%d", &s_id);
				ret = Search_Id(L , s_id);
				if (1 == ret)
				{
					p->id = s_id;
				}
				else if(0 == ret)
				{
					printf("该学号已存在！请重新输入:\n");
					goto start;
				}

				break;
			case 2:
				printf("姓名:\n");
				scanf("%s", p->name);
				break;

			case 3:
				printf("性别:\n");
				scanf("%s", p->sex);
				break;
			case 4:
				printf("语文分数:\n");
				scanf("%d", &p->ch);
				break;
			case 5:
				printf("数学分数:\n");
				scanf("%d", &p->ma);
				break;

			case 6:
				printf("英语分数:\n");
				scanf("%d", &p->en);
				break;
			default:
				printf("输入错误！\n");

				break;
			}
			
			p->sum = (p->ch + p->en + p->ma);
			char n = 0;
			scanf("%c", &n);

			printf("是否确认修改? (Y/N)");
			char c = 0;
			scanf("%c", &c);
			if (c == 'Y') 
			{
				writeFile(L);
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		p = p->next;
	}
	printf("未查找到该学生信息！\n");
	return 0;
}

int Det_Student(Student_Node *L)//删除学生信息
{
	Student_Node *p = L;
	Student_Node *pre; //定义前向指针
	printf("请输入要删除学生的学号:\n");
	int id = 0;
	scanf("%d", &id);
	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("查找到您要删除的学生:\n");
			printf("------------------------------------------------------\n");
			printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			while (1)
			{
				char si;
				scanf("%c", &si);
				printf("请确认是否删除？ 请选择 (Y / N)");
				char sc = 0;
				scanf("%c", &sc);
				if (sc == 'Y')
				{
					pre->next = p->next;
					free(p);
					writeFile(L);
					return 1;

				}
				else if (sc == 'N')
				{
					printf("已取消删除操作！\n");
					return 0;
				}
				else
				{
					printf("输入错误，请重新选择:\n");
				}

			}
			
		}

		pre = p;
		p = p -> next;
	}
	printf("未查找到该学生信息！\n");
	return 0;

}

int Search_Id(Student_Node *L, int s_id)
{
	Student_Node *p = L;
	while (p != NULL)
	{
		if (p->id == s_id)
		{
			return 0;//此id 已存在
		}
		p = p->next;
	}
	return 1;//此Id不存在
}

int Search_Student(Student_Node *L)//查找学生信息
{
	Student_Node *p = L;
	printf("请输入要查找学生的学号:\n");
	int id = 0;
	scanf("%d", &id);

	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("您要查找的学生:\n");
			printf("------------------------------------------------------\n");
			printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void Print_Student(Student_Node *L)//输出学生信息
{
	//遍历链表
	Student_Node *p = L->next;//定义指针指向该链表
	printf("------------------------------------------------------\n");
	printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分|\n");
	printf("------------------------------------------------------\n");
	if (p != NULL)
	{
		while (p != NULL)
		{
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			p = p->next;//指针后移
		}
	}	
	if (L->next != NULL) 
	{
		printf("最高分:\n");
		printf("语文:%d\t", Find_Max_Sc(L, 0));
		printf("数学:%d\t", Find_Max_Sc(L, 1));
		printf("英语:%d\t", Find_Max_Sc(L, 2));
		printf("总分:%d\t\n", Find_Max_Sc(L, 3));
	}
	
}

void my_Exit()//退出系统
{
	printf("系统已退出，欢迎下次使用！");
}

int Find_Max_Sc(Student_Node *L, int mode)
{
	if (mode < 0 && mode>3) return -1;
	Student_Node *p = L->next; // mode 0语文 1数学  2英语 3总分
	if (p != NULL)
	{
		int max0 = -1, max1 = -1, max2 = -1, max3 = -1;
		while (p != NULL)
		{
			if (p->ch >= max0) max0 = p->ch;
			if (p->ma >= max1) max1 = p->ma;
			if (p->en >= max2) max2 = p->en;
			if (p->sum >= max3) max3 = p->sum;
			p = p->next;
		}
		if (0 == mode) return max0;
		if (1 == mode) return max1;
		if (2 == mode) return max2;
		if (3 == mode) return max3;
	}
}

int readFile(Student_Node *L) //文件读取输入
{
	FILE *fpr = fopen("Student_Info.txt","r"); //r 为读取  w为写入
	
	Student_Node stu;
	Student_Node *s;//开辟新结点
	Student_Node *r = L;//定义尾指针
	
	if (fpr == NULL)
	{
		printf("文件为空\n");
		return 0;
	}
	else
	{

		/*printf("----------------------------------------------------\n");
		printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分|\n");
		printf("----------------------------------------------------\n");*/
		while (fscanf(fpr, "%d %s %s %d %d %d %d", &stu.id, stu.name, stu.sex, &stu.ch, &stu.ma, &stu.en, &stu.sum) != EOF)
		{
			
			//printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", stu.id, stu.name, stu.sex, stu.ch, stu.ma, stu.en, stu.sum);
			s = (Student_Node*)malloc(sizeof(Student_Node));
			*s = stu;//存入节点信息
			//尾插法 插入节点
			r->next = s;
			r = s;
			r->next = NULL;
		}
	}

	return 1;
}

void My_Sort(Student_Node *L) 
{
	//mode 0按照学号排序 1按照总成绩排序 2按照语文成绩排序 3按照数学成绩排序 4按照英语成绩排序
	int choice = -1;
	printf("请选择排序方式: id - 0  语文成绩 - 1  数学成绩 - 2  英语成绩 - 3  总分 - 4\n");
	scanf("%d", &choice);
	int ret = -1;
	Student_Node *pre = L;//定义头指针
	Student_Node *p = L->next;//
	if (p == NULL) return;
	Student_Node *r = p->next;//定义尾指针
	Student_Node *p_flag = p->next;//定义循环判断指针
	
	if (r != NULL)//排序函数逻辑问题 只遍历了一次 无法实现排序功能 按照冒泡排序逻辑 
	{
		while(p_flag != NULL)
		{
			
			while (r != NULL)//每一轮将最大节点放置最后 需要便利 节点数 - 1 轮  小结点后移
			{
				ret = Node_Swap(p, r, choice);
				if (1 == ret)//前一个节点id大于后一个节点id就交换两个节点 按学号升序
				{

					//如果后一个节点的学号小于前一个节点的学号 就交换两个节点位置
					p->next = r->next;
					r->next = p;
					pre->next = r;
					pre = pre->next;
					r = p->next;

				}
				else
				{
					pre = p;
					p = r;
					r = r->next;
				}

			}
			pre = L;
			p = L->next;
			r = p->next;
			p_flag = p_flag->next;
		}

	}
	writeFile(&List);
	Print_Student(&List);

}

int Node_Swap(Student_Node *node1, Student_Node *node2 ,int ch)
{
	switch (ch)
	{
	case 0: //按学号升序
		if (node1->id > node2->id)
			return 1;
		else 
			return 0;

		break;
	case 1://按语文成绩降序
		if (node1->ch >= node2->ch)
			return 0;
		else
			return 1;
		
		break;
	case 2://按数学成绩降序
		if (node1->ma >= node2->ma)
			return 0;
		else
			return 1;

		break;
	case 3://按英语成绩降序
		if (node1->en >= node2->en)
			return 0;
		else
			return 1;
		break;
	case 4://按总分降序
		if (node1->sum >= node2->sum)
			return 0;
		else
			return 1;
		break;
	default:
		printf("选择错误!\n");
		break;
	}


}

int writeFile(Student_Node *L)//文件写入函数
{
	FILE *fpw = fopen("Student_Info.txt", "w");
	if (fpw == NULL)
	{
		return 0;
		printf("文件打开失败！\n");
	}
	//fprintf(fpw , "xxx"); 信息存储 	
	Student_Node *p = L->next;
	while (p != NULL)
	{
		fprintf(fpw, "%d %s %s %d %d %d %d\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		p = p->next;
	}
}

void insertStuIfo(Student_Node *L, Student_Node s)
{
	//头插法
	Student_Node *p = L;
	Student_Node *r = (Student_Node *)malloc(sizeof(Student_Node));
	*r = s;
	r->next = p->next;
	p->next  = r;
	writeFile(L);

}