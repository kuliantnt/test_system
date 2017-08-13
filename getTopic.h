//
// Created by lianlian on 17-8-13
// 主要用于，获取答案的类
//

#pragma once

#include <fstream>
#include <iostream>
#include "Topic_lib.h"


Topics get_topics(std::string& _source_file,std::string& name){
    Topics topics(name);
    std::string line;
    std::fstream source_fs(_source_file);
    getline(source_fs,line); //去掉一行没用的题目
    while(getline(source_fs,line)){
        try {
            topics.addTopic(line);
        }
        catch(std::runtime_error& e){
            //todo 加载错误行
        }
        catch(...){
            std::cerr << "出现未知错误"<< std::endl;
            std::exit(1);
        }
    }
    return topics;
}

