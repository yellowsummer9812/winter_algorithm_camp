#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int ans;
vector<int> v[101];
queue<int> q;
int check[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin>> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>> a>> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    check[1] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : v[cur]){
            if(check[nxt]) continue;
            q.push(nxt);
            check[nxt] = 1;
            ans++;
        }
    }
    cout<< ans;
}