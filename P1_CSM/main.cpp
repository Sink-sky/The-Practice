#include"CStudentMng.h"
#include"CStudent.h"
#include"MyString.h"
#include<iostream>
using namespace std;
int main(void){
    MyString a("HHY"),b("666666"),c("DALAO"),d("999999"),e("xuezha"),f("111111");
    CStudent hhy(a,b,66),dalao(c,d,99),xuezha(e,f,11);
    //学生信息建立
    CStudentMng jwc;
    jwc.push_cstu(hhy);jwc.push_cstu(dalao);jwc.push_cstu(xuezha);
    //学生信息管理系统建立
    cout << "------------------------" << endl;
    cout << jwc.get_size() << " CStudent in the CSM" << endl;
    cout << "------------------------" << endl;
    jwc.show_cstu_info(b);
    cout << "------------------------" << endl;
    jwc.show_cstu_info();
    cout << "------------------------" << endl;
    jwc.show_cstu_info(99);
    cout << "------------------------" << endl;
    jwc.show_cstu_info(11,66);
    //测试显示学生信息
    cout << "------------------------" << endl;
	jwc.get_info(d).get_grade() = 100;
    jwc.show_cstu_info();
    //测试修改学生信息
    cout << "------------------------" << endl;
    jwc.pop_cstu();
    jwc.show_cstu_info();
    //测试删除学生信息
    cout << "------------------------" << endl;
    cout << a.get_num() << " MyString was construct" << endl;
    //测试MyString静态成员变量
    cout << "------------------------" << endl;
    return 0;
}

//1.自创建类型无法进行隐式类型转换
//2.CStudent的有参构造函数的这种写法可以避免先调用默认构造函数再赋值
//3.含有可能存在潜在错误的函数不适合返回值，因为一旦出错，极可能返回什么都有问题
//4.深拷贝浅拷贝返回引用、指针、还是副本等问题值得考虑
//5.inline函数最好在头文件中实现