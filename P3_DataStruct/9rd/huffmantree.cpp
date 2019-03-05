#include<iostream>
#include<algorithm>
using namespace std;

class HuffmanNode{
    public:
      char data;
      int value;
      HuffmanNode *Lchild, *Rchild;
      HuffmanNode(){
          this->Rchild = nullptr;
          this->Lchild = nullptr;
      }
      HuffmanNode(int value){
          this->value = value;
          this->Rchild = nullptr;
          this->Lchild = nullptr;
      }
      HuffmanNode(const char & data,int value){
          this->data = data;
          this->value = value;
          this->Rchild = nullptr;
          this->Lchild = nullptr;
      }

      HuffmanNode operator +(const HuffmanNode & HN) const{
          return HuffmanNode(this->value + HN.value);
      }


      bool operator < (const HuffmanNode & HN){
          return this->value < HN.value;
      }
      
};
typedef HuffmanNode *HN_ptr;


bool comp(HN_ptr p1,HN_ptr p2){
    return *p1 < *p2;
}

HN_ptr HuffmanTree(int len,HN_ptr p){
    HN_ptr plist[len];
    for (int i = 0; i < len;++i)
        plist[i] = p + i;
    for (int i = 0; i < len - 1;++i){
        sort(plist + i, plist + len, comp);
        HN_ptr np = new HuffmanNode(plist[i]->value+plist[i+1]->value);
        np->Lchild = plist[i];
        np->Rchild = plist[i + 1];
        plist[i + 1] = np;
    }
    return plist[len - 1];
}

void dg(HN_ptr p,int i){
    static char l[1000];
    if(!p->Lchild&&!p->Rchild){
        l[i] = 0;
        cout << p->data << ":" << l << endl;
        return;
    }
    if(p->Lchild){
        l[i] = '0';
        dg(p->Lchild,i+1);
    }
    if(p->Rchild){
        l[i] = '1';
        dg(p->Rchild,i+1);
    }
}

int main(void){
    HuffmanNode HN_list[10];
    for (int i = 0; i < 5;++i)
        HN_list[i] = HuffmanNode('A' + i, i);
    HN_ptr head =  HuffmanTree(5, HN_list);
    dg(head, 0);
    return 0;
}