// test_system.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Topic_lib.h"
#include "getTopic.h"


int main(int argc, char ** argv)
{
	//MYSQL connect_mysql;
	//mysql_init(&connect_mysql);
	//if (&connect_mysql == NULL)
	//	std::cout << "initialized error" << std::endl;

	//if (!mysql_real_connect(&connect_mysql, "127.0.0.1"
	//	, "root", "tcsw930605", nullptr, 3306, nullptr, 0))
	//{
	//	std::cout << "connect error" << std::endl;
	//	system("pause");
	//	exit(1);
	//}
	//if (mysql_query(&connect_mysql, "create database test1"))
	//{
	//	std::cout << mysql_errno(&connect_mysql) << mysql_error(&connect_mysql) << std::endl;
	//	system("pause");
	//	exit(1);
	//}


	//if (mysql_query(&connect_mysql, "drop database test1"))
	//{
	//	std::cout << mysql_errno(&connect_mysql) << mysql_error(&connect_mysql) << std::endl;
	//	system("pause");
	//	exit(1);
	//}

	//mysql_close(&connect_mysql);
	//system("pause");
	//return 0;

	if (!connect_to_mysql("localhost", "root", "tcsw930605", "test_system", 3306))
	{
		system("pause");
		return 1;
	}
	create_table("a10", "test1");
	system("pause");
}




