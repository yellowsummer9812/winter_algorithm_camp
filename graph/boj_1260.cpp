#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
int check[1001];
vector<int> vtx[1001];
void dfs(int x){
    check[x] = 1;
    cout<< x<< " ";
    for(int n : vtx[x]){
        if(check[n]) continue;
        dfs(n); 
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    check[x] = 1;

    while(q.size()){
        int tmp = q.front();
        cout<< tmp<< " ";
        q.pop();
        for(int nxt : vtx[tmp]){
            if(check[nxt]) continue;
            q.push(nxt);
            check[nxt] = 1;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m>> v;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin>> a>> b;
        vtx[a].push_back(b);
        vtx[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(vtx[i].begin(), vtx[i].end());
    }
    

    dfs(v);
    for(int i = 1; i <= n; i++){
        check[i] = 0;
    }
    cout<< '\n';
    bfs(v);
}