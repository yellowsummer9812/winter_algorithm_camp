#include <iostream>
#include <vector>
#define INF 1e9
#define MAX 500
typedef long long ll;
using namespace std;

int tc;
int n, m, w;
ll dest[MAX + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> tc;
    for(int t = 0; t < tc; t++){
        cin>> n>> m>> w;
        vector<pair<int, ll>> adj[MAX + 1];
        for(int i = 1; i <= m; i++){
            int a, b;
            ll c;
            cin>> a>> b>> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        for(int i = 1; i <= w; i++){
            int a, b;
            ll c;
            cin>> a>> b>> c;
            adj[a].push_back({b, (-1) * c});
        }
        dest[1] = 0;
        for(int i = 2; i <= n; i++){
            dest[i] = INF;
        }

        bool negative_cycle = false;

        for(int i = 1; i <= n; i++){
            for(int from = 1; from <= n; from++){
                for(int j = 0; j < adj[from].size(); j++){
                    int to = adj[from][j].first;
                    int cost = adj[from][j].second;
                    if(dest[from] + cost < dest[to]){
                        if(i == n){          
                            negative_cycle = true;
                        }
                        dest[to] = dest[from] + cost;
                    }
                }
            }
        }
        if(negative_cycle){
            cout<< "YES\n";
        }else{
            cout<< "NO\n";
        }
    }
}
