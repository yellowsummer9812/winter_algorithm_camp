#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, m, ans;
vector<ll> v;

ll search(ll low, ll high){
    ll mid;
    ll stmp;
    ll bcnt;
    ll r;
    while(low <= high){
        stmp = 0;
        bcnt = 1;
        mid = (low + high) / 2;
        for(int i = 0; i < n; i++){
            if(mid < v[i]){
                bcnt = m + 1;
                break;
            }
            if(stmp + v[i] > mid){
                bcnt++;
                stmp = 0;
            }
            stmp += v[i];
        }
        if(bcnt > m){
            low = mid + 1;
        }else if(bcnt <= m){
            r = mid;
            high = mid - 1;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    ll minimum = 10001;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>> tmp;
        v.push_back(tmp);
        if(tmp < minimum) minimum = tmp;
        sum += tmp; 
    }
    ans = search(minimum, sum);
    cout<< ans;
}