#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
int v[1000][1000];
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};
int ans;
queue<pair<int, int>> q;

bool f(){ // 안 익은 게 있는지 확인
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> m>> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int tmp;
            cin>> tmp;
            v[i][j] = tmp;
            if(tmp == 1){
                q.push({i, j});
            }
        }
    }

    if(f()){
        while(!q.empty()){
            queue<pair<int, int>> tmp;
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();

                for(int i = 0; i < 4; i++){
                    int a = cur.first - x[i];
                    int b = cur.second - y[i];
                    if(v[a][b] != 0) continue;
                    if(a < 0 || b < 0 || n - 1 < a|| m - 1 < b) continue;
                    tmp.push({a, b});
                    v[a][b] = 1;
                }
            }
            ans++;
            while(!tmp.empty()){
                q.push(tmp.front()); tmp.pop();
            }
        }
    }else{
        cout<< ans;
        return 0;
    }
    if(f()){
        cout<< -1;
    }else{
        cout<< ans - 1;
    }
}