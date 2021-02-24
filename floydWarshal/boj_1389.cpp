#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;

int n, m;
int dist[MAX][MAX];
int kbn[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        cin>> a>> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int kbn_min = INF;
    int ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            kbn[i] += dist[i][j];
        }
        if(kbn_min > kbn[i]){
            kbn_min = kbn[i];
            ans = i;
        }
    }
    cout<< ans;
}