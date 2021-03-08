#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll n, c, ans;
vector<ll> v;

ll search(ll l, ll h){ 
    ll mid;
    ll start;
    ll cnt;
    ll r;
    ll low = 1;
    ll high = h - l; 
    bool isOk;

    while(low <= high){
        start = 0;
        cnt = 1; // 이미 첫번째 집에는 공유기를 설치함
        isOk = false;
        mid = (low + high) / 2;

        for(int i = 1; i < v.size(); i++){
            if(v[i] - v[start] < mid){
                continue;
            }else if(v[i] - v[start] == mid){
                isOk = true;
                cnt++; // 공유기 하나 더 설치
                start = i;
            }else{
                cnt++;
                start = i;                
            }
        }

        if(cnt >= c){
            if(isOk){
                r = mid;                
            }
            low = mid + 1;
        }else if(cnt < c){
            high = mid - 1;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> c;
    ll tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ans = search(v[0], v[v.size() - 1]);
    cout<< ans;
}