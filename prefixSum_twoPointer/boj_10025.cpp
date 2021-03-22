#include <iostream>
typedef long long ll;
using namespace std;

ll x[1000001];
int n, k;
int m;
ll ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> k;
    int xi,q;
    for(int i = 0; i < n; i++){
        cin>> q>> xi;
        x[xi] += q;
        for(int j = 1; j <= k; j++){
            if(0 <= xi - j){
                x[xi - j] += q;
            }
            if(xi + j <= 1000000){
                x[xi + j] += q;
            }
        }
        if(m < xi){
            m = xi;
        }
    }
    for(int i = 0; i <= m; i++){
        if(ans < x[i]){
            ans = x[i];
        }
    }
    cout<< ans;
}