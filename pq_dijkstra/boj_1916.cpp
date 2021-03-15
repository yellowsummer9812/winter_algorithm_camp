#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
typedef long long ll;
using namespace std;

int n, m;
vector<pair<int, int>> bus[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int dist[1001];
bool visit[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin>> m;

    int s, e, w;
    for(int i = 0; i < m; i++){
        cin>> s>> e>> w;
        bus[s].push_back({e, w});
    }
    cin>> s>> e;

    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(visit[cur.second]) continue;
        visit[cur.second] = true;
        for(auto nxt : bus[cur.second]){
            if(!visit[nxt.first] && (cur.first + nxt.second <= dist[nxt.first])){
                dist[nxt.first] = cur.first + nxt.second;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
    cout<< dist[e];
}