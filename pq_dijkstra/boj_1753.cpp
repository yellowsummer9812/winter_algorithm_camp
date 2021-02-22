#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20001
#define INT_MAXINT_MAX 2147483647
typedef long long ll;
using namespace std;

int V, E, K;
vector<pair<int ,int>> path[MAX]; // <v, w>
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // <현재 거리, 현재 정점>
ll ans[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> V>> E;
    cin>> K;

    for(int i = 0; i < E; i++){
        int u, v, w;

        cin>> u>> v>> w;
        path[u].push_back({v, w});
    }
    fill(ans, ans + V + 1, INT_MAXINT_MAX);
    pq.push({0, K});
    ans[K] = 0;

    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();

        if(ans[cur.second] < cur.first) continue;
        for(int i = 0; i < path[cur.second].size(); i++){
            if(cur.first + path[cur.second][i].second < ans[path[cur.second][i].first]){
                ans[path[cur.second][i].first] = cur.first + path[cur.second][i].second;
                pq.push({ans[path[cur.second][i].first], path[cur.second][i].first});
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(ans[i] == INT_MAXINT_MAX){
            cout<< "INF\n";
        }else{
            cout<< ans[i]<<'\n';
        }
    }
}