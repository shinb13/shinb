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
void print(TYPE_ROOM* head);														//打印链表
TYPE_ROOM* read_from_file(const char* filename);									//客房读取
void write_to_file(TYPE_ROOM* head, const char* filename);							//客房写入
double cus_vip_discount(char* str);													//客人折扣程度

void read_vip_discount();															//vip折扣读取
void set_vip_discount();															//vip折扣写入

Single_room* search_room(TYPE_ROOM* head, int ID);				//查找特定房间
CUSTOMER* search_cus(CUSTOMER* head, char* ID);					//查找客人


CUSTOMER* read_from_cusdatafile(const char* filename);								//客人读取
void write_to_cusdatafile(CUSTOMER* head, const char* filename);					//客人写入


enum STATUS_ROOM convert_location(char* str);
enum STATUS_ROOM convert_vip_level(char* str);
enum STATUS_ROOM convert_status_cus(char* str);
enum STATUS_ROOM convert_status_room(char* str);
char* reconvert_status_cus(enum STATUS_CUS type);
char* reconvert_vip_level(enum VIP_LEVEL type);
char* reconvert_location(enum LOCATION type);
char* reconvert_status_room(enum STATUS_ROOM type);



typedef int(*CONVERT)(char* str);//定义函数指针类型？
typedef char* (*RECONVERT)(int);



Single_room* single_newpoint(int ID, double price, char* status, char* location);
Single_room* single_connect(Single_room* head, int ID, double price, char* status, char* location);
Single_room* deletesingle(Single_room* head, int ID);													//内层链表删除

void member_write_to_file(const char* filename, char* account, char* password);		//成员读取
MEMBER* member_data(const char* filename);											//成员读取
int ifcorrect(MEMBER* head, char* account, char* password);							//账密正误
int log_in_member();																//用户登录
void regist_member();																//用户注册



void add_room_type();								//增加房间类型

void add_cus();										//增加客人信息
									
void delete_room_type();							//删除单个房间

void delete_customer_type();						//删除单个客人

void adjust_information_room();						//调整房间信息

void adjust_information_cus();						//调整客人信息

void adjust_room_type();							//修改房间类型

void adjust_cus_type();								//修改客人类型

void adjust_room_price();							//修改房间价格

void adjust_vip_discount();							//vip折扣修改
#endif