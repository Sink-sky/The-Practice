#include <iostream>
using namespace std;
#define INITSIZE 2

template <typename T>
class DanamicList
{

  private:
    int len;
    int size;
    T *data;
    //�����С����
    void sizeplus(int needsize)
    {
        int size = this->size;
        while (size <= needsize)
            size <<= 1;
        T *p = this->data;
        this->data = new T[size];
        for (int i = 0; i < this->len; ++i)
            *(this->data + i) = *(p + i);
        delete[] p;
        this->size = size;
    }

  public:
    //�޲ι��캯��
    DanamicList()
    {
        this->len = 0;
        this->size = INITSIZE;
        this->data = new T[INITSIZE];
    }
    //���ƹ��캯��
    DanamicList(const DanamicList &DL)
    {
        this->len = DL.len;
        this->size = DL.size;
        this->data = new T[this->size];
        for (int i = 0; i < this->len; ++i)
            *(this->data + i) = *(DL.data + i);
    }
    //�ƶ����캯��
    DanamicList(DanamicList &&DL)
    {
        this->len = DL.len;
        this->size = DL.size;
        this->data = DL.data;
        DL.data = new T[INITSIZE];
    }
    //��������
    ~DanamicList()
    {
        this->len = -1;
        this->size = -1;
        delete[] this->data;
    }
    //ͷ���뺯��
    void push(const T &data)
    {
        if (this->len >= this->size)
            sizeplus(this->size + 1);
        for (int i = this->len; i >= 1; --i)
            *(this->data + i) = *(this->data + i - 1);
        ++this->len;
        *(this->data) = T(data);
    }
    //���뺯��
    void insert(int i, const T &data)
    {
        if (i > this->len)
            return;
        if (this->len >= this->size)
            sizeplus(this->size + 1);
        for (int j = this->len - 1; j >= i; --j)
            *(this->data + j + 1) = *(this->data + j);
        *(this->data + i) = T(data);
        ++this->len;
    }
    //ͷ��������
    T &pop()
    {
        if (this->len == 0)
            return -1;
        --this->len;
        T data = *(this->data);
        for (int i = 0; i < this->len; ++i)
            *(this->data + i) = *(this->data + i + 1);
        return data;
    }
    //β��������
    T &&rpop()
    {
        if (this->len == 0)
            return -1;
        --this->len;
        return T(*(this->data + this->len));
    }
    //ɾ������
    T &clear(int i)
    {
        T data = *(this->data + i);
        --this->len;
        for (int j = i; j < this->len; ++j)
            *(this->data + j) = *(this->data + j + 1);
        return data;
    }
    //��ѯ����
    T &get(int i) const
    {
        return *(this->data + i);
    }
    int find(int i, const T &data) const
    {
        for (int j = i; j < this->data; ++j)
            if (*(this->data + j) == data)
                return j;
        return this->len;
    }
    //�����ĺϲ�
    DanamicList &meger(const DanamicList &A, bool (*comp)(const T &, const T &))
    {
        int j = 0;
        int l = this->len + A.len;
        for (int i = 0; i < l; ++i)
        {
            if (j == A.len)
                break;
            if (!((*comp)(*(this->data + i), *(A.data + j))))
            {
                this->insert(i, *(A.data + j));
                ++j;
            }
        }
        return *this;
    }

    //��������������
    friend ostream &operator<<(ostream &out, const DanamicList &DL)
    {
        for (int i = 0; i < DL.len; ++i)
            out << *(DL.data + i) << "\t";
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
    DanamicList<int> A, B;
    A.push(1);
    A.push(3);
    A.push(5);
    B.push(2);
    B.push(4);
    cout << A << endl;
    cout << B << endl;
    cout << A.meger(B, comp);
}
#endif
