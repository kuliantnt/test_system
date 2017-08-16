//
// Created by lianlian on 17-8-10.
//
#pragma once
#include "stdafx.h"


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

	Topic(const std::string qustion, std::set<std::string>& option
		,const std::string& Answer,double scorce);

    virtual ~Topic();

    Topic(const Topic &rhs);

    Topic(Topic &&rhs) noexcept;

    Topic &operator=(const Topic &rhs);

    Topic &operator=(Topic &&rhs) noexcept;

    virtual std::ostream &print(std::ostream &) const;

//    std::ostream &print_Ans(std::ostream &) const;

    size_t getNumber() const { return mNumber; }

	std::string getQuestion() const;

	std::string getAnswer() const; //标准答案

	double getScorce() const
	{
		return mScore;
	}

    static int mTopicNumber; //题目编号

protected:
    //获取问题选项的一个函数
    std::set<std::string> getOption(std::string &optionLine) const;
private:
    std::string mQuestion;   //问题
    std::set<std::string> mOption;    //选项
    std::string mAnswer;     //答案
    size_t mNumber; //题目真正的编号。
    double mScore;//分数
};


/**
 * 单选题
 */
class SingleTopic : public Topic {
public:
	SingleTopic(const std::string&);
	SingleTopic(const std::string qustion, std::set<std::string>& option
		,const std::string& Answer,double scorce);
	~SingleTopic();
protected:
};

/**
 * 多选题
 */
class MultiTopic:public Topic{
public:
    MultiTopic(const std::string&);
	MultiTopic(const std::string qustion, std::set<std::string>& option
	           ,const std::string& Answer,double scorce);
    ~MultiTopic();
protected:
};

/**
 * 判断题
 */
class BoolTopic :public Topic {
public:
	BoolTopic(const std::string&);
	BoolTopic(const std::string qustion, std::set<std::string>& option
	          , const std::string& answer, double scorce);
	virtual std::ostream &print(std::ostream &) const override;
	~BoolTopic();
protected:
};

/**
 * 试卷类
 * 嘛。。。好多好多题库放在一起，不是试卷类是什么。。。
 */
class Topics {
public:
	Topics() = delete;

	Topics(const std::string &name = "");//从试卷编号生成试卷。

	Topics(const Topics &);

	Topics(Topics &&) noexcept;

	Topics &operator==(const Topics &);

	Topics &operator==(Topics &&) noexcept;

	std::ostream &print(std::ostream &);

	std::ostream &print_number(std::ostream &os, size_t num);

	~Topics();

	//添加题目
	bool addTopic(const std::string &);

	//删除题目
	bool deleteTopic(const size_t &);

	//修改题目
	bool modifyTopic(const size_t &, Topic* topic);

	//获取分数
	double getScore() const;

	//计算分数
	double calculate_score();

protected:
	void copy_this(const Topics& rhs);

private:
	std::string mName;//试卷名称
	std::string mID = ""; //工号
	std::string mStudent;// 考生姓名
	std::vector<std::shared_ptr<Topic>> mTopic;
	std::vector<std::string> mAnswer; //考生的答案集合
	double mScore = 0.0; //分数
};