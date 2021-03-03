#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    ll c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a*b) / gcd(a, b);
}

int n;
ll bm[51];
ll bj[51];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int a, b;

    for(int i = 1; i <= n; i++){
        cin>> a>> b;
        ll k = gcd(a, b);
        bj[i] = a / k;
        bm[i] = b / k;
    }

   ll c = bj[1], d = bm[1];
   for(ll i = 2; i <= n; i++){
       c = gcd(c, bj[i]);
       d = lcm(d, bm[i]);
   }

   cout<< c<< " "<< d;
}