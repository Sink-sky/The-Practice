#include <iostream>
using namespace std;

template <typename T>
class LinkStack
{
    typedef struct LS_node
    {
        T data;
        LS_node *next;
    } * LS_head, *LS_ptr;

  private:
    LS_head head;

  public:
    LinkStack()
    {
        this->head = nullptr;
    }
    ~LinkStack()
    {
        LS_ptr p = this->head;
        this->head = nullptr;
        while (p != nullptr)
        {
            LS_ptr op = p;
            p = p->next;
            delete op;
        }
    }
    void PushStack(const T &data)
    {
        LS_ptr p = new LS_node;
        p->data = T(data);
        p->next = this->head;
        this->head = p;
    }
    T PopStack()
    {
        if (!this->head)
            return T();
        LS_ptr p = this->head;
        this->head = this->head->next;
        T s = T(p->data);
        delete p;
        return s;
    }
};

int main(void)
{
    int n;
    cin >> n;
    if (!n)
        cout << n;
    LinkStack<char> LS;
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