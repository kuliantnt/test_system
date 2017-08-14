#pragma once
//
// Created by lianlian on 17-8-13
// ��Ҫ���ڣ���ȡ�𰸵���
//

#pragma once


#include "stdafx.h"
#include "Topic_lib.h"


inline Topics get_topics(std::string& _source_file, std::string& name) {
	Topics topics(name);
	std::string line;
	std::fstream source_fs(_source_file);
	getline(source_fs, line); //ȥ��һ��û�õ���Ŀ
	while (getline(source_fs, line)) {
		try {
			topics.addTopic(line);
		}
		catch (std::runtime_error& e) {
			//todo ���ش�����
		}
		catch (...) {
			std::cerr << "����δ֪����" << std::endl;
			std::exit(1);
		}
	}
	return topics;
}


