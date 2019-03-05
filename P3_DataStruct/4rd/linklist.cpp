#include <iostream>
using namespace std;

template <typename T>
class LinkList
{

    typedef struct LL_node
    {
        T data;
        LL_node *next;
    } * LL_ptr, *LL_head;

  private:
    LL_head head;
    //��ȡ��n���ڵ�
    LL_ptr get(const int n)
    {
        int l = n;
        LL_ptr p = this->head;
        while (l-- && p != nullptr)
            p = p->next;
        return p;
    }

  public:
    //Ĭ�Ϲ��캯��
    LinkList()
    {
        this->head = nullptr;
    }
    //���ƹ��캯��
    LinkList(const LinkList &LL)
    {
        LL_ptr *p1 = &(this->head);
        LL_ptr p2 = LL.head;
        while (p2 != nullptr)
        {
            *p1 = new LL_node;
            (*p1)->data = p2->data;
            p1 = &((*p1)->next);
            p2 = p2->next;
        }
        *p1 = nullptr;
    }
    //�ƶ����캯��
    LinkList(LinkList &&LL)
    {
        this->head = LL->head;
        LL->head = nullptr;
    }
    ~LinkList(){
        LL_ptr p = this->head;
        this->head = nullptr;
        while(p){
            LL_ptr op = p;
            p = p->next;
            delete op;
        }
        
    }
    //��ͷ����
    void frontpush(const T &data)
    {
        LL_ptr p = new LL_node;
        p->data = data;
        p->next = this->head;
        this->head = p;
    }
    //iλ�ò���
    void insert(const int i, const T &data)
    {
        int l = i;
        LL_ptr *p = &(this->head);
        while (l-- && *p != nullptr)
        {
            p = &((*p)->next);
        }
        if (l == -1)
        {
            LL_ptr p0 = *p;
            *p = new LL_node;
            (*p)->data = data;
            (*p)->next = p0;
        }
    }
    //��ͷɾ��
    void frontpop()
    {
        LL_ptr p = this->head;
        if (!p)
            return;
        this->head = (this->head)->next;
        delete p;
    }
    //��βɾ��
    void endpop()
    {
        LL_ptr *p = &(this->head);
        while ((*p)->next != nullptr)
        {
            p = &((*p)->next);
        }
        delete *p;
        *p = nullptr;
    }
    //iλ��ɾ��
    void clear(const int i)
    {
        LL_ptr p = this->get(i);
        if (!p)
            return;
        LL_ptr op = p;
        p = p->next;
        delete op;
    }
    //��ѯ
    T &getdata(const int i) const
    {
        LL_ptr p = this->get(i);
        if (!p)
            return T();
        return p->data;
    }

    int find(const T &data) const
    {
        LL_ptr p = this->head;
        int i = 0;
        while (p && p->data != data)
        {
            p = p->next;
            ++i;
        }
        if (p)
            return i;
        else
            return -1;
    }
    //��������ϲ�
    LinkList &meger(const LinkList &LL, bool (*comp)(const T &, const T &))
    {
        LL_ptr *p1 = &(this->head);
        LL_ptr p2 = LL.head;
        while (*p1 != nullptr && p2 != nullptr)
        {
            if (!(*comp)((*p1)->data, p2->data))
            {
                LL_ptr p = new LL_node;
                p->data = p2->data;
                p->next = *p1;
                *p1 = p;
                p2 = p2->next;
            }
            p1 = &((*p1)->next);
            // cout << *this << endl;
        }
        while (p2 != nullptr)
        {
            *p1 = new LL_node;
            (*p1)->data = p2->data;
            (*p1)->next = nullptr;
            p1 = &((*p1)->next);
            p2 = p2->next;
        }
        return *this;
    }
    //��������������
    friend ostream &operator<<(ostream &out, const LinkList &LL)
    {
        LL_ptr p = LL.head;
        while (p != nullptr)
        {
            out << p->data << "\t";
            p = p->next;
        }
        return out;
    }
};

//test
// #define _TEST 0
#ifdef _TEST
bool comp(const int &a, const int &b)
{
    return a > b;
}
int main(void)
{
    LinkList<int> A;
    LinkList<int> B;
    A.frontpush(1);
    A.frontpush(3);
    A.frontpush(5);
    B.frontpush(2);
    B.frontpush(4);
    A.insert(3, 0);
    B.meger(A, comp);
    cout << A << endl;
    cout << B << endl;
    return 0;
}
#endif
