#include <iostream>
#include <algorithm>
#define INF 1e9
#define MAX 101
using namespace std;

int n, m;
int dist[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin>> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            dist[i][j] = INF;
        }
    }

    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        dist[a][b] = min(dist[a][b], c); // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있기 때문
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF){
                cout<<"0 ";
            }else{
                cout<< dist[i][j]<< " ";
            }
        }
        cout<< '\n';
    }
}
