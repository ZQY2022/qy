#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tel {
	char name[40];//��ϵ������
	char num1[30];//��ϵ���ֻ�����
	char num2[30];//��ϵ�˿���ӵ�ж���ֻ�����
	char email1[40];//��ϵ�˵�������
	char email2[40];//��ϵ�˿���ӵ�ж����������
	char zhuzhi[100];//��ϵ�˼�ͥסַ
	char QQ1[30];//��ϵ��QQ����
	char QQ2[30];//��ϵ�˿���ӵ�ж��QQ����
	struct tel* next;//nextָ��
}tel;
tel* Create() {//������ϵ����Ϣ
	tel* head, * p1, * p2;
	int i = 1;
	head = (tel*)malloc(sizeof(tel));
	p2 = head;
	while (1) {
		int a;
		char name1[40];
		char num[30];
		char email[40];
		char zhuzhi1[100];
		char QQ[30];
		p1 = (tel*)malloc(sizeof(tel));
		printf("(%d)������",i);
		scanf("%s", name1);
		printf("(%d)�绰���룺",i);
		scanf("%s", num);
		printf("(%d)�����ʼ���",i);
		scanf("%s",email);
		printf("(%d)��ͥסַ��",i);
		scanf("%s",zhuzhi1);
		printf("(%d)QQ���룺",i);
		scanf("%s", QQ);
		strcpy(p1->name, name1);
		strcpy(p1->num1, num);
		strcpy(p1->num2,"0");
		strcpy(p1->email1, email);
		strcpy(p1->email2, "0");
		strcpy(p1->zhuzhi, zhuzhi1);
		strcpy(p1->QQ1, QQ);
		strcpy(p1->QQ2, "0");
		p2->next = p1;
		p2 = p1;
		i++;
		printf("����������ѡ��0������������ѡ��1��\n");
		scanf("%d", &a);
		if (a == 0) { printf("���������\n\n"); break; }

	}
	p2->next = NULL;
	return (head->next);
}
void insert(tel* head) {//�½���ϵ��
	tel* p = head;
	tel* p1 = (tel*)malloc(sizeof(tel));
	printf("������");
	scanf("%s",p1->name);
	printf("�绰���룺");
	scanf("%s",p1->num1);
	printf("�����ʼ���");
	scanf("%s",p1->email1);
	printf("��ͥסַ��");
	scanf("%s",p1->zhuzhi);
	printf("QQ���룺");
	scanf("%s",p1->QQ1);
	strcpy(p1->num2, "0");
	strcpy(p1->email2, "0");
	strcpy(p1->QQ2, "0");
	for (p; p != NULL; p = p->next) {
		if (p->next == NULL) {
			p->next = p1;
			p = p1;
			break;
		}
	}
	p->next = NULL;
	
}
void search(tel* head) {//��ѯ��ϵ����Ϣ
	tel* p = head;
	char yizhi[100];
	printf("��������֪����ϵ����Ϣ��\n");
	scanf("%s", yizhi);
	while (p != NULL) {
		if (strcmp(p->name, yizhi) == 0 || strcmp(p->num1, yizhi) == 0 || strcmp(p->num2, yizhi) == 0 || strcmp(p->email1, yizhi) == 0 || strcmp(p->zhuzhi, yizhi) == 0 || strcmp(p->QQ1, yizhi) == 0) {
			if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
				printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
				printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
				printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
				printf("������%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") == 0) {
				printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
				printf("������%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->email2, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
				printf("������%s\n�ֻ����룺%s\n=�������䣺%s\n=��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else { printf("������%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1); }
			break;
		}
		p = p->next;
	}
	printf("\n");
}
void tianjia(tel* head) {//�༭��ϵ����Ϣ
	char name1[40];
	char x[20];
	int a;
	printf("��������ϵ�˵����֣�");
	scanf("%s", name1);
	tel* p = head;
	printf("*********************\n* 0������ֻ����룺 *\n* 1����ӵ������䣺 *\n* 2�����QQ���룺   *\n*********************\n");
	scanf("%d", &a);
	if (a == 0) {
		printf("����������ӵ��ֻ����룺");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
			strcpy(p->num2, x); break;
		}
			p = p->next;
	}}
	if (a == 1) {
		printf("����������ӵĵ������䣺");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				strcpy(p->email2, x); break;
			}
			p = p->next;
		}
	}
	if (a == 2) {
		printf("����������ӵ�QQ���룺");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				strcpy(p->QQ2, x); break;
			}
			p = p->next;
		}
	}
	printf("��ӳɹ���\n");
}
void paixu(tel* head){//�������ֵ���ĸ˳�����ϵ�˽�������
	char a[100];
	for (tel* p = head; p != NULL,p->next!=NULL; p = p->next) {
		for (tel* p1 = head; p1 != NULL,p1->next!=NULL; p1 = p1->next) {
			for (int i = 0; i < 100; i++) {
			if (p1->name[i] > p1->next->name[i]) {
				strcpy(a, p1->next->name);
				strcpy(p1->next->name, p1->name);
				strcpy(p1->name, a);
				strcpy(a, p1->num1);
				strcpy(p1->num1, p1->next->num1);
				strcpy(p1->next->num1, a);
				strcpy(a, p1->num2);
				strcpy(p1->num2, p1->next->num2);
				strcpy(p1->next->num2, a);
				strcpy(a, p1->email1);
				strcpy(p1->email1, p1->next->email1);
				strcpy(p1->next->email1, a);
				strcpy(a, p1->email2);
				strcpy(p1->email2, p1->next->email2);
				strcpy(p1->next->email2, a);
				strcpy(a, p1->zhuzhi);
				strcpy(p1->zhuzhi, p1->next->zhuzhi);
				strcpy(p1->next->zhuzhi, a);
				strcpy(a, p1->QQ1);
				strcpy(p1->QQ1, p1->next->QQ1);
				strcpy(p1->next->QQ1, a);
				strcpy(a, p1->QQ2);
				strcpy(p1->QQ2, p1->next->QQ2);
				strcpy(p1->next->QQ2, a);
				break;
			}
			if (p1->name[i] < p1->next->name[i]) { break; }
			if (p1->name[i] == p1->next->name[i]) { continue; }
			if (p1->name[i] == '\0' || p1->next->name[i] == '\0') {
				break;
			}
			}
		}
	}
}
void Print(tel* head) {//�����ϵ�˵���Ϣ
	if (head == NULL) {
		return;
	}
	tel* p = head;
	while(p != NULL) {
		if (strcmp(p->num2,"0")!=0&&strcmp(p->email2,"0")!=0&&strcmp(p->QQ2,"0")!=0) {
			printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1,p->email2, p->zhuzhi, p->QQ1,p->QQ2);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
			printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0")== 0 && strcmp(p->QQ2, "0")!= 0) {
			printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else if(strcmp(p->num2, "0")== 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
			printf("������%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1,p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") == 0) {
			printf("������%s\n�ֻ����룺%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
			printf("������%s\n�ֻ����룺%s\n�������䣺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1,p->email1, p->email2, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
			printf("������%s\n�ֻ����룺%s\n=�������䣺%s\n=��ͥסַ��%s\nQQ���룺%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else { printf("������%s\n�ֻ����룺%s\n�������䣺%s\n��ͥסַ��%s\nQQ���룺%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1); }
		p = p->next;
	}
	printf("\n");
}
void lianxiren(struct tel* head)//����ϵ����Ϣд���ļ�
{
	FILE* lianxiren = fopen("�绰��.txt", "w+");
	for (struct tel* p = head; p!=NULL; p = p->next)
	{
			fprintf(lianxiren, "%s %s %s %s %s %s %s %s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
	}
	fclose(lianxiren);
	printf("�ɹ�����!\n");
}
tel* duqu() //��ȡ��ϵ����Ϣ
{
	tel* head, * p1, * p2;
	head = (tel*)malloc(sizeof(tel));
	p2 = head;
	FILE* fp = fopen("�绰��.txt", "r");
	if (!fp)
	{
		perror("fopen");
		exit(0);
	}
	char name[40];
	char num1[30];
	char num2[30];
	char email1[40];
	char email2[40];
	char zhuzhi[100];
	char QQ1[30];
	char QQ2[30];
	while (fscanf(fp,"%s %s %s %s %s %s %s %s", name, num1,num2, email1,email2, zhuzhi, QQ1,QQ2) != EOF) {
		p1 = (tel*)malloc(sizeof(tel));
		strcpy(p1->name, name);
		strcpy(p1->num1, num1);
		strcpy(p1->num2, num2);
		strcpy(p1->email1, email1);
		strcpy(p1->email2, email2);
		strcpy(p1->zhuzhi, zhuzhi);
		strcpy(p1->QQ1, QQ1);
		strcpy(p1->QQ2, QQ2);
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	fclose(fp);
	printf("�ɹ���ȡ��Ϣ!\n");
	return(head->next);
}
int main() {
	printf("                                                  �ֻ��绰��\n");
	tel* head=(tel*)malloc(sizeof(tel));
	int n;
	while (1) {
		printf("******************************\n* 1��������ϵ����Ϣ��        *\n* 2���༭��ϵ����Ϣ��        *\n* 3���½���ϵ����Ϣ��        *\n* 4����ѯ��ϵ����Ϣ��        *\n* 5�����������ϵ����Ϣ��    *\n* 6������ϵ����Ϣд���ļ���  *\n* 7����ȡ��ϵ����Ϣ��        *\n* 8������ʹ�ã�              *\n******************************\n");
		scanf("%d", &n);
		if (n == 1) {
			head = Create();
			paixu(head);
		}
		if (n == 2) {
			tianjia(head);
		}
		if (n == 3) { 
			insert(head);
			paixu(head);
		}
		if (n == 4) {
			search(head);
		}
		if (n == 5) {
			Print(head); 
		}
		if (n == 6) {
			lianxiren(head);
			paixu(head);
		}
		if (n == 7) {
			head=duqu();
		}
		if (n == 8) { printf("*********��л����ʹ��*********\n"); break; }
	}
	return 1;
}