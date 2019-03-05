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
    //获取子节点
    BitNode & GetLNode() const;
    BitNode & GetRNode() const;
    //设置子节点
    void SetLNode(BitNode & BN);
    void SetRNode(BitNode & BN);
    //判断子节点为空
    bool EmptyLNode() const;
    bool EmptyRNode() const;
    //获取节点内容
    T && GetNode() const;
    //设置节点内容
    void SetNode(const T & data);

    //---------------------------------------这是一条概念的分界线

    //输出当前树高度
    int HighTree() const;
    //先序遍历
    void DLRTree() const;
    //中序遍历
    void LDRTree() const;
    //后序遍历
    void LRDTree() const;
};

//由于节点中保存了节点之间的关系,实际上每一个节点就代表了一个BitTree
//尽量的想将树和节点概念区分开,却发现这样带来的只是繁重的语法
//比如树就像是节点的包装
//于是不如将两者写在一起,通过类型名帮助用户区分概念

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

//发现一个小问题,这棵树的每个节点都是用户new出来的,所以需要用户一个个去delete
//为了用户能够直接操作节点,这也是没办法的选择
//解决方法是创建树类去包装一层,树类中用户无法操作节点(保证每个节点都是new出来的)
//解决方案带来的弊端是需要再写一个解析树结构的构造函数
//构造时会比较抽象
//可以考虑以此重构再写一个 emmm.....
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
