#include"declare.h"
char* data_filename = "D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt";
char* cus_data_filename = "D:\\code\\vs2022\\c����ʵ�����\\cus_data.txt";
void adjust_information_room()
{
	TYPE_ROOM* head = read_from_file(data_filename);
	int ID;
	int found = 0;
	printf("��������޸ķ���ţ�");
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
	printf("����÷��������Ϣ����������ţ��۸�״̬��λ�ã���");
	double price;
	char status;
	char location;
	scanf("%d,%lf,%[^,],%[^,\n]", &ID, &price, status, location);
	write_to_file(head, data_filename);
	printf("�޸ĳɹ���\n");
}


void adjust_information_cus()
{
	CUSTOMER* head = read_from_cusdatafile(cus_data_filename);
	char* ID[19];
	printf("����������ͻ����֤�ţ�");
	scanf("%s", ID);
	CUSTOMER* curr = search_cus(head, ID);
	int number;
	char ID[19];
	char name[20];
	char vip_level[20];
	printf("����ͻ���Ϣ���������������֤�ţ�������vip�ȼ���(Ӣ�Ķ������)��");
	scanf("%d,%[^,],%[^,],%[^,\n]", &number, ID, name, vip_level);
	write_to_cusdatafile(head,cus_data_filename);
	printf("�޸ĳɹ�\n");
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
		printf("���ҷ���ʧ�ܣ������������˵�\n");
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
	printf("���ҿ���ʧ�ܣ������������˵�\n");
	return NULL;
}