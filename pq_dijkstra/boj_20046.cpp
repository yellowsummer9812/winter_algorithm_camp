#include <iostream>
#include <queue>
#define MAX 1001
#define INF 1e9
using namespace std;

int n, m;
int road[MAX][MAX];
int cost[MAX][MAX];
int check[MAX][MAX];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> m>> n;
    int x;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>> x;
            road[i][j] = x;
            cost[i][j] = INF;
        }
    }

    if(road[1][1] == -1){
        cout<< -1;
        return 0;
    }

    cost[1][1] = road[1][1];
    pq.push({cost[1][1], {1, 1}});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int i = cur.second.first;
        int j = cur.second.second;

        if(check[i][j]) continue;

        check[i][j] = 1;
        
        // 위
        if(1 < i && !check[i - 1][j] && road[i - 1][j] != -1){
            if(cur.first + road[i - 1][j] <= cost[i - 1][j]){
                cost[i - 1][j] = cur.first + road[i - 1][j];
                pq.push({cost[i - 1][j], {i - 1, j}});
            }
        }
        // 아래
        if(i < m && !check[i + 1][j] && road[i + 1][j] != -1){
            if(cur.first + road[i + 1][j] <= cost[i + 1][j]){
                cost[i + 1][j] = cur.first + road[i + 1][j];
                pq.push({cost[i + 1][j], {i + 1, j}});
            }
        }
        // 오른쪽
        if(j < n && !check[i][j + 1] && road[i][j + 1] != -1){
            if(cur.first + road[i][j + 1] <= cost[i][j + 1]){
                cost[i][j + 1] = cur.first + road[i][j + 1];
                pq.push({cost[i][j + 1], {i, j + 1}});
            }
        }
        // 왼쪽
        if(1 < j && !check[i][j - 1] && road[i][j - 1] != -1){
            if(cur.first + road[i][j - 1] <= cost[i][j - 1]){
                cost[i][j - 1] = cur.first + road[i][j - 1];
                pq.push({cost[i][j - 1], {i, j - 1}});
            }
        }
    }
    if(cost[m][n] == INF){
        cout<< -1;
    }else{
        cout<< cost[m][n];
    }
}