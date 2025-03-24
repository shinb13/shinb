#include"declare.h"


enum VIP_LEVEL convert_vip_level(char* str)
{
	if (strcmp(str, "black") == 0)
	{
		return black;
	}
	else if (strcmp(str, "gold") == 0)
	{
		return gold;
	}
	else if (strcmp(str, "silver") == 0)
	{
		return silver;
	}
	else if (strcmp(str, "common") == 0)
	{
		return common;
	}
}
enum LOCATION convert_location(char* str)
{
	if (strcmp(str, "north") == 0)
	{
		return north;
	}
	else if (strcmp(str, "south") == 0)
	{
		return south;
	}
	else if (strcmp(str, "near_lift") == 0)
	{
		return near_lift;
	}
	else if (strcmp(str, "near_corner") == 0)
	{
		return near_corner;
	}
}
enum STATUS_CUS convert_status_cus(char* str)
{
	if (strcmp(str, "CUS_available") == 0)
	{
		return CUS_available;
	}
	else if (strcmp(str, "CUS_reserved") == 0)
	{
		return CUS_reserved;
	}
	else if (strcmp(str, "living") == 0)
	{
		return living;
	}
	else if (strcmp(str, "leave") == 0)
	{
		return leave;
	}
}
enum STATUS_ROOM convert_status_room(char* str)
{
	if (strcmp(str, "ROOM_available") == 0)
	{
		return ROOM_available;
	}
	else if (strcmp(str, "ROOM_reserved") == 0)
	{
		return ROOM_reserved;
	}
	else if (strcmp(str, "check_in") == 0)
	{
		return check_in;
	}
}


char* reconvert_vip_level(enum VIP_LEVEL type)
{
	if (type == 0)
	{
		return "black";
	}
	else if (type == 1)
	{
		return "gold";
	}
	else if (type == 2)
	{
		return "silver";
	}
	else if (type == 3)
	{
		return "common";
	}
}

char*  reconvert_location(enum LOCATION type)
{
	if (type == 0)
	{
		return "north";
	}
	else if (type == 1)
	{
		return "south";
	}
	else if (type == 2)
	{
		return "near_lift";
	}
	else if (type == 3)
	{
		return "near_corner";
	}
}
char* reconvert_status_cus(enum STATUS_CUS type)
{
	if (type == 0)
	{
		return "CUS_available";
	}
	else if (type == 1)
	{
		return "CUS_reserved";
	}
	else if (type == 2)
	{
		return "living";
	}
	else if (type == 3)
	{
		return "leave";
	}
}

char* reconvert_status_room(enum STATUS_ROOM type)
{
	if (type == 0)
		return "ROOM_available";
	else if (type == 1)
		return "ROOM_reserved";
	else if (type == 2)
		return "check_in";
}
