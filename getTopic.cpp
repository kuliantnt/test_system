#include "getTopic.h"

MYSQL m_sqlCon; //����һ��mysql�Ľṹָ��

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
	getline(source_fs, line); //ȥ��һ��û�õ���Ŀ
	line_number += 1; //��Ŀ�ǵ����п�ʼ��
	while (getline(source_fs, line)) {
		try {
			line_number++;
			if (topics.addTopic(line))
			{

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

bool connect_mysql(const_str_ref server_address, const_str_ref user_name
	, const_str_ref passwd, const_str_ref db,unsigned int port)
{
	mysql_init(&m_sqlCon);
	try
	{
		if (!mysql_real_connect(&m_sqlCon, server_address.c_str(), user_name.c_str()
			, passwd.c_str(), db.c_str(), port, nullptr, 0)) 
		{
			std::cout << "����ʧ�ܣ��������ݿ��������" << std::endl;
			return false;
		}
		std::cout << "���ݿ����ӳɹ�" << std::endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
