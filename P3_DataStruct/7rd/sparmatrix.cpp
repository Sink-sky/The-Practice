#include<iostream>
using namespace std;

struct Matrix{
    int r,c;
    int *data;
};

class SparMatrix
{
private:
  int r, c, n;
  int *row, *col, *num;

public:
    SparMatrix();
    SparMatrix(const Matrix & M);
    ~SparMatrix();
    void T();
    friend ostream &operator<<(ostream &out, const SparMatrix &SM);
};

SparMatrix::SparMatrix()
{
    this->r = this->c = this->n = 1;
    this->row = new int[1];
    this->col = new int[1];
    this->num = new int[1];
    *this->row = *this->col = *this->num = 1;
}

SparMatrix::SparMatrix(const Matrix & M){
    for (int i = 0; i < M.r * M.c;++i)
        if(*(M.data+i))
            ++this->n;
    this->row = new int[this->n];
    this->col = new int[this->n];
    this->num = new int[this->n];
    this->r = M.r;
    this->c = M.c;
    int l = 0;
    for (int i = 0; i < M.r;++i){
        for (int j = 0; j < M.c;++j){
            if(*(M.data + i * M.c + j)){
                num[l] = *(M.data + i * M.c + j);
                row[l] = i;
                col[l] = j;
                ++l;
            }
        }
    }
}

SparMatrix::~SparMatrix()
{
    this->r = this->c = this->n = 0;
    delete[] this->row;
    delete[] this->col;
    delete[] this->num;
}

void SparMatrix::T(){
    int tmp = this->r;
    this->r = this->c;
    this->c = tmp;
    int *tmpp = this->row;
    this->row = this->col;
    this->col = tmpp;
}

ostream &operator<<(ostream &out, const SparMatrix &SM){
    for (int i = 0; i < SM.r;++i){
        for (int j = 0; j < SM.c;++j){
            int flag = 1;
            for (int k = 0; k < SM.n;++k){
                if(*(SM.row+k) == i && *(SM.col+k) == j){
                    out << *(SM.num + k) << " ";
                    flag = 0;
                }
            }
            if(flag)
                out << 0 << " ";
        }
        out << endl;
    }
    return out;
}

// #define _TEST 0
#ifdef _TEST
int main(void){
    Matrix A;
    A.r = 3;
    A.c = 3;
    for (int i = 0; i < 9;++i)
        *(A.data + i) = i;
    SparMatrix B(A);
    cout << "Begin:" << endl;
    cout << B;
    B.T();
    cout << "After:" << endl;
    cout << B;
    return 0;
}
#endif