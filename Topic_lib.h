//
// Created by lianlian on 17-8-10.
//
#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

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

    std::ostream &print(std::ostream &) const;

    std::ostream &print_Ans(std::ostream &) const;

    size_t getNumber() const { return mNumber; }

    static size_t mTopicNumber; //题目编号

protected:
    //获取问题选项的一个函数
    std::set<std::string> getOption(std::string &optionLine);

    //纯虚函数
    virtual std::set<size_t> getAnswer(std::string &optionLine);

private:
    std::string mQuestion;   //问题
    std::set<std::string> mOption;    //选项
    std::set<size_t> mAnswer;     //答案
    size_t mNumber; //题目真正的编号。
};


/**
 * 单选题
 */
class SingleTopic : public Topic{
    ~SingleTopic();
    std::set<size_t> getAnswer(std::string& optionLine) override;
};

/**
 * 多选题
 */
class MultiTopic:public Topic{
    std::set<size_t> getAnswer(std::string& optionLine) override;
    ~MultiTopic();
};

/**
 * 判断题
 */
class BoolTopic:public Topic{
    std::set<size_t > getAnswer(std::string& optionLine);
    ~BoolTopic();
};

/**
 * 试卷类
 * 嘛。。。好多好多题库放在一起，不是试卷类是什么。。。
 */
class Topics {
public:
    Topics() = delete;

    Topics(const std::string &number, const std::string &name = "", const std::string &ID = ""); //从试卷编号生成试卷。

    Topics(const Topics &);

    Topics(Topics &&);

    Topics &operator==(const Topics &);

    Topics &operator==(Topics &&);

    std::ostream& print(std::ostream&);

    ~Topics();

    //添加题目
    bool addTopic(const std::string &);

    //删除题目
    bool deleteTopic(const size_t &);

    //修改题目
    bool modifyTopic(const size_t &, const std::string &);

private:
    std::string mName;//试卷名称
    std::string mID; //工号
    std::vector<std::shared_ptr<Topic>> mTopic;
};