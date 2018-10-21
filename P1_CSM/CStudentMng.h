//每个CS学生管理系统是一个链表
//为了处理方便，每个链表后面都加上了一个空节点，因此会有额外的MyString被默认构造

#pragma once
#include"CStudent.h"
#define _my_inf 0x3fffffff

typedef struct CSM_node{
    CStudent cstu;
    CSM_node *next; 
} *CSM_ptr,*CSM_head;
//提高可阅读性做的类型定义

class CStudentMng{
    private:
        int size;
        CSM_head LL_head;
        //由链表大小和一个头指针构成
    public:
        CStudentMng();
        //默认构造函数
        CStudentMng(const CStudentMng &CSM);
        //复制构造函数
        ~CStudentMng();
        //析构函数
        void show_cstu_info(const MyString &id);
        //根据id查询学生信息
        void show_cstu_info(const int grade_begin = -_my_inf,const int grade_end = _my_inf);
        //根据成绩区间查询学生信息，无参默认全部，一参查询==，两参查询区间
        CStudent & get_info(const MyString &id);
        //返回引用学生信息
        void push_cstu(const CStudent &cstu);
        //添加学生信息
        void pop_cstu();
        //删除学生信息
        inline int get_size(){
            return size;
        };
        //返回链表学生数目
};