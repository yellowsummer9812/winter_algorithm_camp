#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, m, ans;
vector<ll> v;

void search(ll low, ll high){
    ll mid;
    ll tmp;
    while(low <= high){
        mid = (low + high) / 2;
        tmp = 0;
        for(int i = 0; i < n; i++){
            if(v[i] <= mid) continue;
            tmp += v[i] - mid;
        }

        if(tmp < m){
            high = mid - 1;
        }else{
            ans = mid;
            low = mid + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    ll tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    search(0, v[n - 1]);
    cout<< ans;
}