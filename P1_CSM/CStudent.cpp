#include"CStudent.h"

CStudent::CStudent(){
	grade = 0;
}

CStudent::CStudent(const MyString &name,const MyString &id,const int grade):name(name),id(id),grade(grade){
}

CStudent::CStudent(const CStudent &CStu){
	this->name = CStu.name;
	this->id = CStu.id;
	this->grade = CStu.grade;
}

CStudent::~CStudent(){

}

CStudent & CStudent::operator = (const CStudent & CStu){
	name = CStu.name;
	id = CStu.id;
	grade = CStu.grade;
	return *this;
}