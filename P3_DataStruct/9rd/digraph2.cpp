#include <iostream>
using namespace std;
#define MAXN 1000

//写成类,用虚构函数来实现每个ArcNode自动释放new VexNode
struct ArcNode
{
    char data;
    int weight;
    ArcNode *Next;
};

struct VexNode
{
    char data;
    ArcNode *Next;
};

class DiGraph
{
  public:
    int num;
    VexNode Point[MAXN];

    DiGraph()
    {
        this->num = 0;
    }
    ~DiGraph()
    {
        return;
    }
    void AddVexNode(char data)
    {
        this->Point[this->num].data = data;
        this->Point[this->num].Next = nullptr;
        ++this->num;
    }
    void AddArcNode(char data1,char data2,int weight){
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < this->num;++i){
            if(this->Point[i].data == data1)
                pos1 = i;
            if(this->Point[i].data == data2)
                pos2 = i;
        }
        if(pos1==-1||pos2==-1)
            return;
        ArcNode ** pre = &(this->Point[pos1].Next);
        while((*pre)){
            pre = &((*pre)->Next);
        }
        (*pre) = new ArcNode;
        (*pre)->data = data2;
        (*pre)->weight = weight;
        (*pre)->Next = nullptr;
    }
    void Print(int i){
        if(i >= this->num)
            return;
        cout << this->Point[i].data << ":";
        ArcNode *p = this->Point[i].Next;
        while(p){
            cout << p->data << " ";
            p = p->Next;
        }
        cout << endl;
    }
};

int main(void)
{
    DiGraph DG;
    DG.AddVexNode('A');
    DG.AddVexNode('B');
    DG.AddVexNode('C');
    DG.AddArcNode('A', 'B', 1);
    DG.AddArcNode('B', 'C', 1);
    DG.AddArcNode('C', 'A', 1);
    DG.Print(0);
    DG.Print(1);
    DG.Print(2);
    return 0;
}