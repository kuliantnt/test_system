#pragma once
/*!
 * \file getTopic.h
 * \date 2017/09/05 10:12
 *
 * \author ����tnt
 * Contact: user@company.com
 *
 * \brief �ļ��Ļ�ȡ�Լ�sql������
 *
 * TODO: long description
 *
 * \note
*/

#include "stdafx.h"
#include "Topic_lib.h"

using const_str_ref = const std::string&;

//************************************
// Method:    get_topics
// FullName:  get_topics
// Access:    public 
// Returns:   Topics
// Qualifier:
// Parameter: const_str_ref _source_file �ļ���
// Parameter: const_str_ref name �Ծ�����
//************************************
Topics get_topics(const_str_ref _source_file, const_str_ref name);



//************************************
// Method:    connect_mysql
// FullName:  connect_mysql
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: const_str_ref server_address
// Parameter: const_str_ref user_name
// Parameter: const_str_ref passwd
// Parameter: const_str_ref db
// Parameter: int port
//************************************
bool connect_mysql(const_str_ref server_address,const_str_ref user_name
	,const_str_ref passwd,const_str_ref db, unsigned int port);