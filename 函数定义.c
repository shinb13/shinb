#include"declare.h"

double vip_discounts[4] = { 0.8,0.85,0.9,1.0 };

CONVERT convert[] = {
	(CONVERT)convert_location,
	(CONVERT)convert_vip_level,
	(CONVERT)convert_status_cus,
	(CONVERT)convert_status_room,
};													//����ָ�����飬��������ַ���תö���͵��ĸ�����

RECONVERT reconvert[] = {
	(RECONVERT)reconvert_location,
	(RECONVERT)reconvert_vip_level,
	(RECONVERT)reconvert_status_cus,
	(RECONVERT)reconvert_status_room,
};


Single_room* single_newpoint(int ID,double price,char* status,char* location)			//�ڲ��½�
{
	Single_room* new = (Single_room*)malloc(sizeof(Single_room));
	new->ID = ID;
	new->price = price;
	new->status = convert[3](status);
	new->location = convert[0](location);
	new->next = NULL;
	return new;
}

Single_room* single_connect(Single_room* head, int ID, double price, char* status, char* location)
{
	Single_room* new = single_newpoint(ID, price, status, location);
	if (head == NULL)
		head = new;
	else
	{
		Single_room* curr = head; 
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
	return head;
}

Single_room* deletesingle(Single_room* head, int ID)
{
	Single_room* curr = head;
	Single_room* prev = NULL;
	while (curr != NULL && curr->ID != ID)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
		head = head->next;
	else
	{
		prev->next = curr->next;
	}
	free(curr);
	printf("��ɾ������%d\n", ID);
	return head;
}

TYPE_ROOM* read_from_file(const char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)		//ע��=��==�����ȼ����������ŻὫfopen(filename, "r") == NULL�Ľ������fp�����޷��������ļ�
	{
		printf("Failed to open the file");
		exit(0);
	}
	TYPE_ROOM* head = NULL, * tail = NULL,*curr=NULL;
	Single_room room;
	int num;
	float size;
	char _typename[100];
	int ID;
	double price;
	char status[20];
	char location[20];
	while (fscanf(fp, "%d,%f,%[^,],%d,%lf,%[^,],%[^,\n]\n", &num, &size, _typename, &ID, &price, status, location) == 7)			//%[^,] ��Ϊ���ɶ�ȡֱ������','(����ȡ����)  Ȼ����������  [^,\n]��Ϊ�ڶ�ȡ���һ����ʱ�����\n��ҲҪ����
	{	
		if (curr==NULL||curr->num != num || curr->size != size || strcmp(curr->typename, _typename) != 0)							//curr==NULL�ж��Ƿ�Ϊͷ�ڵ�,���жϵĻ������º�������NULL����Ȩ�޳�ͻ
		{
			TYPE_ROOM* new = (TYPE_ROOM*)malloc(sizeof(TYPE_ROOM));
			new->num = num;
			new->size = size;
			strcpy(new->typename, _typename);
			new->room = NULL;
			new->next = NULL;
			if (head == NULL)
			{
				head = new;
			}
			else
			{
				tail->next = new;
			}
			tail = new;
			curr = new;
		}
		curr->room=single_connect(curr->room, ID, price, status, location);
	}
	fclose(fp);
	return head;
}


void write_to_file(TYPE_ROOM* head,const char* filename)
{
	TYPE_ROOM* curr = head;
	FILE* fp = fopen(filename, "w");		//ֻдģʽ
	if (fp == NULL)
	{
		printf("Open failed\n");
		return;		//void��return�󲻼�0
	}
	while (curr)
	{
		Single_room* roomcurr = curr->room;
		while (roomcurr)
		{
			fprintf(fp, "%d,%.2f,%s,%d,%.2lf,%s,%s\n",
				curr->num,
				curr->size,
				curr->typename,
				roomcurr->ID,
				roomcurr->price, 
				reconvert[3](roomcurr->status),
				reconvert[0](roomcurr->location));
			roomcurr = roomcurr->next;
		}
		
		curr = curr->next;
	}
	fclose(fp);
}




CUSTOMER* read_from_cusdatafile(const char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)		//ע��=��==�����ȼ����������ŻὫfopen(filename, "r") == NULL�Ľ������fp�����޷��������ļ�
	{
		printf("Failed to open the file");
		exit(0);
	}
	CUSTOMER* head = NULL, * tail = NULL;
	int number;
	char ID[19];
	char name[20];
	char vip_level[20];
	while (fscanf(fp, "%d,%[^,],%[^,],%[^,\n]", &number, ID, name, vip_level) == 4)			//%[^,] ��Ϊ���ɶ�ȡֱ������','(����ȡ����)  Ȼ����������  [^,\n]��Ϊ�ڶ�ȡ���һ����ʱ�����\n��ҲҪ����
	{
		CUSTOMER* new = (CUSTOMER*)malloc(sizeof(CUSTOMER));
		new->number = number;
		strcpy(new->ID, ID);
		strcpy(new->name, name);
		new->vip_level = convert[1](vip_level);
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

double cus_vip_discount(char* str)			//�����ۿ�
{
	enum VIP_LEVEL temp = convert[1](str);
	if (temp == 0)
		return vip_discounts[0];
	else if (temp == 1)
		return vip_discounts[1];
	else if (temp == 2)
		return vip_discounts[2];
	else if (temp == 3)
		return vip_discounts[3];
}



void write_to_cusdatafile(CUSTOMER* head, const char* filename)
{
	CUSTOMER* curr = head;
	FILE* fp = fopen(filename, "w");		//ֻдģʽ
	if (fp == NULL)
	{
		printf("Open failed\n");
		return;		//void��return�󲻼�0
	}
	while (curr)
	{
		fprintf(fp, "%d,%s,%s,%s\n",
			curr->number,
			curr->ID,
			curr->name,
			reconvert[1](curr->vip_level));
		curr = curr->next;
	}
	fclose(fp);
}


void read_vip_discount()
{
	FILE* fp = fopen("D:\\code\\vs2022\\c����ʵ�����\\vip_discount.txt","r");
	if (fp == NULL)
	{
		printf("��������\n");
		return;
	}
	fscanf(fp, "%lf,%lf,%lf,%lf", &vip_discounts[0], &vip_discounts[1], &vip_discounts[2], &vip_discounts[3]);
	fclose(fp);
}

void set_vip_discount()
{
	FILE* fp = fopen("D:\\code\\vs2022\\c����ʵ�����\\vip_discount.txt", "w");
	double new_discount[4] = { 0 };
	printf("��������vip�ȼ���Ӧ�ۿۣ�");
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &new_discount[i]);
		fprintf(fp, "%.2lf,", new_discount[i]);
	}
	fclose(fp);
}



void print(TYPE_ROOM* head)
{
	TYPE_ROOM* curr = head;
	while (curr)
	{
		printf("typename is: %s\n", curr->typename);
		curr = curr->next;
	}
}


