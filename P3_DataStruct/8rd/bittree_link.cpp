#include<iostream>
using namespace std;

template<typename T>
class BitNode
{
  private:
    T data;
    BitNode *Lchild, *Rchild;

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
    T && GetNode() const;
    //���ýڵ�����
    void SetNode(const T & data);

    //---------------------------------------����һ������ķֽ���

    //�����ǰ���߶�
    int HighTree() const;
    //�������
    void DLRTree() const;
    //�������
    void LDRTree() const;
    //�������
    void LRDTree() const;
};

//���ڽڵ��б����˽ڵ�֮��Ĺ�ϵ,ʵ����ÿһ���ڵ�ʹ�����һ��BitTree
//�������뽫���ͽڵ�������ֿ�,ȴ��������������ֻ�Ƿ��ص��﷨
//�����������ǽڵ�İ�װ
//���ǲ��罫����д��һ��,ͨ�������������û����ָ���

template <typename T>
using BitTree = BitNode<T>;

template <typename T>
BitNode<T>::BitNode(){
    this->data = T();
    this->Lchild = nullptr;
    this->Rchild = nullptr;
}

template <typename T>
BitNode<T>::BitNode(const T & data){
    this->data = T(data);
    this->Lchild = nullptr;
    this->Rchild = nullptr;
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
    if(this->Lchild)
        return false;
    return true;
}

template <typename T>
bool BitNode<T>::EmptyRNode() const{
    if(this->Rchild)
        return false;
    return true;
}

template <typename T>
T && BitNode<T>::GetNode() const{
    return T(this->data);
}

template <typename T>
void BitNode<T>::SetNode(const T & data){
    this->data = data;
}

template <typename T>
int BitNode<T>::HighTree() const{
    int RH = 0, LH = 0;
    if(!this->EmptyLNode())
        LH = (this->GetLNode()).HighTree();
    if(!this->EmptyRNode())
        RH = (this->GetRNode()).HighTree();
    return RH > LH ? RH : LH + 1;
}

template <typename T>
void BitNode<T>::DLRTree() const{
    cout << this->data << " ";
    if(!this->EmptyLNode())
        (this->GetLNode()).DLRTree();
    if(!this->EmptyRNode())
        (this->GetRNode()).DLRTree();
}

template <typename T>
void BitNode<T>::LDRTree() const{
    if(!this->EmptyLNode())
        (this->GetLNode()).LDRTree();
    cout << this->data << " ";
    if(!this->EmptyRNode())
        (this->GetRNode()).LDRTree();
}

template <typename T>
void BitNode<T>::LRDTree() const{
    if(!this->EmptyLNode())
        (this->GetLNode()).LRDTree();
    if(!this->EmptyRNode())
        (this->GetRNode()).LRDTree();
    cout << this->data << " ";
}

#define _TEST 0
#ifdef _TEST
int main(void){
    BitTree<char> A('A');
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
    cout << "High: " << A.HighTree() << endl;
    cout << "DLR: " << endl;
    A.DLRTree();
    cout << endl;
    cout << "LDR: " << endl;
    A.LDRTree();
    cout << endl;
    cout << "LRD: " << endl;
    A.LRDTree();
    cout << endl;
    return 0;
}
#endif
