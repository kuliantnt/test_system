//
// Created by lianlian on 17-8-10.
//
// 题目excel顺序为"问题，选项，答案，分数"
#include "stdafx.h"
#include "Topic_lib.h"

static const char separator_line = ','; //分隔符 excel行分隔符
static const char separator_ans= ' '; //分隔符 excel答案分隔符
int Topic::mTopicNumber = 1; //题目的默认编号是0



/**
 * 构造函数
 * @param line 一行包括问题，回答，答案
 */
Topic::Topic(const std::string &line) {
	//这个正则怎么写呀呀呀呀！！！！
    std::stringstream stringGet(line);
	std::string temp;
	getline(stringGet, temp, ',');
	mScore = std::stod(temp);
	getline(stringGet, temp, ',');
	mNumber = std::stoi(temp);
	getline(stringGet, temp, ',');
	mTopicType = temp;
	getline(stringGet, temp, ',');
	mQuestion = temp;
	getline(stringGet, temp, ',');
	mOption = temp;
	getline(stringGet, temp, ',');
	mAnswer = temp;

}

/**
 * \brief 另外一种生成题目的方法
 * \param qustion 问题
 * \param option 选项
 * \param answer 回答
 * \param scorce 分数
 */
Topic::Topic(const std::string qustion, const std::string& option
	, const std::string& answer, double scorce)
{
	mQuestion = qustion;
	mOption = option;
	mAnswer = answer;
	mScore = scorce;
	mNumber = mTopicNumber++;
}

/**
 * \brief 反馈问题
 * \return 问题
 */
std::string Topic::getQuestion() const
{
	return mQuestion;
}

/**
 * \brief 反馈标准答案
 * \return 标准答案
 */
std::string Topic::getAnswer() const
{
	return mAnswer;
}
/**
 * 获得回答选项的list
 * @param optionLine 得到的所有回答，用separator_ans 分割
 * @return 回答的set
 */

std::set<std::string> Topic::getOption(const std::string &optionLine) const
{
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
Topic::Topic(const Topic &rhs) :mQuestion(rhs.mQuestion),mOption(rhs.mOption)
        ,mAnswer(rhs.mAnswer),mNumber(rhs.mNumber),mScore(rhs.mScore)
{

}

/**
 * 移动构造函数
 * @param rhs
 */
Topic::Topic(Topic &&rhs)noexcept:mQuestion(std::move(rhs.mQuestion))
        ,mOption(std::move(rhs.mOption)),mAnswer(std::move(rhs.mAnswer))
        ,mNumber(std::move(rhs.mNumber)),mScore(std::move(rhs.mScore)) {

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
    mScore = rhs.mScore;
    return *this;
}

/**
 * 移动赋值运算符
 * @param rhs
 * @return
 */
Topic &Topic::operator=(Topic &&rhs) noexcept{
    mQuestion = std::move(rhs.mQuestion);
    mAnswer = std::move(rhs.mAnswer);
    mNumber = std::move(rhs.mNumber);
    mOption = std::move(rhs.mOption);
    mScore = std::move(rhs.mScore);
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
    return lhs.mNumber < rhs.mNumber;
}

/*std::set<size_t> Topic::getAnswer(std::string &optionLine) {
    return std::set<size_t>();
}*/

/**
 * 打印题目 选项
 * @param os  ostream
 * @return
 */
std::ostream &Topic::print(std::ostream &os) const{
    os << mQuestion << std::endl;
    char num = 'A';
	for (auto opt : mOption) {
		os << num++ << "."
			<< &opt << "\t";
	}
    return os;
}

/**
 * 打印答案
 * @param os  ostream
 * @return
 */
/*std::ostream &Topic::print_Ans(std::ostream &os) const {
    os << mAnswer;
    return os;
}*/

std::ostream &operator<<(std::ostream &os, const Topic &rhs) {
    rhs.print(os);
    return os;
}


SingleTopic::~SingleTopic() {

}

/*
 * 写多了，压根不需要virtual这个 = =!
std::set<std::string> SingleTopic::getOption(std::string &optionLine) {

}
*/

// ReSharper disable once CppDoxygenUnresolvedReference
/**
 * 单选题获取正确答案的函数
 * @param option Line
 * @return
 */
/*std::set<size_t> SingleTopic::getAnswer(std::string &optionLine) {
    std::set<size_t> result;
    char temp = optionLine[0];
    if (temp != '\0' && temp >= 65 && temp <= 97) {
        result.insert(static_cast<unsigned long &&>(temp - 65));
    }
}*/

/**
 * 直接调用基类的构造函数呢
 * @param line
 */
SingleTopic::SingleTopic(const std::string& line) : Topic(line){}

SingleTopic::SingleTopic(const std::string qustion, const std::string& option
	, const std::string& answer, double scorce):Topic(qustion,option,answer,scorce)
{}


MultiTopic::~MultiTopic() {}


// ReSharper disable once CppDoxygenUnresolvedReference
/**
 * 判断题获取正确答案的函数
 * @param optionLine 获取到的答案
 * @return 答案的set
 */
/*std::set<size_t> MultiTopic::getAnswer(std::string &optionLine) {
    std::set<size_t > result;
    for (char temp: optionLine) {
        if (temp != '\0' && temp >= 65 && temp <= 97) {
            result.insert(static_cast<unsigned long &&>(temp - 65));
        }
        else
            throw std::out_of_range("答案必须在26个字母里选择诶！");
    }
    return result;
}*/

MultiTopic::MultiTopic(const std::string &line) : Topic(line){

}

MultiTopic::MultiTopic(const std::string qustion, const std::string& option
	, const std::string& answer, double scorce):Topic(qustion, option, answer, scorce)
{
}

BoolTopic::~BoolTopic() {}

// ReSharper disable once CppDoxygenUnresolvedReference
/**
 * 多选题获取正确答案的函数
 * @param optionLine 获取到的答案
 * @return 答案的set
 */
/*std::set<size_t> BoolTopic::getAnswer(std::string &optionLine) {
    std::set<size_t > result;
    char temp = optionLine[0];
    if(temp == 'y' || temp == 'Y')
        result.insert(1);
    else if(temp == 'X' || temp == 'x')
        result.insert(0);
    else
        throw std::out_of_range("判断题答案必须为X，Y");
    return result;

}*/

BoolTopic::BoolTopic(const std::string &line) : Topic(line)
{
	
}

BoolTopic::BoolTopic(const std::string qustion, const std::string& option
	, const std::string& answer, double scorce) : Topic(qustion, option, answer, scorce)
{
	
}


/**
 * 打印服务
 */
std::ostream &BoolTopic::print(std::ostream &os) const {
    os << getQuestion() << std::endl;
    return os;
}

/**
 * 添加题目
 * @param line 从文件中读取的行
 * @return 成功或者失败的bool
 */
bool Topics::addTopic(const std::string &line) {
	
	mTopic.push_back(std::make_shared<Topic>(line));
	return true;
}

/**
 * destruct function
 */
Topics::~Topics() 
{

}

/**
 * 打印整张试卷，可是感觉就是测试用
 * @param os ostream
 * @return os ostream
 */
std::ostream &Topics::print(std::ostream & os) {
    for (auto topic : mTopic) {
        os << topic->getNumber() << " ";
        topic->print(os);
        std::cout << std::endl;
    }
	return os;
}

/**
 * 打印题目（题号）
 * @param os
 * @param num 题号
 * @return os
 */
std::ostream &Topics::print_number(std::ostream &os, size_t num) 
{
    if (num <= mTopic.size() || num >= 1)
        mTopic[num - 1]->print(os);
    else
        throw std::out_of_range("错误的题号");
    return os;
}

bool Topics::returnToSql()
{
	MYSQL m_sqlCon;
	try
	{
		mysql_init(&m_sqlCon);
		if (!mysql_real_connect(&m_sqlCon, "local", "root", "tcsw930605"
			, "test_system", 3306, nullptr, 0))
		{
			std::cout << "数据库链接失败" << std::endl;
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

/**
 * 删除题目
 * @param num 题号
 * @return 是否成功
 */
bool Topics::deleteTopic(const size_t & num) {
    if (num <= mTopic.size() || num >= 1) {
        auto iter = mTopic.begin();
        iter += num - 1;
        mTopic.erase(iter);
    }
    else{
        return false;
    }
	return true;
}

/**
 * \brief 修改题目
 * \param num 题号
 * \param topic 题目的指针
 * \return 成功与否
 */
bool Topics::modifyTopic(const size_t&num, Topic* topic)
{
	if (num <= mTopic.size() || num >= 1) {
		auto iter = mTopic.begin();
		iter += num - 1;
		**iter = *topic;
	}
	else
	{
		return false;
	}
	return true;
}

/**
 * \brief 得到分数
 * \return 分数
 */
double Topics::getScore() const
{
	return mScore;
}

double Topics::calculate_score()
{
	double scorce = 0.0;
	for(int i = 0; i!= mTopic.size(); i++)
	{
		if (mTopic[i]->getAnswer() == mAnswer[i])
			scorce += mTopic[i]->getScorce();
	}
	return scorce;
}

void Topics::copy_this(const Topics& rhs)
{
	mName = rhs.mName;
	mID = rhs.mID;
	mStudent = rhs.mStudent;
	mTopic = rhs.mTopic;
	mAnswer = rhs.mAnswer;
	mScore = rhs.mScore;
}




Topics::Topics(const std::string &name) :mName(name)
{

}

Topics::Topics(const Topics& rhs) 
{
	copy_this(rhs);
}

Topics::Topics(Topics&&rhs) noexcept
{
	mName = std::move(rhs.mName);
	mID = std::move(rhs.mID);
	mStudent = std::move(rhs.mStudent);
	mTopic = std::move(rhs.mTopic);
	mAnswer = std::move(rhs.mAnswer);
	mScore = std::move(rhs.mScore);
}

Topics& Topics::operator==(const Topics&rhs)
{
	copy_this(rhs);
	return *this;
}

Topics& Topics::operator==(Topics&&	rhs) noexcept
{
	mName = std::move(rhs.mName);
	mID = std::move(rhs.mID);
	mStudent = std::move(rhs.mStudent);
	mTopic = std::move(rhs.mTopic);
	mAnswer = std::move(rhs.mAnswer);
	mScore = std::move(rhs.mScore);
	return *this;
}