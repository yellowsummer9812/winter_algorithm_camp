#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int dist[100][100]; // 연습이라서 100
int main(){
    int V, E;
    cin>> V>> E;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i == j) dist[i][j] = 0; // 자기 자신까지 거리 0
            dist[i][j] = INF;
        }
    }

    bool negative_cycle = false;

    for(int i = 1; i <= E; i++){
        int a, b, c;
        cin>> a>> b>> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for(int k = 1; k <= V; k++){ // 정점 k를 경유하는 경우
        // 모든 경우에 대해서 검사
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 음의 cycle이 있는지 확인
    for(int i = 1; i <= V; i++){
        if(dist[i][i] != 0){
            negative_cycle = true;
            break;
        }
    }
}