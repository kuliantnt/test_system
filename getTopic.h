#pragma once
/*!
 * \file getTopic.h
 * \date 2017/09/05 10:27
 *
 * \author 哭脸tnt
 * Contact: user@company.com
 *
 * \brief 用于获取文件以及sql对象的函数
 *
 * TODO: long description
 *
 * \note
*/
#include "stdafx.h"
#include "Topic_lib.h"
using cnt_str_ref = const std::string&;


//************************************
// Method:    get_topics
// FullName:  get_topics
// Access:    public 
// Returns:   Topics
// Qualifier:
// Parameter: cnt_str_ref _source_file
// Parameter: cnt_str_ref name
//************************************
Topics get_topics(cnt_str_ref _source_file, cnt_str_ref name);


//************************************
// Method:    connect_to_mysql
// FullName:  connect_to_mysql
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: MYSQL & m_sql_con
// Parameter: cnt_str_ref host
// Parameter: cnt_str_ref name
// Parameter: cnt_str_ref passwd
// Parameter: cnt_str_ref db
// Parameter: unsigned int port
//************************************
bool connect_to_mysql(MYSQL &m_sql_con,cnt_str_ref host, cnt_str_ref name, cnt_str_ref passwd
	, cnt_str_ref db, unsigned int port);


//************************************
// Method:    create_table
// FullName:  create_table
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: cnt_str_ref ID
// Parameter: cnt_str_ref NAME
//************************************
bool create_table(MYSQL &m_sql_con, cnt_str_ref ID, cnt_str_ref NAME);


//************************************
// Method:    insert_topic_to_sql
// FullName:  insert_topic_to_sql
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: MYSQL & m_sql_con
// Parameter: const Topics & topic
//************************************
bool insert_topic_to_sql(MYSQL &m_sql_con, const Topics& topics);