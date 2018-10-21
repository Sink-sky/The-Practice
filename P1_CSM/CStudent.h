//做一个学生信息管理系统的中间层次，提升可阅读性、可扩展性
#pragma once
#include"MyString.h"

class CStudent{
	private:
		MyString name;
		MyString id;
		int grade;
		//根据需要还可扩充学生信息
	public:
		CStudent();
		//默认构造函数
		CStudent(const MyString &name,const MyString &id,const int grade);
		//有参构造函数
		CStudent(const CStudent &CStu);
		//复制构造函数
		~ CStudent();
		//析构函数
		inline MyString & get_name(){
			return this->name;
		};
		inline MyString & get_id(){
			return this->id;
		};
		inline int & get_grade(){
			return this->grade;
		};
		//获取相对应属性的引用
		CStudent & operator = (const CStudent & CStu);
		//重载赋值运算符（深拷贝）
};