//https://github.com/Sink-sky/The-Practice
#include<iostream>
using namespace std;

class MyString{
	private:
		static int num;
		//�ַ���������Ŀ
		int size;
		//�ַ�����С 
		int maxsize;
		//����ռ��С 
		char *str;
		//�ַ������� 
		
		void incre_size(int needsize);
		//��������ռ��С 
	public:
		MyString();
		//Ĭ�Ϲ��캯��
		MyString(int n,char c);
		//������n��c��ɵ�MyString 
		MyString(const char *cstr);
		//��C�����ַ�������MyString 
		MyString(const MyString &mystr); 
		//���ƹ��캯���������
		MyString(MyString &&mystr);
		//�ƶ����캯�� 
		~MyString();
		//��������
		inline char * get_string(){
			return str;
		};
		//�����ַ�����ǳ������
		static inline int get_num(){
			return num;
		};
		//���ش���������Ŀ
		void get_string(int n,char *rec) const;
		//��ǰn���ַ���C�����ַ�������ʽ����rec�� 
		void set_string(const char *cstr);
		//����C�����ַ�����MyString 
		inline int get_length() const{
			return size;
		};
		//����MyString��size 
		MyString & append(const MyString &mystr);
		MyString & append(const char *cstr);
		//��ĩβ׷��C�����ַ�����MyString 
		bool operator < (const MyString &mystr) const;
		//����С�������(����׼������)
		bool operator == (const MyString &mystr) const;
		//���صȺ������ 
		MyString & operator = (const MyString &mystr);
		//���ظ�ֵ����� 
		friend ostream & operator << (ostream &os,const MyString &mystr);
		//�������������� 
};
