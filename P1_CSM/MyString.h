#pragma once
#include<iostream>
using namespace std;

class MyString{
	private:
		static int num;
		//字符串对象数目
		int size;
		//字符串大小 
		int maxsize;
		//分配空间大小 
		char *str;
		//字符串数据 
		
		void incre_size(int needsize);
		//调整分配空间大小 
	public:
		MyString();
		//默认构造函数
		MyString(int n,char c);
		//构造由n个c组成的MyString 
		MyString(const char *cstr);
		//从C类型字符串构造MyString 
		MyString(const MyString &mystr); 
		//复制构造函数（深拷贝）
		MyString(MyString &&mystr);
		//移动构造函数 
		~MyString();
		//析构函数
		inline char * get_string(){
			return str;
		};
		//返回字符串（浅拷贝）
		static inline int get_num(){
			return num;
		};
		//返回创建对象数目
		void get_string(int n,char *rec) const;
		//将前n个字符以C类型字符串的形式放入rec中 
		void set_string(const char *cstr);
		//返回C类型字符串的MyString 
		inline int get_length() const{
			return size;
		};
		//返回MyString的size 
		MyString & append(const MyString &mystr);
		MyString & append(const char *cstr);
		//在末尾追加C类型字符串或MyString 
		bool operator < (const MyString &mystr) const;
		//重载小于运算符(按标准序排序)
		bool operator == (const MyString &mystr) const;
		//重载等号运算符 
		MyString & operator = (const MyString &mystr);
		//重载赋值运算符 
		friend ostream & operator << (ostream &os,const MyString &mystr);
		//重载流输出运算符 
};
