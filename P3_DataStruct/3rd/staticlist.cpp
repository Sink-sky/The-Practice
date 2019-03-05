#include <iostream>
using namespace std;
#define MAXN 1000

template <typename T>
class StaticList
{

  private:
    int len;
    T *data;

  public:
    StaticList()
    {
        this->len = 0;
        this->data = new T[MAXN];
    }
    StaticList(const StaticList &SL)
    {
        this->len = SL->len;
        this->data = new T[MAXN];
        for (int i = 0; i < this->len; ++i)
            *(this->data + i) = *(SL->data + i);
    }
    StaticList(StaticList &&SL)
    {
        this->len = SL->len;
        this->data = SL->data;
        SL->data = new T[MAXN];
    }
    ~StaticList()
    {
        this->len = -1;
        delete[] this->data;
    }
    int push(const T &data)
    {
        if (this->len >= MAXN)
            return -1;
        *(this->data + this->len) = T(data);
        return len++;
    }
    int pop()
    {
        if (this->len == 0)
            return -1;
        return --len;
    }
    friend ostream &operator<<(ostream &out, const StaticList &SL)
    {
        for (int i = 0; i < SL.len; ++i)
            out << *(SL.data + i) << "\t";
        return out;
    }
};
//test
// #define _TEST 0;

#ifdef _TEST
int main(void)
{
    StaticList<int> SL;
    SL.push(1);
    SL.push(2);
    SL.push(3);
    cout << SL << endl;
    SL.pop();
    cout << SL << endl;
    return 0;
}
#endif