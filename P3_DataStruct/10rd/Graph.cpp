#include<bits/stdc++.h>
using namespace std;
//"ABCDEFG"
int a[7][7] = {{0,1,1,0,0,0,0},
               {1,0,0,1,1,0,0},
               {1,0,0,0,0,1,1},
               {0,1,0,0,0,0,0},
               {0,1,0,0,0,0,0},
               {0,0,1,0,0,0,0},
               {0,0,1,0,0,0,0}};
int had[1000]={};
int n = 7;
void dfs(int i){
    if(had[i])
        return;
    had[i] = 1;
    cout << char('A' + i) << " ";
    for (int j = 0; j < n;++j)
        if(a[i][j])
            dfs(j);
}

void bfs(int i){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        had[f] = 1;
        cout << char('A'+f) << " ";
        for (int j = 0; j < n;++j)
            if(!had[j]&&a[f][j])
                q.push(j);
    }
}

int main(void){
    cout << "DFS ";
    dfs(0);
    cout << endl;
    memset(had, 0, sizeof(had));
    cout << "BFS ";
    bfs(0);
    cout << endl;
    return 0;
}