#include"declare.h"



void member_write_to_file(const char* filename, char* account, char* password)
{
	FILE* fp = fopen(filename, "a+");		
	if (fp == NULL)
	{
		printf("Open failed\n");
		return;		//void��return�󲻼�0
	}
	fprintf(fp, "%s,%s\n", account, password);
	printf("ע��ɹ���\n");
	fclose(fp);
}

void regist_member()
{
	FILE* fp;
	if ((fp = fopen("D:\\code\\vs2022\\c����ʵ�����\\manager.txt", "a+")) == NULL)
	{
		printf("ϵͳ������!");
		return 0;
	}
	char hide;
	int i = 0;
	char acc[20];
	char pas[20];
	printf("�������˺ţ�");
	scanf("%s", acc);
	printf("���������룺");
	while (1)
	{
		hide = getch();
		if (hide == 13)//13��Ӧ"\r" �س�
		{
			pas[i] = '\0';
			break;
		}
		else if (hide == 8 && i > 0)//ascii 8��Ӧ"\b"�˸�
		{
			i--;
			printf("\b \b");
		}
		else if (i < 20)
		{
			pas[i] = hide;
			i++;
			printf("*");
		}
	}
	printf("\n");
	member_write_to_file("D:\\code\\vs2022\\c����ʵ�����\\member.txt", acc, pas);
}


void add_room_type()
{
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c����ʵ�����\\data.txt");
	TYPE_ROOM* curr = head;
	while (curr)
		curr = curr->next;
	curr = (TYPE_ROOM*)malloc(sizeof(TYPE_ROOM));
	int num;
	float size;
	char typename[100];
	int ID;
	double price;
	char status[20];
	char location[20];
	printf("��������ͷ�����������С�Լ���������");
	scanf("%d%f%s", &num, &size, typename);
	printf("��������������¸�������Ϣ����������ţ��۸�״̬��λ�ã�,Ӣ�Ķ������");
	for (int i = 0; i < num; i++)
	{
		scanf("%d,%f,%[^,],%[^,\n]\n", &ID,&price,status,location);
		curr->room=single_connect(curr->room, ID, price, status, location);
		curr = curr->next;
	}
	curr->next = NULL;
	write_to_file(head, "D:\\code\\vs2022\\c����ʵ�����\\data.txt");
}

void add_cus()
{
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
	CUSTOMER* curr = head;
	int number;
	char ID[19];
	char name[20];
	char vip_level[20];
	printf("��������������Ϣ���������������֤��������VIP�ȼ���");
	scanf("%d,%[^,],%[^,],%[,\n]\n",number,ID,name,vip_level);
	while (curr)
	{
		curr = curr->next;
	}
	curr = (CUSTOMER*)malloc(sizeof(CUSTOMER));
	curr->number = number;
	strcpy(curr->ID, ID);
	strcpy(curr->name, name);
	curr->vip_level = convert_vip_level(vip_level);
	curr->next = NULL;
	write_to_cusdatafile(head, "D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
}


void delete_room_type()
{
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c����ʵ�����\\data.txt");
	TYPE_ROOM* curr = head;
	int ID;
	printf("������Ҫɾ���ķ���ID��");
	scanf("%d", ID);
	int found = 0;
	while (curr)
	{
		curr->room = deletesingle(curr->room, ID);
	}
	write_to_file(head, "D:\\code\\vs2022\\c����ʵ�����\\data.txt");
}

void delete_customer_type()
{
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
	CUSTOMER* curr = head, * prev = NULL;
	char ID[19];
	printf("����ɾ�����˵����֤�ţ�");
	scanf("%[^,\n]", ID);
	while (curr != NULL && strcmp(curr->ID, ID) != 0)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		head = head->next;
	}
	else
		prev->next = curr->next;
	write_to_cusdatafile(head, "D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
}




void adjust_room_type()
{
	TYPE_ROOM* head = read_from_file(data_filename);
	TYPE_ROOM* curr = head, *prev = NULL;
	Single_room* roomcurr;
	Single_room* roomprev = NULL;
	int ID;
	int found = 0;
	printf("����������������ͣ�");
	scanf("%d", &ID);
	while (curr)
	{
		roomcurr = curr->next;
		roomprev = NULL;
		while (roomcurr)
		{
			if (roomcurr->ID == ID)
			{
				found = 1;
				break; 
			}
			roomprev = roomcurr;
			roomcurr = roomcurr->next;
		}
		if (found)
		{
			if (roomprev == NULL)
				curr->room = roomcurr->next;
			else
				roomprev->next = roomcurr->next;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	if (!found)
	{
		printf("���ҷ���ʧ�ܣ������������˵�\n");
		return;
	}
	char typename[20];
	printf("����������\n");
	scanf("%s", typename);
	curr = head;
	while (curr)
	{
		if (strcmp(curr->typename, typename) == 0)
		{
			if (curr->room == NULL)
				curr->room = roomcurr;
			else
			{
				Single_room* now = curr->room;
				while (now->next)
					now = now->next;
				now->next = roomcurr;
			}
			roomcurr->next = NULL;
			break;
		}
		curr = curr->next;
	}
	printf("%d�����������޸�Ϊ%s", ID, typename);
	write_to_file(head, data_filename);
}




void adjust_cus_type()
{
	char ID[19];
	printf("����������֤�ţ�");
	scanf("%s", ID);
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
	CUSTOMER* curr = head;
	while (curr)
	{
		if (strcmp(curr->ID,ID)==0)
			break;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		printf("Ѱ�ҿ���ʧ��\n");
		return;
	}
	else
	{
		char newlevel[20];
		printf("�������VIP�ȼ���");
		scanf("%s", newlevel);
		curr->vip_level= convert_vip_level(newlevel);
		printf("�޸ĳɹ�\n");
		write_to_cusdatafile(head, "D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt");
		return;
	}
}


void adjust_room_price()
{
	char* condition[20];
	printf("���뵱ǰ�����cold season/hot season/weekend/weekday����");
	getchar();
	scanf("%[^\n]", condition);
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c����ʵ�����\\data.txt");
	int ID;
	printf("�����뷿���ţ�");
	scanf("%d", &ID);
	TYPE_ROOM* curr = head;
	int found = 0;
	while (curr)
	{
		Single_room* single_curr = curr->room;
		while (single_curr)
		{
			if (single_curr->ID == ID)
			{
				found = 1;
				if (strcmp(condition, "cold season") == 0)
				{
					single_curr->price *= 0.85;
				}
				else if (strcmp(condition, "hot season") == 0)
				{
					single_curr->price *= 1.85;

				}
				else if (strcmp(condition, "weekend") == 0)
				{
					single_curr->price *= 1.85;
				}
				else if (strcmp(condition, "weekday") == 0)
				{
					single_curr->price *= 0.85;
				}
				else
				{
					printf("������Ч\n");
					return;
				}
				printf("����%d�ļ۸��ѵ���Ϊ�¼۸�%.2lf\n", ID, single_curr->price);
				break;
			}
			single_curr = single_curr->next;
		}
		if (found)
			break;
		curr = curr->next;
	}
	if (!found)
	{
		printf("�������ʧ��\n");
		return;
	}
	write_to_file(head, "D:\\code\\vs2022\\c����ʵ�����\\data.txt");
	return;
}


void adjust_vip_discount()
{
	set_vip_discount();
	read_vip_discount();
}