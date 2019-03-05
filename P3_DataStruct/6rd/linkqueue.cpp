#include<iostream>
using namespace std;

class Error{
    private:
    string s;
    public:
    Error(string s):s(s){
        cout << this->s << " Error" << endl;
    }
};

template<typename T>
class LinkQueue
{
    typedef struct LQ_node{
        T data;
        LQ_node *next;
    } *LQ_ptr;

  private:
    LQ_ptr head;
    LQ_ptr rear;

  public:
    LinkQueue();
    ~LinkQueue();
    void push(const T &data);
    T pop();
    T &get()const;
    template <typename Ty>
    friend ostream &operator<<(ostream &out, const LinkQueue<Ty> &LQ);
};

template<typename T>
LinkQueue<T>::LinkQueue()
{
    this->head = this->rear = new LQ_node;
    this->head->next = nullptr;
}

template<typename T>
LinkQueue<T>::~LinkQueue()
{
    LQ_ptr p = this->head;
    while(p != this->rear){
        LQ_ptr op = p;
        p = p->next;
        delete op;
    }
    delete this->rear;
    this->head = this->rear = nullptr;
}

template<typename T>
void LinkQueue<T>::push(const T &data){
    LQ_ptr p = new LQ_node;
    p->data = T(data);
    p->next = this->rear;
    if(this->head == this->rear){
        this->head = p;
        return;
    }
    LQ_ptr p0 = this->head;
    while(p0->next != this->rear)
        p0 = p0->next;
    p0->next = p;
}

template<typename T>
T LinkQueue<T>::pop(){
    if(this->head == this->rear)
        return T();
    T data = move(this->head->data);
    LQ_ptr p = this->head;
    this->head = this->head->next;
    delete p;
    return data;
}

template<typename T>
T & LinkQueue<T>::get() const{
    if(this->head == this->rear)
        throw Error("EmptyQueue");
    return this->head->data;
}

template<typename T>
ostream & operator << (ostream & out,const LinkQueue<T> & LQ){
    for (auto i = LQ.head; i != LQ.rear;i = i->next){
        out << i->data << "\t";
    }
    return out;
}


//test
// #define _TEST 0
#ifdef _TEST
int main(void){
    LinkQueue<int> A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.pop();
    cout << A << endl;
    return 0;
}
#endif