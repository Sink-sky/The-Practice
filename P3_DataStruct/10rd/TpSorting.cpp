#include<bits/stdc++.h>
using namespace std;

int a[7][7] = {{0,1,1,0,0,0,0},
               {0,0,0,1,1,0,0},
               {0,0,0,0,0,1,1},
               {0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0}};

int num = 7;
int has[1000];

bool isok(){
    for (int i = 0; i < num;++i){
        if(!has[i])
            return false;
    }
    return true;
}

int SearchNext(){
    for (int i = 0; i < num;++i){
        if(!has[i]){
            int flag = 1;
            for (int j = 0; j < num;++j){
                if(a[j][i]&&!has[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                has[i] = 1;
                return i;
            }
        }
    }
    return -1;
}


int main(void){
    while(1){
        int s = SearchNext();
        if(s==-1){
            cout << "Can't OK" << endl;
            break;
        }
        else
            cout << "Do " << char(s+'A') << endl;
        if(isok())
            break;
    }
    return 0;
}