#include "getTopic.h"

MYSQL m_sqlCon; //创建一个mysql的结构指针

//************************************
// Method:    get_topics
// FullName:  get_topics
// Access:    public 
// Returns:   Topics
// Qualifier:
// Parameter: const_str_ref _source_file
// Parameter: const_str_ref name
//************************************
Topics get_topics(const_str_ref _source_file, const_str_ref name) {
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

bool connect_mysql(const_str_ref server_address, const_str_ref user_name
	, const_str_ref passwd, const_str_ref db,unsigned int port)
{
	mysql_init(&m_sqlCon);
	try
	{
		if (!mysql_real_connect(&m_sqlCon, server_address.c_str(), user_name.c_str()
			, passwd.c_str(), db.c_str(), port, nullptr, 0)) 
		{
			std::cout << "链接失败，请检查数据库参数设置" << std::endl;
			return false;
		}
		std::cout << "数据库链接成功" << std::endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
