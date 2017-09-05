//
// Created by lianlian on 17-8-10.
//
#pragma once
#include "stdafx.h"


/*!
 * \class Topic
 *
 * \brief 题目的基类，也就是存储题目的地方
 *
 * \author 哭脸tnt
 * \date 九月 2017
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
	Topic(const std::string qustion, const std::string& option
		, const std::string& Answer, double scorce);
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
	std::set<std::string> getOption(const std::string &optionLine) const;
private:
	std::string mQuestion;   //问题
	std::string mOption;    //选项
	std::string mAnswer;     //答案
	size_t mNumber; //题目真正的编号
	double mScore;//分数
	std::string mTopicType; //题目类型
};


/*!
 * \class Topics
 *
 * \brief 试卷类
 *
 * \author 哭脸tnt
 * \date 九月 2017
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
	static bool returnToSql();
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