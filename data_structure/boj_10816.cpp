#include <iostream>
#define MAX 10000000
typedef long long ll;
using namespace std;

ll n, m;
ll a[2 * MAX + 1];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    ll tmp;
    for(ll i = 0; i < n; i++){
        cin>> tmp;
        a[tmp + MAX]++;
    }

    cin>> m;
    for(ll i = 0; i < m; i++){
        cin>> tmp;
        cout<< a[tmp + MAX]<< " ";
    }
}