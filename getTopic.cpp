/*!
 * \file getTopic.cpp
 *
 * \author 哭脸tnt
 * \date 九月 2017
 *
 * getTopic库的源文件
 */
#include "stdafx.h"
#include "getTopic.h"



Topics get_topics(cnt_str_ref _source_file, cnt_str_ref name)
{
	size_t line_number = 1;
	Topics topics(name);
	std::string line;
	std::fstream source_fs(_source_file);
	getline(source_fs, line); //去掉一行没用的题目
	line_number += 1; //题目是第三行开始呢
	while (getline(source_fs, line)) {
		try {
			line_number++;
			if (topics.addTopic(line))
			{
				std::cout << "导入成功" << std::endl;
			}
			else
			{
				throw std::runtime_error("导入失败");
			}
		}
		catch (const std::runtime_error& e) {
			std::cerr << "第" << line_number << "行出现问题，请检查是否有空格或者其他情况";
		}
		catch (...) {
			std::cerr << "出现未知错误" << std::endl;
			std::exit(1);
		}
	}
	return topics;
}

MYSQL m_sql_con; //导入到试卷的数据库
bool connect_to_mysql(cnt_str_ref host, cnt_str_ref name, cnt_str_ref passwd, cnt_str_ref db, unsigned int port)
{
	try
	{
		mysql_init(&m_sql_con);
		if (!mysql_real_connect(&m_sql_con, host.c_str(), name.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0))
		{
			std::cerr << "链接失败，请检查数据库参数设置" << std::endl;
			return false;
		}
		std::cout << "链接成功" << std::endl;
		return true;
	}
	catch(...)
	{
		std::cerr << "未知原因引起的错误" << std::endl;
		return false;
	}
}

bool create_table(cnt_str_ref ID, cnt_str_ref NAME)
{
	MYSQL_RES* result = mysql_list_tables(&m_sql_con, "TEST_INDEX");
	MYSQL_ROW row = mysql_fetch_row(result);
	if (!row)
	{
		std::cout << "该表不存在,正在创建索引数据库" << std::endl;
		mysql_query(&m_sql_con, 
			"CREATE TABLE `test_system`.`test_index` (\
			`ID` INT NOT NULL,\
			`NAME` VARCHAR(99) NOT NULL,\
			PRIMARY KEY(`ID`));"
		);
	}
	return true;
}

