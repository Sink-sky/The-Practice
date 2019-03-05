#include<bits/stdc++.h>
#define MANX 1000
using namespace std;


//特意做成了树结构
int a[7][7] = {{11,5,5,11,11,11,11},
               {5,11,11,5,5,11,11},
               {5,11,11,11,11,5,5},
               {11,5,11,11,11,11,11},
               {11,5,11,11,11,11,11},
               {11,11,5,11,11,11,11},
               {11,11,5,11,11,11,11}};

int np[MANX];
pair<int,int> nv[MANX];

int num = 7;

bool isok(){
    for (int i = 0; i < num;++i)
        if(!np[i])
            return false;
    return true;
}

pair<int,int> SearchV(){
    int mini, minj, min = 0x3fffffff;
    for (int i = 0; i < num;++i){
        if(np[i]){
            for (int j = 0; j < num;++j){
                if(!np[j]&&a[i][j]<min){
                    min = a[i][j];
                    mini = i;
                    minj = j;
                }
            }
        }
    }
    np[minj] = 1;
    return make_pair(mini,minj);
}

int main(void){
    //0~6随意一个点
    np[0] = 1;
    int vnum = 0;
    while(!isok()){
        pair<int, int> v = SearchV();
        nv[vnum] = v;
        ++vnum;
    }
    for (int i = 0; i < vnum;++i)
        cout << char('A' + nv[i].first) << " link " << char('A' + nv[i].second) << endl;
        return 0;
}