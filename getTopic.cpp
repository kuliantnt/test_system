/*!
 * \file getTopic.cpp
 *
 * \author ����tnt
 * \date ���� 2017
 *
 * getTopic���Դ�ļ�
 */
#include "stdafx.h"
#include "getTopic.h"



Topics get_topics(cnt_str_ref _source_file, cnt_str_ref name)
{
	size_t line_number = 1;
	Topics topics(name);
	std::string line;
	std::fstream source_fs(_source_file);
	getline(source_fs, line); //ȥ��һ��û�õ���Ŀ
	line_number += 1; //��Ŀ�ǵ����п�ʼ��
	while (getline(source_fs, line)) {
		try {
			line_number++;
			if (topics.addTopic(line))
			{
				std::cout << "����ɹ�" << std::endl;
			}
			else
			{
				throw std::runtime_error("����ʧ��");
			}
		}
		catch (const std::runtime_error& e) {
			std::cerr << "��" << line_number << "�г������⣬�����Ƿ��пո�����������";
		}
		catch (...) {
			std::cerr << "����δ֪����" << std::endl;
			std::exit(1);
		}
	}
	return topics;
}

MYSQL m_sql_con; //���뵽�Ծ������ݿ�
bool connect_to_mysql(cnt_str_ref host, cnt_str_ref name, cnt_str_ref passwd, cnt_str_ref db, unsigned int port)
{
	try
	{
		mysql_init(&m_sql_con);
		if (!mysql_real_connect(&m_sql_con, host.c_str(), name.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0))
		{
			std::cerr << "����ʧ�ܣ��������ݿ��������" << std::endl;
			return false;
		}
		std::cout << "���ӳɹ�" << std::endl;
		return true;
	}
	catch(...)
	{
		std::cerr << "δ֪ԭ������Ĵ���" << std::endl;
		return false;
	}
}

bool create_table(cnt_str_ref ID, cnt_str_ref NAME)
{
	MYSQL_RES* result = mysql_list_tables(&m_sql_con, "TEST_INDEX");
	MYSQL_ROW row = mysql_fetch_row(result);
	if (!row)
	{
		std::cout << "�ñ�������,���ڴ����������ݿ�" << std::endl;
		mysql_query(&m_sql_con, 
			"CREATE TABLE `test_system`.`test_index` (\
			`ID` INT NOT NULL,\
			`NAME` VARCHAR(99) NOT NULL,\
			PRIMARY KEY(`ID`));"
		);
	}
	return true;
}
