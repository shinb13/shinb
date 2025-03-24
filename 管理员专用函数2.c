#include"declare.h"
char* data_filename = "D:\\code\\vs2022\\c语言实验设计\\cus_data.txt";
char* cus_data_filename = "D:\\code\\vs2022\\c语言实验设计\\cus_data.txt";
void adjust_information_room()
{
	TYPE_ROOM* head = read_from_file(data_filename);
	int ID;
	int found = 0;
	printf("请输入待修改房间号：");
	scanf("%d", &ID);
	TYPE_ROOM* curr = head;
	Single_room* roomcurr;
	while (curr)
	{
		roomcurr = curr->room;
		while (roomcurr != NULL && roomcurr->ID != ID)
			roomcurr - roomcurr->next;
		if (roomcurr != NULL)
		{
			found = 1;
			return roomcurr;
		}
		curr = curr->next;
	}
	printf("输入该房间各项信息（包括房间号，价格，状态，位置）：");
	double price;
	char status;
	char location;
	scanf("%d,%lf,%[^,],%[^,\n]", &ID, &price, status, location);
	write_to_file(head, data_filename);
	printf("修改成功！\n");
}


void adjust_information_cus()
{
	CUSTOMER* head = read_from_cusdatafile(cus_data_filename);
	char* ID[19];
	printf("输入待调整客户身份证号：");
	scanf("%s", ID);
	CUSTOMER* curr = search_cus(head, ID);
	int number;
	char ID[19];
	char name[20];
	char vip_level[20];
	printf("输入客户信息（包括人数，身份证号，姓名，vip等级）(英文逗号相隔)：");
	scanf("%d,%[^,],%[^,],%[^,\n]", &number, ID, name, vip_level);
	write_to_cusdatafile(head,cus_data_filename);
	printf("修改成功\n");
}


Single_room* search_room(TYPE_ROOM* head, int ID)
{
	int found = 0;
	TYPE_ROOM* curr = head;
	while (curr)
	{
		Single_room* roomcurr = curr->room;
		while (roomcurr != NULL && roomcurr->ID != ID)
			roomcurr - roomcurr->next;
		if (roomcurr != NULL)
		{
			found = 1;
			return roomcurr;
		}
		curr = curr->next;
	}
	if (!found)
	{
		printf("查找房间失败，即将返回主菜单\n");
		return NULL;
	}
}

CUSTOMER* search_cus(CUSTOMER* head, char* ID)
{
	CUSTOMER* curr = head;
	while (curr)
	{
		if (strcmp(curr->ID, ID) != 0)
			return curr;
		curr = curr->next;
	}
	printf("查找客人失败，即将返回主菜单\n");
	return NULL;
}