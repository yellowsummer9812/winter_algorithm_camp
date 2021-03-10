#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, k, ans;
vector<ll> v;

void search(ll low, ll high){
    ll mid;
    ll f;
    while(low <= high){
        mid = (low + high) / 2;
        f = 0;
        for(int i = 0; i < n; i++){
            f += (v[i] / mid);
        }
        if(f < k){
            high = mid - 1;
        }else{
            ans = mid;
            low = mid + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    cin>> n>> k;
    for(int i = 0; i < n; i++){
        ll tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    search(0, v[n - 1]);
    cout<< ans;
}