//
// Created by lianlian on 17-8-10.
//
#pragma once
#include <map>
#include <set>
#include <string>
/**
 * 一个题目的基类
 */
class Topic;
bool operator==(const Topic&lhs, const Topic&rhs);
bool operator< (const Topic&lhs,const Topic&rhs);
std::ostream& operator<< (std::ostream& os,const Topic&);
class Topic {
public:
    friend bool operator==(const Topic &lhs, const Topic &rhs);

    friend bool operator<(const Topic &lhs, const Topic &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Topic &);

    Topic() = delete; //不允许默认构造函数
    Topic(const std::string &line);

    virtual ~Topic();

    Topic(const Topic &rhs);

    Topic(Topic &&rhs);

    Topic &operator=(const Topic &rhs);

    Topic &operator=(Topic &&rhs);

    static size_t mTopicNumber; //题目编号
    std::ostream &print(std::ostream &) const;

    std::ostream &print_Ans(std::ostream &) const;

private:
    //获取问题选项的一个函数
    std::set<std::string> getOption(std::string &optionLine);

    //纯虚函数
    virtual std::set<size_t> getAnswer(std::string &optionLine);

    std::string mQuestion;   //问题
    std::set<std::string> mOption;    //选项
    std::set<size_t> mAnswer;     //答案
    size_t mNumber; //题目真正的编号。
};
size_t Topic::mTopicNumber = 1;

/**
 * 单选题
 */
class singleTopic : public Topic{
    ~singleTopic();
    std::set<size_t> getAnswer(std::string& optionLine) override;
};

/**
 * 多选题
 */
class multiTopic:public Topic{
    std::set<size_t> getAnswer(std::string& optionLine) override;
    ~multiTopic();
};

/**
 * 判断题
 */
class boolTopic:public Topic{
    std::set<size_t > getAnswer(std::string& optionLine);
    ~boolTopic();
};

/**
 * 试卷类
 * 嘛。。。好多好多题库放在一起，不是试卷类是什么。。。
 */
class Topics{
private:
    std::string mName;//试卷名称
    std::string mClass; //班级

};