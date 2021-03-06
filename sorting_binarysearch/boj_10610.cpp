#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n;
ll sum;
ll z;
vector<ll> v;
bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    ll a;
    while(n > 0){
        a = n % 10;
        v.push_back(a);
        if(a == 0){
            z = 1;
        }else{
            sum += a;
        }
        n /= 10;
    }
    if(sum % 3 == 0 && z == 1){
        sort(v.begin(), v.end(), cmp);
        for(ll i = 0; i < v.size(); i++){
            cout<< v[i];
        }
    }else{
        cout<< -1;
    }

}