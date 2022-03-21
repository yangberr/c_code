#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

//����ṹ��
typedef struct Student_Node
{
	int id;           //ѧ��
	char name[50];	  //����
	char sex[10];	  //�Ա�
	int ch, ma, en;	  //������ɼ�
	int sum;		  //�ܳɼ�
	struct Student_Node *next; //����ָ����
}Student_Node;
Student_Node List;//����

void display_menu();//��ӡ�˵�
void Add_Student(Student_Node *L);//����ѧ����Ϣ  
int Fix_Student(Student_Node *L);//�޸�ѧ����Ϣ
int Det_Student(Student_Node *L);//ɾ��ѧ����Ϣ
int Search_Student(Student_Node *L);//����ѧ����Ϣ
void Print_Student(Student_Node *L);//���ѧ����Ϣ
void my_Exit();//�˳�ϵͳ
void insertStuIfo(Student_Node *L, Student_Node s);//����ڵ㺯��
int Search_Id(Student_Node *L , int s_id);//ѧ�ò��غ���
int Find_Max_Sc(Student_Node *L, int mode);//������߷���
void My_Sort(Student_Node *L );//�Զ��������� ʵ�ֿɰ���ѧ���Լ����Ƴɼ�������������� ����qsort 
int Node_Swap(Student_Node *node1, Student_Node *node2 ,int ch);//�����жϺ���

//��ȡ�ļ�
int readFile(Student_Node *L);//��������ָ��
//д���ļ�
int writeFile(Student_Node *L);



int main()
{
	int choice = 0;
	int i = 0;
	readFile(&List);
	display_menu();//�˵���ӡ

	do
	{
	
		printf("��ѡ����:\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
			
		case 1://����ѧ����Ϣ
			Add_Student(&List);
			break;
		case 2://�޸�ѧ����Ϣ
			i = Fix_Student(&List);
			if (i == 1) 
			{
				printf("�޸ĳɹ���\n");
			}
			else
			{
				printf("�޸�ʧ��!\n");
			}
			break;
		case 3://ɾ��ѧ����Ϣ
		    i = Det_Student(&List);
			if (i == 1)
			{
				printf("ɾ���ɹ���\n");
			}
			else
			{
				printf("ʧ��!\n");
			}
			break;
		case 4://��ѯѧ����Ϣ
			i = Search_Student(&List);
			if (0 != i)
			{
				printf("����ʧ�ܣ�\n");
			}
			break;
		case 5://���ѧ����Ϣ
			Print_Student(&List);
			break;
		case 6:
			My_Sort(&List);
			break;
		case 0://�˳�ϵͳ
			my_Exit();
			break;
		default:
			printf("�����������������:\n");
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
	printf("----��ӭʹ��ѧ���ɼ�����ϵͳ----\n");
	printf("-----    1. ����ѧ����Ϣ    ----\n");
	printf("-----    2. �޸�ѧ����Ϣ    ----\n");
	printf("-----    3. ɾ��ѧ����Ϣ    ----\n");
	printf("-----    4. ��ѯѧ����Ϣ    ----\n");
	printf("-----    5. ���ѧ����Ϣ    ----\n");
	printf("-----    6. ����ѧ����Ϣ    ----\n");
	printf("-----    0. �˳�����ϵͳ    ----\n");
	printf("--------------------------------\n");
	printf("--------------------------------\n");
}

void Add_Student(Student_Node *L)//����ѧ����Ϣ
{
	Student_Node s;
	Student_Node *p = L;
	printf("����������ѧ����Ϣ:\n");
	printf("ѧ��:\n");
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
		printf("��ѧ���Ѵ��ڣ�����������:\n");
		goto start1;
	}
	printf("����:\n");
	scanf("%s", s.name);
	printf("�Ա�:\n");
	scanf("%s", s.sex);
	printf("���ķ���:\n");
	scanf("%d", &s.ch);
	printf("��ѧ����:\n");
	scanf("%d", &s.ma);
	printf("Ӣ�����:\n");
	scanf("%d", &s.en);
	s.sum = (s.ch + s.en + s.ma);

	insertStuIfo(&List, s);//������뺯�� 
	
}

int Fix_Student(Student_Node *L)//�޸�ѧ����Ϣ
{
	Student_Node *p = L;
	int chioce = 0;
	printf("������Ҫ�޸�ѧ����ѧ��:\n");
	int id = 0;
	scanf("%d", &id);
	int s_id = 0;//�����޸ĺ��id
	int ret = 0;//�ж�id�Ƿ���ڱ�־
	

	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("���ҵ���Ҫ�޸ĵ�ѧ��:\n");
			printf("------------------------------------------------------\n");
			printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			printf("��ѡ����Ҫ�޸ĵ���Ϣ:\n");
			printf("ѧ�� - 1\t���� - 2\t�Ա� - 3\t���ķ��� - 4\t��ѧ���� - 5\tӢ����� - 6 \n");
			scanf("%d", &chioce);
			switch (chioce)
			{
			case 1:
				printf("ѧ��:\n");
			    start:scanf("%d", &s_id);
				ret = Search_Id(L , s_id);
				if (1 == ret)
				{
					p->id = s_id;
				}
				else if(0 == ret)
				{
					printf("��ѧ���Ѵ��ڣ�����������:\n");
					goto start;
				}

				break;
			case 2:
				printf("����:\n");
				scanf("%s", p->name);
				break;

			case 3:
				printf("�Ա�:\n");
				scanf("%s", p->sex);
				break;
			case 4:
				printf("���ķ���:\n");
				scanf("%d", &p->ch);
				break;
			case 5:
				printf("��ѧ����:\n");
				scanf("%d", &p->ma);
				break;

			case 6:
				printf("Ӣ�����:\n");
				scanf("%d", &p->en);
				break;
			default:
				printf("�������\n");

				break;
			}
			
			p->sum = (p->ch + p->en + p->ma);
			char n = 0;
			scanf("%c", &n);

			printf("�Ƿ�ȷ���޸�? (Y/N)");
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
	printf("δ���ҵ���ѧ����Ϣ��\n");
	return 0;
}

int Det_Student(Student_Node *L)//ɾ��ѧ����Ϣ
{
	Student_Node *p = L;
	Student_Node *pre; //����ǰ��ָ��
	printf("������Ҫɾ��ѧ����ѧ��:\n");
	int id = 0;
	scanf("%d", &id);
	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("���ҵ���Ҫɾ����ѧ��:\n");
			printf("------------------------------------------------------\n");
			printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			while (1)
			{
				char si;
				scanf("%c", &si);
				printf("��ȷ���Ƿ�ɾ���� ��ѡ�� (Y / N)");
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
					printf("��ȡ��ɾ��������\n");
					return 0;
				}
				else
				{
					printf("�������������ѡ��:\n");
				}

			}
			
		}

		pre = p;
		p = p -> next;
	}
	printf("δ���ҵ���ѧ����Ϣ��\n");
	return 0;

}

int Search_Id(Student_Node *L, int s_id)
{
	Student_Node *p = L;
	while (p != NULL)
	{
		if (p->id == s_id)
		{
			return 0;//��id �Ѵ���
		}
		p = p->next;
	}
	return 1;//��Id������
}

int Search_Student(Student_Node *L)//����ѧ����Ϣ
{
	Student_Node *p = L;
	printf("������Ҫ����ѧ����ѧ��:\n");
	int id = 0;
	scanf("%d", &id);

	while (p != NULL)
	{
		if (p->id == id)
		{
			printf("��Ҫ���ҵ�ѧ��:\n");
			printf("------------------------------------------------------\n");
			printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�|\n");
			printf("------------------------------------------------------\n");
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void Print_Student(Student_Node *L)//���ѧ����Ϣ
{
	//��������
	Student_Node *p = L->next;//����ָ��ָ�������
	printf("------------------------------------------------------\n");
	printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�|\n");
	printf("------------------------------------------------------\n");
	if (p != NULL)
	{
		while (p != NULL)
		{
			printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			p = p->next;//ָ�����
		}
	}	
	if (L->next != NULL) 
	{
		printf("��߷�:\n");
		printf("����:%d\t", Find_Max_Sc(L, 0));
		printf("��ѧ:%d\t", Find_Max_Sc(L, 1));
		printf("Ӣ��:%d\t", Find_Max_Sc(L, 2));
		printf("�ܷ�:%d\t\n", Find_Max_Sc(L, 3));
	}
	
}

void my_Exit()//�˳�ϵͳ
{
	printf("ϵͳ���˳�����ӭ�´�ʹ�ã�");
}

int Find_Max_Sc(Student_Node *L, int mode)
{
	if (mode < 0 && mode>3) return -1;
	Student_Node *p = L->next; // mode 0���� 1��ѧ  2Ӣ�� 3�ܷ�
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

int readFile(Student_Node *L) //�ļ���ȡ����
{
	FILE *fpr = fopen("Student_Info.txt","r"); //r Ϊ��ȡ  wΪд��
	
	Student_Node stu;
	Student_Node *s;//�����½��
	Student_Node *r = L;//����βָ��
	
	if (fpr == NULL)
	{
		printf("�ļ�Ϊ��\n");
		return 0;
	}
	else
	{

		/*printf("----------------------------------------------------\n");
		printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�|\n");
		printf("----------------------------------------------------\n");*/
		while (fscanf(fpr, "%d %s %s %d %d %d %d", &stu.id, stu.name, stu.sex, &stu.ch, &stu.ma, &stu.en, &stu.sum) != EOF)
		{
			
			//printf("%d %-6s  %3s\t  %3d\t %3d\t %3d\t %3d\t\n", stu.id, stu.name, stu.sex, stu.ch, stu.ma, stu.en, stu.sum);
			s = (Student_Node*)malloc(sizeof(Student_Node));
			*s = stu;//����ڵ���Ϣ
			//β�巨 ����ڵ�
			r->next = s;
			r = s;
			r->next = NULL;
		}
	}

	return 1;
}

void My_Sort(Student_Node *L) 
{
	//mode 0����ѧ������ 1�����ܳɼ����� 2�������ĳɼ����� 3������ѧ�ɼ����� 4����Ӣ��ɼ�����
	int choice = -1;
	printf("��ѡ������ʽ: id - 0  ���ĳɼ� - 1  ��ѧ�ɼ� - 2  Ӣ��ɼ� - 3  �ܷ� - 4\n");
	scanf("%d", &choice);
	int ret = -1;
	Student_Node *pre = L;//����ͷָ��
	Student_Node *p = L->next;//
	if (p == NULL) return;
	Student_Node *r = p->next;//����βָ��
	Student_Node *p_flag = p->next;//����ѭ���ж�ָ��
	
	if (r != NULL)//�������߼����� ֻ������һ�� �޷�ʵ�������� ����ð�������߼� 
	{
		while(p_flag != NULL)
		{
			
			while (r != NULL)//ÿһ�ֽ����ڵ������� ��Ҫ���� �ڵ��� - 1 ��  С������
			{
				ret = Node_Swap(p, r, choice);
				if (1 == ret)//ǰһ���ڵ�id���ں�һ���ڵ�id�ͽ��������ڵ� ��ѧ������
				{

					//�����һ���ڵ��ѧ��С��ǰһ���ڵ��ѧ�� �ͽ��������ڵ�λ��
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
	case 0: //��ѧ������
		if (node1->id > node2->id)
			return 1;
		else 
			return 0;

		break;
	case 1://�����ĳɼ�����
		if (node1->ch >= node2->ch)
			return 0;
		else
			return 1;
		
		break;
	case 2://����ѧ�ɼ�����
		if (node1->ma >= node2->ma)
			return 0;
		else
			return 1;

		break;
	case 3://��Ӣ��ɼ�����
		if (node1->en >= node2->en)
			return 0;
		else
			return 1;
		break;
	case 4://���ֽܷ���
		if (node1->sum >= node2->sum)
			return 0;
		else
			return 1;
		break;
	default:
		printf("ѡ�����!\n");
		break;
	}


}

int writeFile(Student_Node *L)//�ļ�д�뺯��
{
	FILE *fpw = fopen("Student_Info.txt", "w");
	if (fpw == NULL)
	{
		return 0;
		printf("�ļ���ʧ�ܣ�\n");
	}
	//fprintf(fpw , "xxx"); ��Ϣ�洢 	
	Student_Node *p = L->next;
	while (p != NULL)
	{
		fprintf(fpw, "%d %s %s %d %d %d %d\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		p = p->next;
	}
}

void insertStuIfo(Student_Node *L, Student_Node s)
{
	//ͷ�巨
	Student_Node *p = L;
	Student_Node *r = (Student_Node *)malloc(sizeof(Student_Node));
	*r = s;
	r->next = p->next;
	p->next  = r;
	writeFile(L);

}