// 정점 번호 1에서 출발하는 벨만포드 코드
#include <iostream>
#include <vector>
#define INF 1e18
typedef long long ll;
using namespace std;

vector<pair<ll, ll>> adj[100]; // 연습이라서 100
ll dist[100]; // 정점 1에서부터 정점 index까지의 최단경로
int main(){
    int V, E;
    cin>> V>> E;
    for(int i = 0; i < E; i++){
        ll a, b, c;
        adj[a].push_back({b, c});
    }

    for(int i = 2; i <= V; i++){ // 정점1 시작이기 때문에 2부터 무한대로 갱신
        dist[i] = INF;
    }

    bool negative_cycle = false; // 음의 사이클 존재 유무를 담는 변수

    for(int i = 1; i <= V; i++){ // 모든 간선에 대해서 V번 체크
        for(int from = 1; from <= V; from++){
            if(dist[from] == INF) continue; // 아직 연결되지 않은 정점이면 스킵

            for(int j = 0; j <= adj[from].size(); j++){
                ll to = adj[from][j].first;
                ll cost = adj[from][j].second;

                if(dist[from] + cost < dist[to]){
                    if(i == V) negative_cycle = true; // V번째에 변화가 발생하면 음의 사이클이 있음
                    dist[to] = dist[from] + cost;
                }
            }

        }
    }
}