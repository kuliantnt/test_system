#include "getTopic.h"


MYSQL m_sql_con; //导入到试卷的数据库

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
