//id:线索二叉树
//Error:莓办法,尽力了
//debug hold不住了
//存在问题
//线索化失败(指针乱飞)
//无法解决问题
//求解决方案

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
    T GetNode() const;
    //设置节点内容
    void SetNode(const T & data);
    //---------------------------------------建立之后
    BitNode &FirstNode();
    BitNode &PostNode();

    //---------------------------------------这是一条概念的分界线

    //初始化中序线索树
    void ThreadLDRTree();
};

//由于节点中保存了节点之间的关系,实际上每一个节点就代表了一个BitTree
//尽量的想将树和节点概念区分开,却发现这样带来的只是繁重的语法
//比如树就像是节点的包装
//于是不如将两者写在一起,通过类型名帮助用户区分概念

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