#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class BitTree
{
    //1号节点是根节点
  private:
    int size;
    T *data;
    int *has;
    void sizeplus(int needsize);

  public:
    BitTree();
    BitTree(int len, const T *data);
    ~BitTree();
    //设置i节点内容
    void Set(const int i,const T & data);
    //获取i节点内容
    T & Get(const int i) const;
    T & GetL(const int i) const;
    T & GetR(const int i) const;
    //获取i子节点位置
    static int GetLNode(const int i);
    static int GetRNode(const int i);
    //判断i子节点为空
    bool EmptyLNode(const int i) const;
    bool EmptyRNode(const int i) const;

    //---------------------------------------(。???)ノ这也是一条概念的分界线

    //输出当前树高度
    int HighTree() const;
    //先序遍历
    void DLRTree() const;
    //中序遍历
    void LDRTree() const;
    //后序遍历
    void LRDTree() const;
};

template<typename T>
void BitTree<T>::sizeplus(int needsize){
    if(this->size > needsize)
        return;
    int s = this->size;
    while(s < needsize)
        s <<= 1;
    T *ndata = new T[s];
    int *nhas = new int[s]();
    for (int i = 1; i < this->size;++i){
        *(ndata + i) = *(this->data + i);
        *(nhas + i) = *(this->has + i);
    }
    delete[] this->data;
    delete[] this->has;
    this->size = s;
    this->data = ndata;
    this->has = nhas;
}

template<typename T>
BitTree<T>::BitTree(){
    this->size = 4;
    this->data = new T[4];
    this->has = new int[4]();
}

template<typename T>
BitTree<T>::BitTree(int len, const T *data){
    this->size = 4;
    this->data = new T[4];
    this->has = new int[4]();
    this->sizeplus(3*len);
    for (int i = 1; i < len + 1;++i){
        *(this->data + i) = *(data + i - 1);
        *(this->has + i) = 1;
    }
    cout << this->data + 1 << endl;
}

template<typename T>
BitTree<T>::~BitTree(){
    this->size = -1;
    delete[] this->data;
    delete[] this->has;
}

template<typename T>
void BitTree<T>::Set(const int i,const T & data){
    this->sizeplus(3 * i);
    *(this->data + i) = T(data);
    *(this->has + i) = 1;
}

template<typename T>
T & BitTree<T>::Get(const int i) const{
    return *(this->data + i);
}

template<typename T>
T & BitTree<T>::GetL(const int i) const{
    return *(this->data + 2 * i);
}

template<typename T>
T & BitTree<T>::GetR(const int i) const{
    return *(this->data + 2 * i + 1);
}

template<typename T>
int BitTree<T>::GetLNode(const int i){
    return 2 * i;
}

template<typename T>
int BitTree<T>::GetRNode(const int i){
    return 2 * i + 1;
}

template<typename T>
bool BitTree<T>::EmptyLNode(const int i) const{
    return !*(this->has + 2 * i);
}

template<typename T>
bool BitTree<T>::EmptyRNode(const int i) const{
    return !*(this->has + 2 * i + 1);
}

template<typename T>
int BitTree<T>::HighTree() const{
    if(!*(this->has+1))
        return 0;
    stack<int> s;
    s.push(1);
    int last = 0;
    int h = 1;
    int max = 1;
    while(!s.empty()){
        if(h>max)
            max = h;
        int i = s.top();
        int hl = !this->EmptyLNode(i);
        int hr = !this->EmptyRNode(i);
        int l = 0, r = 0;
        if(hl)
            l = this->GetLNode(i);
        if(hr)
            r = this->GetRNode(i);
        int fl = hl && (l != last && hr && r != last);
        int fr = hr && r != last;
        last = i;
        if(fl){
            s.push(l);
            ++h;
        }
        else if(fr){
            s.push(r);
            ++h;
        }
        else{
            s.pop();
            --h;
        }
    }
    return max;
}

template<typename T>
void BitTree<T>::DLRTree() const{
    if(!*(this->has+1))
        return;
    stack<int> s;
    s.push(1);
    int last = 0;
    while(!s.empty()){
        int i = s.top();
        int hl = !this->EmptyLNode(i);
        int hr = !this->EmptyRNode(i);
        int l = 0, r = 0;
        if(hl)
            l = this->GetLNode(i);
        if(hr)
            r = this->GetRNode(i);
        int fl = hl && (l != last && hr && r != last);
        int fr = hr && r != last;
        if(!((hl&&l==last)||(hr&&r==last)))
            cout << this->Get(i) << " ";
        last = i;
        if(fl){
            s.push(l);
        }
        else if(fr){
            s.push(r);
        }
        else{
            s.pop();
        }
    }
}

template<typename T>
void BitTree<T>::LDRTree() const{
    if(!*(this->has+1))
        return;
    stack<int> s;
    s.push(1);
    int last = 0;
    while(!s.empty()){
        int i = s.top();
        int hl = !this->EmptyLNode(i);
        int hr = !this->EmptyRNode(i);
        int l = 0, r = 0;
        if(hl)
            l = this->GetLNode(i);
        if(hr)
            r = this->GetRNode(i);
        int fl = hl && (l != last && hr && r != last);
        int fr = hr && r != last;
        int n = !((hl && l == last) || (hr && r == last));
        if(hl&&l==last)
            cout << this->Get(i) << " ";
        last = i;
        if(fl){
            s.push(l);
        }
        else if(fr){
            s.push(r);
        }
        else{
            s.pop();
            if(n)
                cout << this->Get(i) << " ";
        }
    }
}

template<typename T>
void BitTree<T>::LRDTree() const{
    if(!*(this->has+1))
        return;
    stack<int> s;
    s.push(1);
    int last = 0;
    while(!s.empty()){
        int i = s.top();
        int hl = !this->EmptyLNode(i);
        int hr = !this->EmptyRNode(i);
        int l = 0, r = 0;
        if(hl)
            l = this->GetLNode(i);
        if(hr)
            r = this->GetRNode(i);
        int fl = hl && (l != last && hr && r != last);
        int fr = hr && r != last;
        int n = !((hl && l == last) || (hr && r == last));
        if(hr&&r==last)
            cout << this->Get(i) << " ";
        last = i;
        if(fl){
            s.push(l);
        }
        else if(fr){
            s.push(r);
        }
        else{
            s.pop();
            if(n)
                cout << this->Get(i) << " ";
        }
    }
}

//test
#define _TEST 0
#ifdef _TEST
int main(void){
    string s = "ABCDEFG";
    const char *p = s.c_str();
    int l = 7;
    BitTree<char> A(l, p);
    cout << A.HighTree() << endl;
    A.DLRTree();
    cout << endl;
    A.LDRTree();
    cout << endl;
    A.LRDTree();
    cout << endl;
    return 0;
}

#endif