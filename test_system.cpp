// test_system.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Topic_lib.h"


MYSQL m_sqlCon;
int main(int argc, char ** argv )
{
	mysql_init(&m_sqlCon);
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root", "tcsw930605"
		, "test_system", 3306, nullptr, 0))
	{
		return false;
	}
	return true;
}

