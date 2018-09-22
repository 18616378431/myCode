1.首先你得将MySQL安装上
  apt-get install mysql-server
 (mysql -uroot -p 登陆测试)

2.安装链接库
  apt-get install libmysqlclient-dev

3.进行数据库的创建,例如:
  create table t1(a int, name varchar(10));
  insert into t1 values(1,"Jack");
  insert into t1 values(2,"Smith");
  insert into t1 values(3,"Bruce");

4.进行C语言代码的编写
#include <stdio.h>
#include <stdlib.h>

#include "mysql.h"

int main()
{
	MYSQL m_conn;
	int ret;

	mysql_init(&m_conn);
	if(mysql_real_connect(&m_conn, "localhost","root","******","Jack",0,NULL,0))
	{
		//insert
		printf("connect mysql successful");
		ret = mysql_query(&m_conn, "insert into t1 values(10,'Tony')");
		if(!res)
		{
			printf("insert %lu rows\n",(unsigned long)mysql_affected_rows(&m_conn));
		}
		else
		{
			printf("insert error\n");
		}

		//delete
		char* deleteData = "delete from t1 where a=3";
		res = mysql_real_query(&m_conn, deleteData,(unsigned int)strlen(deleteData));
		if(!res)
		{
			printf("delete successful");
		}
		else
		{
			printf("delete error\n");
		}

		//show all data
		MYSQL_ROW row;
		MYSQL_RES *res;
		int t;
		char *allData = "select * from t1";
		res = mysql_real_query(&m_conn, allData, (unsigned int)strlen(allData));

		res = mysql_store_result(&m_conn); //
		while(row=mysql_fetch_row(res))
		{
			for(t=0; t<mysql_num_fields(res); t++)
			{
				printf("%s\t",row[t]);
			}
			printf("\n");
		}
		mysql_close(&m_conn);
	}
   return 0;
}


4.编译时注意加上链接库啥的
 gcc -I/usr/include/mysql mysqlTest.c -L/usr/lib/mysql -lmysqlclient -o mysqlTest
 ./mysqlTest