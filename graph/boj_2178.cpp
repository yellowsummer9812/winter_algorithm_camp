#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 102
using namespace std;

int n, m;
char p[MAX][MAX];
int check[MAX][MAX];
const int r[4] = {-1, 0, 1, 0};
const int c[4] = {0, -1, 0, 1};
int ans = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>> p[i][j];
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({ans, {1, 1}});
    check[1][1] = 1;

    while(!q.empty()){
        ans = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        if(x == n && y == m) break;
        q.pop();
        for(int i = 0; i < 4; i++){
            int z = x + r[i];
            int w = y + c[i];
            if(z < 1 || w < 1 || n < z || m < w) continue;
            if(check[z][w]) continue;
            if(p[z][w] == '0') continue;
            q.push({ans + 1, {z, w}});
            check[z][w] = 1;
        }
    }
    cout<< ans;
}