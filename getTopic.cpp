#include "getTopic.h"


MYSQL m_sql_con; //���뵽�Ծ�����ݿ�

//************************************
// Method:    get_topics
// FullName:  get_topics
// Access:    public 
// Returns:   Topics
// Qualifier:
// Parameter: std::string & _source_file
// Parameter: std::string & name
//************************************
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
