#pragma once
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>


typedef struct Time
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}Time;
enum LOCATION
{
	north,
	south,
	near_lift,
	near_corner
};
enum VIP_LEVEL
{
	black,
	gold,
	silver,
	common,
};
enum STATUS_CUS
{
	CUS_available,
	CUS_reserved,
	living,
	leave,
};
enum STATUS_ROOM
{
	ROOM_available,
	ROOM_reserved,
	check_in,
};
typedef struct Single_room
{
	int ID;
	double price;
	enum STATUS_ROOM status;
	enum LOCATION location;
	struct Single_room* next;
}Single_room;
typedef struct CUSTOMER
{
	int number;
	char ID[19];
	char name[20];
	enum VIP_LEVEL vip_level;
	struct CUSTOMER* next;
}CUSTOMER;
typedef struct TYPE_ROOM
{
	int num;
	float size;
	char typename[100];
	Single_room* room;
	struct TYPE_ROOM* next;
}TYPE_ROOM;
typedef struct MEMBER
{
	char account[20];
	char password[20];
	struct MEMBER* next;
}MEMBER;

extern double vip_discounts[];
const char* data_filename;
const char* cus_data_filename;
void print(TYPE_ROOM* head);														//��ӡ����
TYPE_ROOM* read_from_file(const char* filename);									//�ͷ���ȡ
void write_to_file(TYPE_ROOM* head, const char* filename);							//�ͷ�д��
double cus_vip_discount(char* str);													//�����ۿ۳̶�

void read_vip_discount();															//vip�ۿ۶�ȡ
void set_vip_discount();															//vip�ۿ�д��

Single_room* search_room(TYPE_ROOM* head, int ID);				//�����ض�����
CUSTOMER* search_cus(CUSTOMER* head, char* ID);					//���ҿ���


CUSTOMER* read_from_cusdatafile(const char* filename);								//���˶�ȡ
void write_to_cusdatafile(CUSTOMER* head, const char* filename);					//����д��


enum STATUS_ROOM convert_location(char* str);
enum STATUS_ROOM convert_vip_level(char* str);
enum STATUS_ROOM convert_status_cus(char* str);
enum STATUS_ROOM convert_status_room(char* str);
char* reconvert_status_cus(enum STATUS_CUS type);
char* reconvert_vip_level(enum VIP_LEVEL type);
char* reconvert_location(enum LOCATION type);
char* reconvert_status_room(enum STATUS_ROOM type);



typedef int(*CONVERT)(char* str);//���庯��ָ�����ͣ�
typedef char* (*RECONVERT)(int);



Single_room* single_newpoint(int ID, double price, char* status, char* location);
Single_room* single_connect(Single_room* head, int ID, double price, char* status, char* location);
Single_room* deletesingle(Single_room* head, int ID);													//�ڲ�����ɾ��

void member_write_to_file(const char* filename, char* account, char* password);		//��Ա��ȡ
MEMBER* member_data(const char* filename);											//��Ա��ȡ
int ifcorrect(MEMBER* head, char* account, char* password);							//��������
int log_in_member();																//�û���¼
void regist_member();																//�û�ע��



void add_room_type();								//���ӷ�������

void add_cus();										//���ӿ�����Ϣ
									
void delete_room_type();							//ɾ����������

void delete_customer_type();						//ɾ����������

void adjust_information_room();						//����������Ϣ

void adjust_information_cus();						//����������Ϣ

void adjust_room_type();							//�޸ķ�������

void adjust_cus_type();								//�޸Ŀ�������

void adjust_room_price();							//�޸ķ���۸�

void adjust_vip_discount();							//vip�ۿ��޸�
#endif