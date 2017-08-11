//
// Created by lianlian on 17-8-10.
//
#include <sstream>
#include <memory>
#include <iostream>
#include "Topic_lib.h"
static const char separator_line = ';'; //分隔符 excel行分隔符
static const char separator_ans= ' '; //分隔符 excel答案分隔符

/**
 * 构造函数
 * @param line 一行包括问题，回答，答案
 */
Topic::Topic(const std::string &line) {
    std::stringstream stringGet(line);
    std::unique_ptr<std::string> temp = std::make_unique<std::string>();
    getline(stringGet,*temp,separator_line);
    mQuestion = *temp;
    getline(stringGet,*temp,separator_line);
    mOption = getOption(*temp);
    getline(stringGet,*temp);
    mAnswer = getAnswer(*temp);
    mNumber = mTopicNumber++;
}

/**
 * 获得回答选项的list
 * @param optionLine 得到的所有回答，用separator_ans 分割
 * @return 回答的set
 */
std::set<std::string> Topic::getOption(std::string &optionLine) {
    std::stringstream ssLine(optionLine);
    std::string temp;
    std::set<std::string> result;
    while(getline(ssLine,temp,separator_ans)||getline(ssLine,temp)){
        result.insert(temp);
    }
    return result;
}

Topic::~Topic() {

}



/**
 * 拷贝构造函数
 * @param rhs
 */
Topic::Topic(const Topic &rhs) :mQuestion(rhs.mQuestion),mAnswer(rhs.mAnswer)
        ,mOption(rhs.mOption),mNumber(rhs.mNumber)
{

}

/**
 * 移动构造函数
 * @param rhs
 */
Topic::Topic(Topic &&rhs) :mQuestion(std::move(rhs.mQuestion)),mAnswer(std::move(rhs.mAnswer))
        ,mOption(std::move(rhs.mOption)),mNumber(std::move(rhs.mNumber)){

}

/**
 * 拷贝赋值运算符
 * @param rhs
 * @return
 */
Topic &Topic::operator=(const Topic &rhs) {
    mQuestion = rhs.mQuestion;
    mAnswer = rhs.mAnswer;
    mNumber = rhs.mNumber;
    mOption = rhs.mOption;
    return *this;
}

/**
 * 移动赋值运算符
 * @param rhs
 * @return
 */
Topic &Topic::operator=(Topic &&rhs) {
    mQuestion = std::move(rhs.mQuestion);
    mAnswer = std::move(rhs.mAnswer);
    mNumber = std::move(rhs.mNumber);
    mOption = std::move(rhs.mOption);
    return *this;
}

/**
 * 比较相等运算符
 * @param lhs 左值
 * @param rhs 右值
 * @return
 */
bool operator==(const Topic &lhs, const Topic &rhs) {
    return lhs.mNumber==rhs.mNumber;
}

/**
 * 比较大小运算符
 * @param lhs 左值
 * @param rhs 右值
 * @return
 */
bool operator<(const Topic &lhs, const Topic &rhs) {
    return lhs.mNumber< rhs.mNumber;
}

singleTopic::~singleTopic() {

}

/*
 * 写多了，压根不需要virtual这个 = =!
std::set<std::string> singleTopic::getOption(std::string &optionLine) {

}
*/

/**
 * 单选题获取正确答案的函数
 * @param optionLine
 * @return
 */
std::set<size_t> singleTopic::getAnswer(std::string &optionLine) {
    std::set<size_t > result;
    char temp = optionLine[0];
    if (temp != '\0' && temp >= 65 && temp <= 97) {
            result.insert(static_cast<unsigned long &&>(temp - 65));
    }
}


multiTopic::~multiTopic() {

}


/**
 * 判断题获取正确答案的函数
 * @param optionLine 获取到的答案
 * @return 答案的set
 */
std::set<size_t> multiTopic::getAnswer(std::string &optionLine) {
    std::set<size_t > result;
    for (char temp: optionLine) {
        if (temp != '\0' && temp >= 65 && temp <= 97) {
            result.insert(static_cast<unsigned long &&>(temp - 65));
        }
        else
            throw std::out_of_range("答案必须在26个字母里选择诶！");
    }
    return result;
}

boolTopic::~boolTopic() {

}

/**
 * 多选题获取正确答案的函数
 * @param optionLine 获取到的答案
 * @return 答案的set
 */
std::set<size_t> boolTopic::getAnswer(std::string &optionLine) {
    std::set<size_t > result;
    char temp = optionLine[0];
    if(temp == 'y' || temp == 'Y')
        result.insert(1);
    else if(temp == 'X' || temp == 'x')
        result.insert(0);
    else
        throw std::out_of_range("判断题答案必须为X，Y");
    return result;

}

