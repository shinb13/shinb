#include"declare.h"
int main()
{
	const char* filename = "D:\\code\\vs2022\\c����ʵ�����\\data.txt";
	int n;
	do
	{
		printf("********���ܲ˵�********\n");
		printf("**                    **\n");
		printf("**      0.  �˳�      **\n");
		printf("**      1.  ��¼      **\n");
		printf("**      2.  ע��      **\n");
		printf("**                    **\n");
		printf("************************\n");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("********���ѡ��********\n");
			printf("**                    **\n");
			printf("**   1.  ����Ա       **\n");
			printf("**   2.  ǰ̨         **\n");
			printf("**   3.  ����         **\n");
			printf("**                    **\n");
			printf("************************\n");
			scanf("%d", &n);
			if (n == 1)
			{	
				if (log_in_member())
				{
					do
					{
						printf("*****����Ա���ܽ���*****\n");
						printf("**                    **\n");
						printf("**   0.  �˳�         **\n");
						printf("**   1.  ������Ϣ     **\n");
						printf("**   2.  ��Ϣ����     **\n");
						printf("**   3.  ��Ϣ��ѯ     **\n");
						printf("**   4.  ��Ϣ����     **\n");
						printf("**   5.  ��Ϣͳ��     **\n");
						printf("**   6.  ϵͳά��     **\n");
						printf("**   7.  ����         **\n");
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
							printf("1.������Ϣ\n");
							printf("2.ɾ����Ϣ\n");
							printf("3.�޸���Ϣ\n");
							int choice_1;
							scanf("%d", &choice_1);
							if (choice_1 == 1)
							{
								int choice_2;
								printf("1.�ͷ�\n");
								printf("2.����\n");
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
								printf("1.�ͷ�\n");
								printf("2.����\n");
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
								printf("1.�ͷ�\n");
								printf("2.����\n");
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
							printf("1.������������\n");
							printf("2.������������\n");
							printf("3.�������÷���۸�\n");
							printf("4.���������ۿ۳̶�\n");
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
							//��Ϣ��ѯ
						}
						else if (choice_0 == 4)
						{
							//��Ϣ����
						}
						else if (choice_0 == 5)
						{
							//��Ϣͳ��
						}
						else if (choice_0 == 6)
						{
							//ϵͳά��
						}
					} while (1);
				}
				
			}
		}
		else if (n == 2)
		{
			printf("********���ѡ��********\n");
			printf("**                    **\n");
			printf("**   1.  ����Ա       **\n");
			printf("**   2.  ǰ̨         **\n");
			printf("**   3.  ����         **\n");
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
			printf("�������,�������س�ʼĿ¼\n");
			continue;
		}
	} while (n != 0);



	
}