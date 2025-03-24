#include"declare.h"



void member_write_to_file(const char* filename, char* account, char* password)
{
	FILE* fp = fopen(filename, "a+");		
	if (fp == NULL)
	{
		printf("Open failed\n");
		return;		//void型return后不加0
	}
	fprintf(fp, "%s,%s\n", account, password);
	printf("注册成功！\n");
	fclose(fp);
}

void regist_member()
{
	FILE* fp;
	if ((fp = fopen("D:\\code\\vs2022\\c语言实验设计\\manager.txt", "a+")) == NULL)
	{
		printf("系统崩溃啦!");
		return 0;
	}
	char hide;
	int i = 0;
	char acc[20];
	char pas[20];
	printf("请输入账号：");
	scanf("%s", acc);
	printf("请输入密码：");
	while (1)
	{
		hide = getch();
		if (hide == 13)//13对应"\r" 回车
		{
			pas[i] = '\0';
			break;
		}
		else if (hide == 8 && i > 0)//ascii 8对应"\b"退格
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
	member_write_to_file("D:\\code\\vs2022\\c语言实验设计\\member.txt", acc, pas);
}


void add_room_type()
{
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c语言实验设计\\data.txt");
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
	printf("输入该类型房间数量，大小以及类型名：");
	scanf("%d%f%s", &num, &size, typename);
	printf("依次输入该类型下各房间信息（包含房间号，价格，状态，位置）,英文逗号相隔");
	for (int i = 0; i < num; i++)
	{
		scanf("%d,%f,%[^,],%[^,\n]\n", &ID,&price,status,location);
		curr->room=single_connect(curr->room, ID, price, status, location);
		curr = curr->next;
	}
	curr->next = NULL;
	write_to_file(head, "D:\\code\\vs2022\\c语言实验设计\\data.txt");
}

void add_cus()
{
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
	CUSTOMER* curr = head;
	int number;
	char ID[19];
	char name[20];
	char vip_level[20];
	printf("请输入客人相关信息（包括人数，身份证，姓名，VIP等级）");
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
	write_to_cusdatafile(head, "D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
}


void delete_room_type()
{
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c语言实验设计\\data.txt");
	TYPE_ROOM* curr = head;
	int ID;
	printf("请输入要删除的房间ID：");
	scanf("%d", ID);
	int found = 0;
	while (curr)
	{
		curr->room = deletesingle(curr->room, ID);
	}
	write_to_file(head, "D:\\code\\vs2022\\c语言实验设计\\data.txt");
}

void delete_customer_type()
{
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
	CUSTOMER* curr = head, * prev = NULL;
	char ID[19];
	printf("输入删除客人的身份证号：");
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
	write_to_cusdatafile(head, "D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
}




void adjust_room_type()
{
	TYPE_ROOM* head = read_from_file(data_filename);
	TYPE_ROOM* curr = head, *prev = NULL;
	Single_room* roomcurr;
	Single_room* roomprev = NULL;
	int ID;
	int found = 0;
	printf("输入待调整房间类型：");
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
		printf("查找房间失败，即将返回主菜单\n");
		return;
	}
	char typename[20];
	printf("输入新类型\n");
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
	printf("%d房间类型已修改为%s", ID, typename);
	write_to_file(head, data_filename);
}




void adjust_cus_type()
{
	char ID[19];
	printf("输入客人身份证号：");
	scanf("%s", ID);
	CUSTOMER* head = read_from_cusdatafile("D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
	CUSTOMER* curr = head;
	while (curr)
	{
		if (strcmp(curr->ID,ID)==0)
			break;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		printf("寻找客人失败\n");
		return;
	}
	else
	{
		char newlevel[20];
		printf("输入客人VIP等级：");
		scanf("%s", newlevel);
		curr->vip_level= convert_vip_level(newlevel);
		printf("修改成功\n");
		write_to_cusdatafile(head, "D:\\code\\vs2022\\c语言实验设计\\cus_data.txt");
		return;
	}
}


void adjust_room_price()
{
	char* condition[20];
	printf("输入当前情况（cold season/hot season/weekend/weekday）：");
	getchar();
	scanf("%[^\n]", condition);
	TYPE_ROOM* head = read_from_file("D:\\code\\vs2022\\c语言实验设计\\data.txt");
	int ID;
	printf("请输入房间编号：");
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
					printf("输入无效\n");
					return;
				}
				printf("房间%d的价格已调整为新价格：%.2lf\n", ID, single_curr->price);
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
		printf("房间查找失败\n");
		return;
	}
	write_to_file(head, "D:\\code\\vs2022\\c语言实验设计\\data.txt");
	return;
}


void adjust_vip_discount()
{
	set_vip_discount();
	read_vip_discount();
}