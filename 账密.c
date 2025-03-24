#include"declare.h"
MEMBER* member_data(const char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)		//注意=与==的优先级，不加括号会将fopen(filename, "r") == NULL的结果赋给fp导致无法正常打开文件
	{
		printf("Failed to open the file");
		exit(0);
	}
	MEMBER* head = NULL, * tail = NULL;
	char account[20];
	char password[20];
	while (fscanf(fp, "%[^,],%[^,\n]\n",account,password) == 2)			//%[^,] 意为自由读取直到遇到','(不读取逗号)  然后跳过逗号  [^,\n]因为在读取最后一个数时会读入\n，也要跳过
	{
		MEMBER* new = (MEMBER*)malloc(sizeof(MEMBER));
		strcpy(new->account, account);
		strcpy(new->password, password);
		if (head == NULL)
		{
			head = new;
			head->next = NULL;
			tail = new;
		}
		else
		{
			tail->next = new;
			tail = new;
		}
	}
	tail->next = NULL;
	fclose(fp);
	return head;
}

int ifcorrect(MEMBER* head,char *account,char *password)
{
	MEMBER* curr = head;
	while (curr)
	{
		if (strcmp(curr->account, account) == 0)
		{
			if (strcmp(curr->password, password) == 0)
			{
				return 1;
			}
		}
		curr = curr->next;
	}
	printf("登陆失败\n");
	return 0;
}


int log_in_member()
{
	MEMBER* head = member_data("D:\\code\\vs2022\\c语言实验设计\\member.txt");
	char account[20];
	char password[20];
	char hide;
	int i = 0;
	printf("请输入账号:");
	scanf("%20s", account);
	printf("是否显示密码:\n");
	printf("0.显示\n");
	printf("1.不显示\n");
	int ifdisplay;
	scanf("%d", &ifdisplay);
	if (ifdisplay)
	{
		printf("请输入密码:");
		while (1)
		{
			hide = getch();
			if (hide == 13)//13对应"\r" 回车
			{
				password[i] = '\0';
				break;
			}
			else if (hide == 8 && i > 0)//ascii 8对应"\b"退格
			{
				i--;
				printf("\b \b");
			}
			else if (i < 20)
			{
				password[i] = hide;
				i++;
				printf("*");
			}
		}
		printf("\n");
	}
	else
	{
		printf("请输入密码:");
		scanf("%s", password);
	}
	
	if (ifcorrect(head, account, password))
	{
		printf("登陆成功！\n");
		return 1;
	}
	else
		return 0;
}

