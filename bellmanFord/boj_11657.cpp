#include <iostream>
#include <vector>
#define INF 1e18
#define MAX_CITY 500 
typedef long long ll;
using namespace std;

vector<pair<int, ll>> city[MAX_CITY + 1];
ll dist[MAX_CITY + 1];
int N, M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> N>> M;
    for(int i = 0; i < M; i++){
        int a, b;
        ll c;
        cin>> a>> b>> c;
        city[a].push_back({b, c});
    }

    for(int i = 2; i <= N; i++){
        dist[i] = INF;
    }

    bool negative_cycle = false;

    for(int i = 1; i <= N; i++){
        for(int from = 1; from <= N; from++){
            if(dist[from] == INF) continue;

            for(int j = 0; j < city[from].size(); j++){
                int to = city[from][j].first;
                int cost = city[from][j].second;

                if(dist[from] + cost < dist[to]){
                    if(i == N) negative_cycle = true;
                    dist[to] = dist[from] + cost;
                }
            }
        }
    }
    if(negative_cycle){
        cout<< "-1\n";
    }else{
        for(int i = 2; i <= N; i++){
            if(dist[i] == INF) 
                cout<< "-1\n";
            else
                cout<< dist[i]<<'\n';
        }
    }
}
