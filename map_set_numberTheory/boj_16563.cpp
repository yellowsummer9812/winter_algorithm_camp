#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
typedef long long ll;
using namespace std;

ll n;
ll num[5000001]; // 0이면 소수, 1이면 소수 아님
ll a[MAX];
vector<ll> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for(ll i = 2; i * i <= 5000000; i++){
        if(num[i] == 0){
            for(ll j = i; i * j <= 5000000; j++){
                    num[i * j] = 1;
            } 
            v.push_back(i); // 소수인 거 v에 담기
        }
    }

    cin>> n;

    ll tmp;

    for(ll i = 1; i <= n; i++){ 
        cin>> tmp;
        for(ll j = 0; (j < v.size()) && (v[j] * v[j] <= tmp); j++){
            while(tmp % v[j] == 0){
                cout<<v[j]<< " ";
                tmp /= v[j];
            }
        }
        if(tmp != 1)
            cout<< tmp;
        cout<< "\n";
    }
}