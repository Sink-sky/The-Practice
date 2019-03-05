//id:����������
//Error:ݮ�취,������
//debug hold��ס��
//��������
//������ʧ��(ָ���ҷ�)
//�޷��������
//��������

#include<iostream>
using namespace std;

template<typename T>
class BitNode
{
  private:
    T data;
    BitNode *Lchild, *Rchild;
    bool ltag, rtag;

  public:
    BitNode();
    BitNode(const T & data);
    ~BitNode();
    //��ȡ�ӽڵ�
    BitNode & GetLNode() const;
    BitNode & GetRNode() const;
    //�����ӽڵ�
    void SetLNode(BitNode & BN);
    void SetRNode(BitNode & BN);
    //�ж��ӽڵ�Ϊ��
    bool EmptyLNode() const;
    bool EmptyRNode() const;
    //��ȡ�ڵ�����
    T GetNode() const;
    //���ýڵ�����
    void SetNode(const T & data);
    //---------------------------------------����֮��
    BitNode &FirstNode();
    BitNode &PostNode();

    //---------------------------------------����һ������ķֽ���

    //��ʼ������������
    void ThreadLDRTree();
};

//���ڽڵ��б����˽ڵ�֮��Ĺ�ϵ,ʵ����ÿһ���ڵ�ʹ�����һ��BitTree
//�������뽫���ͽڵ�������ֿ�,ȴ��������������ֻ�Ƿ��ص��﷨
//�����������ǽڵ�İ�װ
//���ǲ��罫����д��һ��,ͨ�������������û����ָ���

template <typename T>
using Threadtree = BitNode<T>;

template <typename T>
BitNode<T>::BitNode(){
    this->data = T();
    this->Lchild = nullptr;
    this->Rchild = nullptr;
    this->ltag = false;
    this->rtag = false;
}

template <typename T>
BitNode<T>::BitNode(const T & data){
    this->data = T(data);
    this->Lchild = nullptr;
    this->Rchild = nullptr;
    this->ltag = false;
    this->rtag = false;
}

//����һ��С����,�������ÿ���ڵ㶼���û�new������,������Ҫ�û�һ����ȥdelete
//Ϊ���û��ܹ�ֱ�Ӳ����ڵ�,��Ҳ��û�취��ѡ��
//��������Ǵ�������ȥ��װһ��,�������û��޷������ڵ�(��֤ÿ���ڵ㶼��new������)
//������������ı׶�����Ҫ��дһ���������ṹ�Ĺ��캯��
//����ʱ��Ƚϳ���
//���Կ����Դ��ع���дһ�� emmm.....
template <typename T>
BitNode<T>::~BitNode(){
    return ;
}

template <typename T>
BitNode<T> & BitNode<T>::GetLNode() const{
    return *(this->Lchild);
}

template <typename T>
BitNode<T> & BitNode<T>::GetRNode() const{
    return *(this->Rchild);
}

template <typename T>
void BitNode<T>::SetLNode(BitNode<T> & BN){
    this->Lchild = &(BN);
}

template <typename T>
void BitNode<T>::SetRNode(BitNode<T> & BN){
    this->Rchild = &(BN);
}

template <typename T>
bool BitNode<T>::EmptyLNode() const{
    if(this->Lchild&&!this->ltag)
        return false;
    return true;
}

template <typename T>
bool BitNode<T>::EmptyRNode() const{
    if(this->Rchild&&!this->rtag)
        return false;
    return true;
}

template <typename T>
T BitNode<T>::GetNode() const{
    return this->data;
}

template <typename T>
void BitNode<T>::SetNode(const T & data){
    this->data = data;
}

template <typename T>
BitNode<T> &BitNode<T>::FirstNode(){
    BitNode *p = this;
    while(p->ltag==0){
        p = p->Lchild;
    }
    return *p;
}

template <typename T>
BitNode<T> &BitNode<T>::PostNode(){
    BitNode *p = this->Rchild;
    if(!this->rtag)
        while(!p->ltag)
            p = p->Lchild;
    return *p;
}

template <typename T>
void BitNode<T>::ThreadLDRTree(){
    static BitNode *pre;
    if(this->Lchild){
        (this->GetLNode()).ThreadLDRTree();
    }
    if(!this->Lchild){
        this->Lchild = pre;
        this->ltag = true;
    }
    if(!this->Rchild)
        this->rtag = true;
    if(pre->rtag)
        pre->Rchild = this;
    pre = this;
    if(!this->EmptyRNode())
        (this->GetRNode()).ThreadLDRTree();
}

#define _TEST 0
#ifdef _TEST
int main(void){
    Threadtree<char> A('A');
    BitNode<char> B('B'), C('C'), D('D'), E('E'), F('F'), G('G');
    A.SetLNode(B);
    A.SetRNode(C);
    B.SetLNode(D);
    B.SetRNode(E);
    C.SetLNode(F);
    C.SetRNode(G);
    cout << "Tree:" << endl;
    cout << "        A        " << endl;
    cout << "    |       |    " << endl;
    cout << "    B       C    " << endl;
    cout << "  |   |   |   |  " << endl;
    cout << "  D   E   F   G  " << endl;
    cout << endl;
    cout << "LDR: " << endl;
    A.ThreadLDRTree();
    // cout << D.GetLNode().GetNode() << endl;
    // cout << D.GetRNode().GetNode() << endl;
    cout << E.GetLNode().GetNode() << endl;
    cout << E.GetRNode().GetNode() << endl;
    // BitNode<char> *p = &(A.FirstNode());
    // cout << D.GetRNode().GetNode() << " ";
    // while(1){
    //     cout << p->GetNode() << " ";
    //     p = &(p->PostNode());
    // }
    cout << endl;
    return 0;
}
#endif
//D B E A F C G