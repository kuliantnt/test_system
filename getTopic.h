#pragma once

/**
 * �������Ҫ���ڸ�����Ҫ�ļ��Ļ�ȡ
 */
#include "stdafx.h"
#include "Topic_lib.h"


inline Topics get_topics(std::string& _source_file, std::string& name) {
	size_t line_number = 1;
	Topics topics(name);
	std::string line;
	std::fstream source_fs(_source_file);
	getline(source_fs, line); //ȥ��һ��û�õ���Ŀ
	line_number += 1; //��Ŀ�ǵ����п�ʼ��
	while (getline(source_fs, line)) {
		try {
			line_number++;
			topics.addTopic(line);
		}
		catch (std::runtime_error& e) {
			std::cerr << "��" << line_number << "�г������⣬�����Ƿ��пո�����������";
		}
		catch (...) {
			std::cerr << "����δ֪����" << std::endl;
			std::exit(1);
		}
	}
	return topics;
}


