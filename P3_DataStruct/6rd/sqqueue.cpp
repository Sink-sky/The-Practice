#include <iostream>
using namespace std;

class Error{
    private:
    string s;
    public:
    Error(string s):s(s){
        cout << this->s << " Error" << endl;
    }
};

template <typename T>
class SqQueue
{
  private:
    T *base;
    int front;
    int rear;
    int len;
    int size;

    void sizeplus();

  public:
    SqQueue();
    ~SqQueue();
    void push(const T &data);
    T pop();
    T &get()const;
    template<typename Ty>
    friend ostream & operator <<(ostream &out, const SqQueue<Ty> &SQ);
};

template<typename T>
SqQueue<T>::SqQueue(){
    this->base = new T[2];
    this->front = 0;
    this->rear = 0;
    this->len = 0;
    this->size = 2;
}

template<typename T>
SqQueue<T>::~SqQueue(){
    delete[] this->base;
    this->size = -1;
    this->len = -1;
}

template<typename T>
void SqQueue<T>::sizeplus(){
    if((this->rear+1) % this->size == this->front){
        int newsize = this->size << 1;
        T *p = new T[newsize];
        int j = 0;
        for (int i = this->front; i != this->rear;++i,++j,i%=this->size){
            *(p + j) = *(this->base + i);
        }
        this->size = newsize;
        this->front = 0;
        this->rear = j;
        delete[] this->base;
        this->base = p;
    }
}

template<typename T>
void SqQueue<T>::push(const T &data){
    this->sizeplus();
    *(this->base + this->rear) = data;
    this->rear = (this->rear + 1) % this->size;
    ++this->len;
}

template<typename T>
T SqQueue<T>::pop(){
    if(!this->len)
        return T();
    T data = T(*(this->base + this->front));
    this->front = (this->front + 1) % this->size;
    --this->len;
    return data;
}

template<typename T>
T & SqQueue<T>::get()const{
    if(!this->len)
        throw Error("EmptyQueue");
    return *(this->base + this->front);
}

template<typename T>
ostream & operator <<(ostream & out,const SqQueue<T> & SQ){
    for (int i = SQ.front; i != SQ.rear;++i,i%=SQ.size)
        out << *(SQ.base + i) << "\t";
    return out;
}

#define _TEST 0
#ifdef _TEST
int main(void)
{
    SqQueue<int> A;
    for (int i = 0; i < 100;++i)
        A.push(i);
    for (int i = 0; i < 33;++i)
        A.pop();
    cout << A;
    return 0;
}
#endif