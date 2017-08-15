#pragma once

/**
 * 这个类主要用于各种需要文件的获取
 */
#include "stdafx.h"
#include "Topic_lib.h"


inline Topics get_topics(std::string& _source_file, std::string& name) {
	size_t line_number = 1;
	Topics topics(name);
	std::string line;
	std::fstream source_fs(_source_file);
	getline(source_fs, line); //去掉一行没用的题目
	line_number += 1; //题目是第三行开始呢
	while (getline(source_fs, line)) {
		try {
			line_number++;
			topics.addTopic(line);
		}
		catch (std::runtime_error& e) {
			std::cerr << "第" << line_number << "行出现问题，请检查是否有空格或者其他情况";
		}
		catch (...) {
			std::cerr << "出现未知错误" << std::endl;
			std::exit(1);
		}
	}
	return topics;
}


