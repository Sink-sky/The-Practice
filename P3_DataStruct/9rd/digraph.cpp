#include<iostream>
using namespace std;

class DiGraph
{
    public:
      int point;
      bool *mat;
    DiGraph(int n){
        this->point = n;
        this->mat = new bool[n*n]();
    }
    ~DiGraph(){
        delete[] this->mat;
    }
    bool get(int i,int j){
        return *(this->mat + i * this->point + j);
    }
    void GraphList(int i){
        cout << i+1 << " Can GOTO: ";
        for (int j = 0; j < this->point;++j)
            if(get(i,j))
                cout << j+1 << " ";
        cout << endl;
        for (int j = 0; j < this->point;++j)
            if(get(j,i))
                cout << j+1 << " ";
        cout << "Can GOTO: " << i+1 << endl;
    }
};
int main(void){
    DiGraph A(3);
    bool data[] = {0,1,0,0,0,1,1,0,0};
    A.mat = data;
    cout << " 1  ---*  2 " << endl;
    cout << "  *      |  " << endl;
    cout << "   |    |   " << endl;
    cout << "    |  *    " << endl;
    cout << "     3      " << endl;
    cout << 1 << endl;
    A.GraphList(0);
    cout << 2 << endl;
    A.GraphList(1);
    cout << 3 << endl;
    A.GraphList(2);
}