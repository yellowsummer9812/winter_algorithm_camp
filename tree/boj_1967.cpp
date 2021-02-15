#include <iostream>
#include <vector>
using namespace std;

struct TREENODE{
    vector<pair<int, int>> v; // <이웃, 가중치>
};

int n, x, ans;
struct TREENODE tree[10001];

void solve(int w, int cur, int pre){
    if(ans < w){
        ans = w;
        x = cur;
    }
    for(int i = 0; i < tree[cur].v.size(); i++){
        int next = tree[cur].v[i].first;
        int d = tree[cur].v[i].second;
        if(next == pre) continue;
        solve(w + d, next, cur);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n - 1; i++){
        int a, b, c;
        cin>> a>> b>> c;

        tree[a].v.push_back({b, c});
        tree[b].v.push_back({a, c});
    }
    solve(0, 1, -1);
    ans = 0;
    solve(ans, x, -1);

    cout<< ans;
}