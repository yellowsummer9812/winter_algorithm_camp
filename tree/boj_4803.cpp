#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];
bool check[501];

int t;

void bfs(int k){
    queue<pair<int, int>> q;
    check[k] = true;
    q.push({0, k});

    while(!q.empty()){
        int parent = q.front().first;
        int cur = q.front().second; 
        q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            if(check[v[cur][i]]){
                if(v[cur][i] == parent){
                    continue;
                }
                else{
                    t--;
                    return;
                }
            }
            q.push({cur, v[cur][i]});
            check[v[cur][i]] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    int tc = 0;
    while(++tc){
        cin>> n>> m;
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= 500; i++){
            v[i].erase(v[i].begin(), v[i].end());
            check[i] = false;
        }
        t = 0;

        for(int i = 0; i < m; i++){
            int a, b;
            cin>> a>> b;
           v[a].push_back(b);
           v[b].push_back(a);
        }
        
        int e = 0;
        while(e == 0){
            int i;
            for(i = 1; i <= n; i++){
                if(check[i]) continue;
                t++;
                bfs(i);
                break;
            }
            if(n < i){
                e = 1;
            }
        }
        if(t == 0){
            cout<<"Case "<< tc<< ": No trees.\n";
        }else if(t == 1){
            cout<<"Case "<< tc<< ": There is one tree.\n";
        }else{
            cout<<"Case "<< tc<< ": A forest of "<< t<<" trees.\n";
        }
    }
}
