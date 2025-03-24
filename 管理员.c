#include"declare.h"
int main()
{
	const char* filename = "D:\\code\\vs2022\\c语言实验设计\\data.txt";
	int n;
	do
	{
		printf("********功能菜单********\n");
		printf("**                    **\n");
		printf("**      0.  退出      **\n");
		printf("**      1.  登录      **\n");
		printf("**      2.  注册      **\n");
		printf("**                    **\n");
		printf("************************\n");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("********身份选择********\n");
			printf("**                    **\n");
			printf("**   1.  管理员       **\n");
			printf("**   2.  前台         **\n");
			printf("**   3.  客人         **\n");
			printf("**                    **\n");
			printf("************************\n");
			scanf("%d", &n);
			if (n == 1)
			{	
				if (log_in_member())
				{
					do
					{
						printf("*****管理员功能界面*****\n");
						printf("**                    **\n");
						printf("**   0.  退出         **\n");
						printf("**   1.  基础信息     **\n");
						printf("**   2.  信息管理     **\n");
						printf("**   3.  信息查询     **\n");
						printf("**   4.  信息排序     **\n");
						printf("**   5.  信息统计     **\n");
						printf("**   6.  系统维护     **\n");
						printf("**   7.  其他         **\n");
						printf("**                    **\n");
						printf("************************\n");

						int choice_0;
						scanf("%d", &choice_0);


						if (choice_0 == 0)
						{
							exit(0);
						}
						else if (choice_0 == 1)
						{
							printf("1.增加信息\n");
							printf("2.删除信息\n");
							printf("3.修改信息\n");
							int choice_1;
							scanf("%d", &choice_1);
							if (choice_1 == 1)
							{
								int choice_2;
								printf("1.客房\n");
								printf("2.客人\n");
								if (choice_2 == 1)
								{
									add_room_type();
								}
								else if (choice_2 == 2)
								{
									add_cus();
								}
							}
							else if (choice_1 == 2)
							{
								int choice_2;
								printf("1.客房\n");
								printf("2.客人\n");
								if (choice_2 == 1)
								{
									delete_room_type();
								}
								else if (choice_2 == 2)
								{
									delete_customer_type();
								}
							}
							else if (choice_1 == 3)
							{
								int choice_2;
								printf("1.客房\n");
								printf("2.客人\n");
								if (choice_2 == 1)
								{
									adjust_information_room();
								}
								else if (choice_2 == 2)
								{
									adjust_information_cus();
								}
							}
						}
						else if (choice_0 == 2)
						{
							int choice_2;
							printf("1.调整房间类型\n");
							printf("2.调整客人类型\n");
							printf("3.调整设置房间价格\n");
							printf("4.调整客人折扣程度\n");
							scanf("%d", &choice_2);

							if (choice_2 == 1)
							{
								adjust_room_type();
							}
							else if (choice_2 == 2)
							{
								adjust_cus_type();
							}
							else if (choice_2 == 3)
							{
								adjust_room_price();
							}
							else if (choice_2 == 4)
							{
								adjust_vip_discount();
							}
						}
						else if (choice_0 == 3)
						{
							//信息查询
						}
						else if (choice_0 == 4)
						{
							//信息排序
						}
						else if (choice_0 == 5)
						{
							//信息统计
						}
						else if (choice_0 == 6)
						{
							//系统维护
						}
					} while (1);
				}
				
			}
		}
		else if (n == 2)
		{
			printf("********身份选择********\n");
			printf("**                    **\n");
			printf("**   1.  管理员       **\n");
			printf("**   2.  前台         **\n");
			printf("**   3.  客人         **\n");
			printf("**                    **\n");
			printf("************************\n");
			scanf("%d", &n);
			if (n == 1)
			{
				regist_member();
				continue;
			}
		}
		else if (n == 0)
		{
			exit(0);
		}
		else
		{
			printf("输入错误,即将返回初始目录\n");
			continue;
		}
	} while (n != 0);



	
}