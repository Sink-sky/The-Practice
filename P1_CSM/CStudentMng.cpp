#include"CStudentMng.h"
#define _my_inf 0x3fffffff

CStudentMng::CStudentMng(){
    size = 0;
    LL_head = new CSM_node;
    LL_head->next = nullptr;
}

CStudentMng::CStudentMng(const CStudentMng &CSM){
    size = CSM.size;
    CSM_ptr p = CSM.LL_head;
    LL_head = new CSM_node;
    CSM_ptr p2 = LL_head;
    while(p->next != nullptr){
        p2->cstu = p->cstu;
        p2->next = new CSM_node;
        p = p->next;
        p2 = p2->next;
    }
    p2->next = nullptr;
}

CStudentMng::~CStudentMng(){
    size = 0;
    CSM_ptr p = LL_head; 
    LL_head = nullptr;
    while(p->next != nullptr){
        CSM_ptr oldp = p;
        p = p->next;
        delete oldp;
    }
    delete p;
}

void CStudentMng::show_cstu_info(const MyString &id){
    CSM_ptr p = LL_head;
    while(p != nullptr){
        if(p->cstu.get_id() == id){
            cout << p->cstu.get_id() << "\t" << p->cstu.get_name() << "\t" << p->cstu.get_grade() << endl;
            return;
        }
        p = p->next;
    }
    cout << "No result." << endl;
}

void CStudentMng::show_cstu_info(const int grade_begin,const int grade_end){
    int left = grade_begin,right = grade_end;
    if(grade_begin != -_my_inf && grade_end ==_my_inf)
        right = left;
    CSM_ptr p = LL_head;
    int flag = 1;
    while(p->next != nullptr){
        if(p->cstu.get_grade() >= left && p->cstu.get_grade() <= right){
            flag = 0;
            cout << p->cstu.get_id() << "\t" << p->cstu.get_name() << "\t" << p->cstu.get_grade() << endl;
        }
        p = p->next;
    }
    if(flag)
        cout << "No result." << endl;
}

CStudent & CStudentMng::get_info(const MyString &id){
    CSM_ptr p = LL_head;
    while(p != nullptr){
        if(p->cstu.get_id() == id){
            return p->cstu;
        }
        p = p->next;
    }
    cout << "No result." << endl;
    static CStudent bad_return;
    return bad_return;
}

void CStudentMng::push_cstu(const CStudent &cstu){
    CSM_ptr p = new CSM_node;
    p->cstu = cstu;
    p->next = LL_head;
    LL_head = p;
    ++size;
}

void CStudentMng::pop_cstu(){
    if(!size)
        return ;
    CSM_ptr p = LL_head;
    LL_head = LL_head->next;
    delete p;
    --size;
}