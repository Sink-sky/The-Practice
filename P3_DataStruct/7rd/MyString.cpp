#include"MyString.h"

int MyString::num = 0;

void MyString::incre_size(int needsize){
	while(maxsize <= needsize)
		maxsize <<= 2;
	char *old_str = str;
	str = new char[maxsize]();
	for(int i = 0;i <= size;++i)
		str[i] = old_str[i];
	delete [] old_str;
}

MyString::MyString(){
	++num;
	size = 0;
	maxsize = 2;
	str = new char[maxsize]();
	cout << "MyString类的默认构造函数被调用" << endl;
}

MyString::MyString(int n,char c){
	++num;
	size = 0;
	maxsize = 2;
	str = new char[maxsize]();
	incre_size(n);
	for(int i = 0;i < n;++i)
		str[i] = c;
	size = n;
}

MyString::MyString(const char *cstr){
	++num;
	size = 0;
	maxsize = 2;
	str = new char[maxsize]();
	int l = 0;
	for(const char *p = cstr;p[l];++l);
	incre_size(l);
	size = l;
	for(;l >= 0;--l)
		str[l] = cstr[l];
	cout << "MyString类的有参构造函数被调用，当前字符串为：" << str << endl;
}

MyString::MyString(const MyString &mystr){
	++num;
	size = mystr.size;
	maxsize = mystr.maxsize;
	str = new char[maxsize]();
	for(int i = 0;i < size;++i)
		str[i] = mystr.str[i];
	cout << "MyString类的复制构造函数被调用，当前字符串为：" << str << endl;
}

MyString::MyString(MyString &&mystr){
	size = mystr.size;
	maxsize = mystr.maxsize;
	str = mystr.str;
	mystr.str = nullptr;
}
 
MyString::~MyString(){
	--num;
	cout << "MyString类的析构函数被调用，当前字符串为：" << str << endl;
	if(str != nullptr){
		delete [] str;
		str = nullptr;
	}
}

void MyString::get_string(int n,char *rec) const{
	for(int i = 0;i < n;++i)
		rec[i] = str[i];
	rec[n] = '\0';
}

void MyString::set_string(const char *cstr){
	int l = 0;
	while(cstr[l])
		++l;
	incre_size(l);
	size = l;
	for(int i = 0;i < l;++i)
		str[i] = cstr[i];
}

MyString & MyString::append(const MyString &mystr){
	if(mystr.size + size >= maxsize)
		incre_size(mystr.size + size); 
	for(int i = 0;i < mystr.size;++i)
		str[i+size] = mystr.str[i];
	size += mystr.size;
	return *this; 
}


MyString & MyString::append(const char *cstr){
	int l = 0;
	while(cstr[l])
		++l;
	if(l + size >= maxsize)
		incre_size(l + size);
	for(int i = 0;i < l;++i)
		str[i+size] = cstr[i];
	size += l;
	return *this;
}

bool MyString::operator < (const MyString &mystr) const{
	if(size != mystr.size)
		return size < mystr.size;
	else
		for(int i = 0;i < size;++i)
			if(str[i] != mystr.str[i])
				return str[i] < mystr.str[i];
	return false;
}

bool MyString::operator == (const MyString &mystr) const{
	if(size != mystr.size)
		return false;
	else
		for(int i = 0;i <size;++i)
			if(str[i] != mystr.str[i])
				return false;
	return true;
}

MyString & MyString::operator = (const MyString &mystr){
	incre_size(mystr.size);
	size = mystr.size;
	for(int i = 0;i <= size;++i)
		str[i] = mystr.str[i];
	cout << "MyString类的赋值运算符被调用，当前字符串为：" << str << endl;
	return *this;
}

ostream & operator << (ostream &os,const MyString &mystr){
	os << mystr.str;
	return os;
}

// #define _TEST 0
#ifdef _TEST
#include<iostream>
#include"MyString.h"
using namespace std;
int main()
{
   MyString str;
   str.set_string("I love C++, ");
   cout << "字符串长度：" << str.get_length() << "\t" << str.get_string() << endl;
   str.append("yeah!");
   cout << "字符串长度：" << str.get_length() << "\t" << str.get_string() << endl;
   {
       MyString str("I like C++ programming!");
       MyString str2(str), str3 = str;
   }
   MyString str2;
   cout << str.get_string() << endl;
   str2 = str;
   str2.append(str2);
   cout << str2.get_string() << endl;
   return 0;
}
#endif