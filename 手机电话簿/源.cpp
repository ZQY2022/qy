#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tel {
	char name[40];//联系人姓名
	char num1[30];//联系人手机号码
	char num2[30];//联系人可能拥有多个手机号码
	char email1[40];//联系人电子邮箱
	char email2[40];//联系人可能拥有多个电子邮箱
	char zhuzhi[100];//联系人家庭住址
	char QQ1[30];//联系人QQ号码
	char QQ2[30];//联系人可能拥有多个QQ号码
	struct tel* next;//next指针
}tel;
tel* Create() {//输入联系人信息
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
		printf("(%d)姓名：",i);
		scanf("%s", name1);
		printf("(%d)电话号码：",i);
		scanf("%s", num);
		printf("(%d)电子邮件：",i);
		scanf("%s",email);
		printf("(%d)家庭住址：",i);
		scanf("%s",zhuzhi1);
		printf("(%d)QQ号码：",i);
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
		printf("结束输入请选择0，继续输入请选择1：\n");
		scanf("%d", &a);
		if (a == 0) { printf("输入结束！\n\n"); break; }

	}
	p2->next = NULL;
	return (head->next);
}
void insert(tel* head) {//新建联系人
	tel* p = head;
	tel* p1 = (tel*)malloc(sizeof(tel));
	printf("姓名：");
	scanf("%s",p1->name);
	printf("电话号码：");
	scanf("%s",p1->num1);
	printf("电子邮件：");
	scanf("%s",p1->email1);
	printf("家庭住址：");
	scanf("%s",p1->zhuzhi);
	printf("QQ号码：");
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
void search(tel* head) {//查询联系人信息
	tel* p = head;
	char yizhi[100];
	printf("请输入已知的联系人信息：\n");
	scanf("%s", yizhi);
	while (p != NULL) {
		if (strcmp(p->name, yizhi) == 0 || strcmp(p->num1, yizhi) == 0 || strcmp(p->num2, yizhi) == 0 || strcmp(p->email1, yizhi) == 0 || strcmp(p->zhuzhi, yizhi) == 0 || strcmp(p->QQ1, yizhi) == 0) {
			if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
				printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
				printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
				printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
				printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") == 0) {
				printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
				printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->email2, p->zhuzhi, p->QQ1);
			}
			else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
				printf("姓名：%s\n手机号码：%s\n=电子邮箱：%s\n=家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
			}
			else { printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1); }
			break;
		}
		p = p->next;
	}
	printf("\n");
}
void tianjia(tel* head) {//编辑联系人信息
	char name1[40];
	char x[20];
	int a;
	printf("请输入联系人的名字：");
	scanf("%s", name1);
	tel* p = head;
	printf("*********************\n* 0、添加手机号码： *\n* 1、添加电子邮箱： *\n* 2、添加QQ号码：   *\n*********************\n");
	scanf("%d", &a);
	if (a == 0) {
		printf("请输入所添加的手机号码：");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
			strcpy(p->num2, x); break;
		}
			p = p->next;
	}}
	if (a == 1) {
		printf("请输入所添加的电子邮箱：");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				strcpy(p->email2, x); break;
			}
			p = p->next;
		}
	}
	if (a == 2) {
		printf("请输入所添加的QQ号码：");
		scanf("%s", x);
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				strcpy(p->QQ2, x); break;
			}
			p = p->next;
		}
	}
	printf("添加成功！\n");
}
void paixu(tel* head){//按照名字的字母顺序对联系人进行排序
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
void Print(tel* head) {//输出联系人的信息
	if (head == NULL) {
		return;
	}
	tel* p = head;
	while(p != NULL) {
		if (strcmp(p->num2,"0")!=0&&strcmp(p->email2,"0")!=0&&strcmp(p->QQ2,"0")!=0) {
			printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1,p->email2, p->zhuzhi, p->QQ1,p->QQ2);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
			printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0")== 0 && strcmp(p->QQ2, "0")!= 0) {
			printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else if(strcmp(p->num2, "0")== 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") != 0) {
			printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1,p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else if (strcmp(p->num2, "0") != 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") == 0) {
			printf("姓名：%s\n手机号码：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->num2, p->email1, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") != 0 && strcmp(p->QQ2, "0") == 0) {
			printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1,p->email1, p->email2, p->zhuzhi, p->QQ1);
		}
		else if (strcmp(p->num2, "0") == 0 && strcmp(p->email2, "0") == 0 && strcmp(p->QQ2, "0") != 0) {
			printf("姓名：%s\n手机号码：%s\n=电子邮箱：%s\n=家庭住址：%s\nQQ号码：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1, p->QQ2);
		}
		else { printf("姓名：%s\n手机号码：%s\n电子邮箱：%s\n家庭住址：%s\nQQ号码：%s\n", p->name, p->num1, p->email1, p->zhuzhi, p->QQ1); }
		p = p->next;
	}
	printf("\n");
}
void lianxiren(struct tel* head)//将联系人信息写入文件
{
	FILE* lianxiren = fopen("电话簿.txt", "w+");
	for (struct tel* p = head; p!=NULL; p = p->next)
	{
			fprintf(lianxiren, "%s %s %s %s %s %s %s %s\n", p->name, p->num1, p->num2, p->email1, p->email2, p->zhuzhi, p->QQ1, p->QQ2);
	}
	fclose(lianxiren);
	printf("成功导入!\n");
}
tel* duqu() //读取联系人信息
{
	tel* head, * p1, * p2;
	head = (tel*)malloc(sizeof(tel));
	p2 = head;
	FILE* fp = fopen("电话簿.txt", "r");
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
	printf("成功读取信息!\n");
	return(head->next);
}
int main() {
	printf("                                                  手机电话簿\n");
	tel* head=(tel*)malloc(sizeof(tel));
	int n;
	while (1) {
		printf("******************************\n* 1、输入联系人信息：        *\n* 2、编辑联系人信息：        *\n* 3、新建联系人信息：        *\n* 4、查询联系人信息：        *\n* 5、输出所有联系人信息：    *\n* 6、将联系人信息写入文件：  *\n* 7、读取联系人信息：        *\n* 8、结束使用：              *\n******************************\n");
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
		if (n == 8) { printf("*********感谢您的使用*********\n"); break; }
	}
	return 1;
}