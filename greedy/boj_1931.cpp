#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, i, result, cur;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>n;
    vector<pair<int, int>> v;
    int b, e;
    for(i = 0; i < n; i++){
        cin>> b>> e;
        v.push_back({e, b});
    }
    sort(v.begin(), v.end());
    cur = 0;
    result++;
    for(i = 1; i < n; i++){
        if(v[i].second < v[cur].first) continue;
        cur = i;
        result++;
    }
    cout<<result;
}