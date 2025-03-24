#include"declare.h"
MEMBER* member_data(const char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)		//ע��=��==�����ȼ����������ŻὫfopen(filename, "r") == NULL�Ľ������fp�����޷��������ļ�
	{
		printf("Failed to open the file");
		exit(0);
	}
	MEMBER* head = NULL, * tail = NULL;
	char account[20];
	char password[20];
	while (fscanf(fp, "%[^,],%[^,\n]\n",account,password) == 2)			//%[^,] ��Ϊ���ɶ�ȡֱ������','(����ȡ����)  Ȼ����������  [^,\n]��Ϊ�ڶ�ȡ���һ����ʱ�����\n��ҲҪ����
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
	printf("��½ʧ��\n");
	return 0;
}


int log_in_member()
{
	MEMBER* head = member_data("D:\\code\\vs2022\\c����ʵ�����\\member.txt");
	char account[20];
	char password[20];
	char hide;
	int i = 0;
	printf("�������˺�:");
	scanf("%20s", account);
	printf("�Ƿ���ʾ����:\n");
	printf("0.��ʾ\n");
	printf("1.����ʾ\n");
	int ifdisplay;
	scanf("%d", &ifdisplay);
	if (ifdisplay)
	{
		printf("����������:");
		while (1)
		{
			hide = getch();
			if (hide == 13)//13��Ӧ"\r" �س�
			{
				password[i] = '\0';
				break;
			}
			else if (hide == 8 && i > 0)//ascii 8��Ӧ"\b"�˸�
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
		printf("����������:");
		scanf("%s", password);
	}
	
	if (ifcorrect(head, account, password))
	{
		printf("��½�ɹ���\n");
		return 1;
	}
	else
		return 0;
}

