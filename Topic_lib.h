﻿/*!
 * \file Topic_lib.h
 *
 * \author 哭脸tnt
 * \date 九月 2017
 *
 * getTopic 库的头文件
 */
#pragma once
#include "stdafx.h"


/**
 * 题目的基类
 */
class Topic;
bool operator== (const Topic&lhs, const Topic&rhs);
bool operator< (const Topic&lhs,const Topic&rhs);
std::ostream& operator<< (std::ostream& os,const Topic&);
class Topic {
public:
	//友元
	friend bool operator==(const Topic &lhs, const Topic &rhs);
	friend bool operator<(const Topic &lhs, const Topic &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Topic &);
	//默认构造函数
	Topic() = delete; //不允许默认构造函数
	Topic(const std::string &line);
	Topic(const std::string number, const std::string qustion
		, const std::string & option, const std::string & answer, const std::string& scorce);
	//析构函数
	virtual ~Topic();
	//赋值构造函数
	Topic(const Topic &rhs);
	Topic(Topic &&rhs) noexcept;
	Topic &operator=(const Topic &rhs);
	Topic &operator=(Topic &&rhs) noexcept;
	virtual std::ostream &print(std::ostream &) const;
	//get & set;
	std::string to_string();
	std::string getNumber() const { return mNumber; }
	std::string getQuestion() const;
	std::string getAnswer() const; //标准答案
	std::string getScorce() const { return mScore; }
	std::string getTopicType() { return mTopicType; }
protected:
	//获取问题选项的一个函数
	std::set<std::string> getOption(const std::string &optionLine) const;
private:
	std::string mQuestion;   //问题
	std::string mOption;    //选项
	std::string mAnswer;     //答案
	std::string mNumber; //题目真正的编号
	std::string mScore;//分数
	std::string mTopicType; //题目类型
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
	Topic &operator[](size_t size);
	size_t size();
	const std::string& getName() const { return mName; }
	const std::string& getID() const { return mID; }
	std::ostream &print(std::ostream & os);
	~Topics();
	//添加题目
	bool addTopic(const std::string &);
	//删除题目
	bool deleteTopic(const size_t &);
	//修改题目
	bool modifyTopic(const size_t &, std::shared_ptr<Topic> topic = std::make_shared<Topic>(""));
	//获取分数
	double getScore() const;
	//计算分数
	double calculate_score();
protected:
	void copy_this(const Topics& rhs);
private:
	std::string mName;//试卷名称
	std::string mID = ""; //工号
	std::string mStudent = "";// 考生姓名
	std::vector<std::shared_ptr<Topic>> mTopic;
	std::vector<std::string> mAnswer; //考生的答案集合
	double mScore = 0.0; //分数
};