#include <iostream>
using namespace std;

template <typename T>
class ListStack
{
  private:
    T *p;
    int size;
    T *LS;
    void sizeplus(int needsize)
    {
        int size = this->size;
        if (size > needsize)
            return;
        while (size <= needsize)
            size <<= 1;
        int l = this->p - this->LS;
        T *p = this->LS;
        this->LS = new T[size];
        for (int i = 0; i < l; ++i)
            *(this->LS + i) = *(p + i);
        delete[] p;
        this->size = size;
        this->p = this->LS + l;
    }

  public:
    ListStack()
    {
        this->LS = new T[2];
        size = 2;
        this->p = LS;
    }
    ~ListStack()
    {
        this->p = nullptr;
        this->size = -1;
        delete[] this->LS;
        this->LS = nullptr;
    }
    void PushStack(const T &data)
    {
        this->sizeplus(this->p - this->LS + 1);
        *(this->p) = T(data);
        ++(this->p);
    }
    T PopStack()
    {
        if (this->p == this->LS)
            return T();
        --(this->p);
        return T(*(this->p));
    }
};

int main(void)
{
    int n;
    cin >> n;
    if (!n)
        cout << n;
    ListStack<char> LS;
    while (n)
    {
        LS.PushStack(n % 2 + '0');
        n /= 2;
    }
    char s;
    while (s = LS.PopStack())
    {
        cout << s;
    }
    return 0;
}